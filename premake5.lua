workspace "Leviathan"
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
IncludeDir["GLFW"] = "Leviathan/vendor/GLFW/include"
IncludeDir["Glad"] = "Leviathan/vendor/Glad/include"
IncludeDir["glm"] = "Leviathan/vendor/glm/"
IncludeDir["ImGui"] = "Leviathan/vendor/imgui"
IncludeDir["entt"] = "Leviathan/vendor/entt/include"
IncludeDir["stb_image"] = "Leviathan/vendor/stb_image"
IncludeDir["JSON"] = "Leviathan/vendor/JSON"


group "Dependencies"
	include "Leviathan/vendor/GLFW"
	include "Leviathan/vendor/Glad"
	include "Leviathan/vendor/imgui"

group ""

project "Leviathan"
	location "Leviathan"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "lpch.h"
	pchsource "Leviathan/src/lpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/JSON/**.hpp",
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
		"%{IncludeDir.JSON}",
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
		"Leviathan/vendor/spdlog/include",
		"Leviathan/src",
		"Leviathan/vendor",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"Leviathan"
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
		