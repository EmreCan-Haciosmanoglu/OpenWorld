workspace "Can"
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
IncludeDir["GLFW"] = "Can/vendor/GLFW/include"
IncludeDir["Glad"] = "Can/vendor/Glad/include"
IncludeDir["imgui"] = "Can/vendor/imgui"

include "Can/vendor/GLFW"
include "Can/vendor/Glad"
include "Can/vendor/imgui"

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
		"Can/vendor/spdlog/include",
		"Can/src"
	}

	links
	{
		"Can"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CAN_PLATFORM_WINDOWS",
			"_WINDLL"
		}
		
	filter "configurations:Debug"
		defines "CAN_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		
	filter "configurations:Release"
		defines "CAN_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		defines "CAN_DIST"
		buildoptions "/MD"
		optimize "On"

project "Can"
	location "Can"
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
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CAN_PLATFORM_WINDOWS",
			"CAN_BUILD_DLL",
			"_WINDLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
		
	filter "configurations:Debug"
		defines 
		{
			"CAN_DEBUG",
			"CAN_ENABLED_ASSERTS"
		}
		buildoptions "/MDd"
		symbols "On"
		
	filter "configurations:Release"
		defines "CAN_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		defines "CAN_DIST"
		buildoptions "/MD"
		optimize "On"
