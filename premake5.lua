workspace "OneGameEngine"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "OneGameEngine"
	location "OneGameEngine"
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
			"OGE_PLATFORM_WINDOWS",
			"OGE_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OGE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "OGE_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "OGE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
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
		"OneGameEngine/vendor/spdlog/include",
		"OneGameEngine/src"
	}

	links 
	{
		"OneGameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"OGE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "OGE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "OGE_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "OGE_DIST"
		optimize "On"
	