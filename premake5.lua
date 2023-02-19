workspace "REngine"
	architecture "x64"
	
	configurations
	{
	"Debug",
	"Release",
	"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "REngine/vendor/GLFW/include"
IncludeDir["Glad"] = "REngine/vendor/Glad/include"
IncludeDir["glm"] = "REngine/vendor/glm/"
IncludeDir["ImGui"] = "REngine/vendor/imgui"
IncludeDir["entt"] = "REngine/vendor/entt/include"
IncludeDir["stb_image"] = "REngine/vendor/stb_image"


group "Dependencies"
	include "REngine/vendor/GLFW"
	include "REngine/vendor/Glad"
	include "REngine/vendor/imgui"

group ""

project "REngine"
	location "REngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "repch.h"
	pchsource "REngine/src/repch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.stb_image}"
	}
	
	links
	{
		
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
	
		defines{
		"RE_PLATFORM_WINDOWS",
		"RE_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
		}
	

	filter "configurations:Debug"
		defines "RE_DEBUG"
		buildoptions "/MDd"
		symbols "on"
	
	filter "configurations:Release"
		defines "RE_RELEASE"
		buildoptions "/MD"
		optimize "on"
		
	filter "configurations:Dist"
		defines "RE_DIST"
		buildoptions "/MD"
		optimize "on"
		
	
project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	
	
	includedirs
	{
		"REngine/vendor/spdlog/include",
		"REngine/src",
		"REngine/vendor",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.stb_image}"
	}
	
	links
	{
		"REngine"
	}

	filter "system:windows"
		systemversion "latest"
	
		defines
		{
		"RE_PLATFORM_WINDOWS"
		}
	
	


	filter "configurations:Debug"
		defines "RE_DEBUG"
		buildoptions "/MDd"
		symbols "on"
	
	filter "configurations:Release"
		defines "RE_RELEASE"
		buildoptions "/MD"
		optimize "on"
		
	filter "configurations:Dist"
		defines "RE_DIST"
		buildoptions "/MD"
		optimize "on"
		