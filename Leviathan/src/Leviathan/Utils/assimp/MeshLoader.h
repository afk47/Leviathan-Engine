#pragma once
#include "Leviathan/Core/Log.h"
#include "Leviathan/Scene/Component.h"
#include <glm/glm.hpp>

#include <vector>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags


#define LE_DEBUG_MESHLOADER
namespace Leviathan {


	class MeshLoader {
	public:
		std::vector<MeshComponent> MeshLoader::LoadMeshes(const std::string& path);

		static glm::mat4 toGLMMat4(aiMatrix4x4 m2);

	private:
		void ProcessNode(aiNode* node, const aiScene* scene);
		MeshComponent ProcessMesh(aiMesh* mesh, const aiScene* scene);
	private:
		std::vector<MeshComponent> meshes = std::vector<MeshComponent>();
	};

	
}