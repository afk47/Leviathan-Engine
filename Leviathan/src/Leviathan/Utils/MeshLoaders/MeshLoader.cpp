#include "lpch.h"
#include "MeshLoader.h"
#include "OBJ-Loader.h"


namespace Leviathan {

	MeshComponent MeshLoader::LoadMeshes(const std::string& path)
	{
		//std::vector<MeshComponent> meshes = std::vector<MeshComponent>();
		//meshes.push_back(LoadOBJ(path));
		MeshComponent comp = LoadOBJ(path);
		
		return comp;
	}

	
	MeshComponent MeshLoader::LoadOBJ(const std::string& path)
	{
		objl::Loader loader = objl::Loader();
		
		loader.LoadFile(path);

	
		return loader.GetMeshComponent(0);

	}


}