#pragma once
#include "Entity.h"
namespace REngine {
	
	class Object3D : Entity {

		Object3D() { new Object3D(entt::entity()) }
	};
}