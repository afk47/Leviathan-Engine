#pragma once

//to be used by applications
#include "REngine/Core/Application.cpp"
#include "REngine/Core/Layer.h"
#include "REngine/Core/Log.h"

//Input
#include "REngine/Core/Input/Input.h"
#include "REngine/Core/Input/KeyCodes.h"
#include "REngine/Core/Input/MouseCodes.h"

//Layers
#include "REngine/ImGui/ImGuiLayer.h"

#define GLM_FORCE_CTOR_INIT

// EntryPoint -----------------------
#include "REngine/Core/EntryPoint.h"