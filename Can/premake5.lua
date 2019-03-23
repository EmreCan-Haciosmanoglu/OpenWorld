workspace "Can"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		symbols "On"
		
	filter "configurations:Release"
		defines "CAN_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "CAN_DIST"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CAN_BUILD_DLL",
			"CAN_PLATFORM_WINDOWS",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
		
	filter "configurations:Debug"
		defines "CAN_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "CAN_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "CAN_DIST"
		optimize "On"
