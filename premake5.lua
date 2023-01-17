workspace "REngine"
	architecture "x64"
	
	configurations
	{
	"Debug",
	"Release",
	"Dist"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "REngine"
	location "REngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines{
		"RE_PLATFORM_WINDOWS",
		"RE_BUILD_DLL"
		}
	
	postbuildcommands
	{

		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")

	}


	filter "configurations:Debug"
		defines "RE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "RE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "RE_DIST"
		optimize "On"
		
	
project "SandBox"
	location "SandBox"
	kind "ConsoleApp"

	language "C++"
	
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
		"REngine/src"
	}
	
	links
	{
		"REngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
		"RE_PLATFORM_WINDOWS"
		}
	
	


	filter "configurations:Debug"
		defines "RE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "RE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "RE_DIST"
		optimize "On"
		