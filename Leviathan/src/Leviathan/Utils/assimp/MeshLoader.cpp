#include "lpch.h"
#include "MeshLoader.h"



namespace Leviathan {

	std::vector<MeshComponent> MeshLoader::LoadMeshes(const std::string& path)
	{
	
		Assimp::Importer importer;
		
		const aiScene* scene = importer.ReadFile(path, aiProcessPreset_TargetRealtime_MaxQuality);

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
		MeshComponent meshcomp = MeshComponent();
		std::vector<float> vertices;
		std::vector<unsigned int> indices;

		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			vertices.push_back(mesh->mVertices[i].x);
			vertices.push_back(mesh->mVertices[i].y);
			vertices.push_back(mesh->mVertices[i].z);
		}
		// process indices - assumes all faces are tris (to ensure use aiProcess_Triangulate flag)
		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			
			indices.push_back(mesh->mFaces->mIndices[0]);
			indices.push_back(mesh->mFaces->mIndices[1]);
			indices.push_back(mesh->mFaces->mIndices[2]);
		}
		// TODO process material
		if (mesh->mMaterialIndex >= 0)
		{
			
		}

		BufferLayout layout = BufferLayout(
			{
				{ ShaderDataType::Vec3, "a_Position" },
			});
		Ref<VertexBuffer> buffer;
		buffer.reset(VertexBuffer::Create(vertices.data(), sizeof(vertices.data())));
		meshcomp.mesh->AddVertexBuffer(buffer);
		buffer->SetLayout(layout);
		Ref<IndexBuffer> iBuffer;
		iBuffer.reset(IndexBuffer::Create(indices.data(), sizeof(indices.data())));
		meshcomp.mesh->SetIndexBuffer(iBuffer);
		
		return meshcomp;
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