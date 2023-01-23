project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

	includedirs
	{
		"include"
	}
    
    filter "system:windows"
        systemversion "latest"
       
    filter "configurations:Debug"
        defines "RE_DEBUG"
        buildoptions "/MDd"
        symbols "on"
        
    filter "configurations:Release"
        defines "RE_RELEASE"
        buildoptions "/MD"
        optimize "on"
        