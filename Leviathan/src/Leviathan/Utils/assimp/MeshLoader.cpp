#include "lpch.h"
#include "MeshLoader.h"



namespace Leviathan {

	std::vector<MeshComponent> MeshLoader::LoadMeshes(const std::string& path)
	{
		Assimp::Importer importer;
		
		const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_SortByPType | aiProcess_ValidateDataStructure);

		if (importer.GetErrorString() == "") {
			LE_CORE_ERROR(importer.GetErrorString());
		}
		
		ProcessNode(scene->mRootNode, scene);

		return meshes;
	}

	void MeshLoader::ProcessNode(aiNode* node, const aiScene* scene)
	{
		// process all the node's meshes (if any)
		for (unsigned int i = 0; i < node->mNumMeshes; i++)
		{
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			meshes.push_back(ProcessMesh(mesh, scene));
		}
		// then do the same for each of its children
		for (unsigned int i = 0; i < node->mNumChildren; i++)
		{
			ProcessNode(node->mChildren[i], scene);
		}
	}


	MeshComponent MeshLoader::ProcessMesh(aiMesh* mesh, const aiScene* scene)
	{
		std::vector<float> vertices;
		std::vector<uint32_t> indices;

		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			vertices.push_back(mesh->mVertices[i].x);
			vertices.push_back(mesh->mVertices[i].y);
			vertices.push_back(mesh->mVertices[i].z);
		}
		// process indices - assumes all faces are tris (to ensure use aiProcess_Triangulate flag)
		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			const aiFace& face = mesh->mFaces[i];

			indices.push_back(face.mIndices[0]);
			indices.push_back(face.mIndices[1]);
			indices.push_back(face.mIndices[2]);
		}
		// TODO process material
		if (mesh->mMaterialIndex >= 0)
		{
			
		}

		MeshComponent comp = MeshComponent();

		//Vertex Buffer Creation
		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices.data(), sizeof(vertices.data())));
		BufferLayout layout = {
			{ ShaderDataType::Vec3, "a_Position" }
		};
		vertexBuffer->SetLayout(layout);
		comp.mesh->AddVertexBuffer(vertexBuffer);

		//Index Buffer Creation
		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::Create(indices.data(), (uint32_t)indices.size())); 
		comp.mesh->SetIndexBuffer(indexBuffer);
		comp.material->Bind();

		//__debugbreak(); //Essentially a breakpoint
		return comp;
	}

	 glm::mat4 MeshLoader::toGLMMat4(aiMatrix4x4 m2) {
		//Convert assimp mat4 to glm::mat4
		glm::mat4 m1 = glm::mat4();
		m1[0][0] = (float)m2.a1; m1[0][1] = (float)m2.a1;	m1[0][2] = (float)m2.a1; m1[0][3] = (float)m2.a1;
		m1[1][0] = (float)m2.a1; m1[1][1] = (float)m2.a1;	m1[1][2] = (float)m2.a1; m1[1][3] = (float)m2.a1;
		m1[2][0] = (float)m2.a1; m1[2][1] = (float)m2.a1;	m1[2][2] = (float)m2.a1; m1[2][3] = (float)m2.a1;
		m1[3][0] = (float)m2.a1; m1[3][1] = (float)m2.a1;	m1[3][2] = (float)m2.a1; m1[3][3] = (float)m2.a1;
		return m1;
	}


	
}