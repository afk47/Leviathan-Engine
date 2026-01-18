#pragma once
#include "Leviathan/Core/Log.h"
#include "Leviathan/Scene/Component.h"
#include <glm/glm.hpp>

#include <vector>

/*
	Main MeshLoader - Will dispatch to different loaders depending on file type


*/

namespace Leviathan {


	class MeshLoader {
	public:
		MeshComponent MeshLoader::LoadMeshes(const std::string& path);

	private:
		MeshComponent MeshLoader::LoadOBJ(const std::string& path);
	
	};


	
}