#pragma once

//to be used by applications
#include "REngine/Core/Application.cpp"
#include "REngine/Core/Layer.h"
#include "REngine/Core/Log.h"
#include "REngine/Core/Core.h"

//Input
#include "REngine/Core/Input/Input.h"
#include "REngine/Core/Input/KeyCodes.h"
#include "REngine/Core/Input/MouseCodes.h"

//Layers
#include "REngine/ImGui/ImGuiLayer.h"

//Scene
#include "REngine/Scene/Scene.h"
#include "REngine/Scene/Entity.h"
#include "REngine/Scene/Component.h"

#include "REngine/Renderer/Material.h"
#include "REngine/Renderer/Texture.h"


//Math
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

// EntryPoint -----------------------
#include "REngine/Core/EntryPoint.h"