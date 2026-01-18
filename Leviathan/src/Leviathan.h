#pragma once

//to be used by applications
#include "Leviathan/Core/Application.cpp"
#include "Leviathan/Core/Layer.h"
#include "Leviathan/Core/Log.h"
#include "Leviathan/Core/Core.h"

//Input
#include "Leviathan/Core/Input/Input.h"
#include "Leviathan/Core/Input/KeyCodes.h"
#include "Leviathan/Core/Input/MouseCodes.h"

//Layers
#include "Leviathan/ImGui/ImGuiLayer.h"

//Scene
#include "Leviathan/Scene/Scene.h"
#include "Leviathan/Scene/Entity.h"
#include "Leviathan/Scene/Component.h"

#include "Leviathan/Renderer/Material.h"
#include "Leviathan/Renderer/Texture.h"


//Math
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

// EntryPoint -----------------------
#include "Leviathan/Core/EntryPoint.h"