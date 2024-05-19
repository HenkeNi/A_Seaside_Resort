workspace "A_Seaside_Resort"
	configurations { "Debug", "Release" }
	architecture "x64"
	startproject "Game"
	language "C++"
	cppdialect "C++20"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	

	--flags
	--{
	--	"MultiProcessorCompile"
	--}

	
project "Game"
	location "Game"
	kind "ConsoleApp"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Pch.h"
	pchsource "Game/Source/Precompiled/Pch.cpp"

	files { "%{prj.name}/Source/**.h", "%{prj.name}/Source/**.hpp", "%{prj.name}/Source/**.cpp" }

	includedirs
	{
		"Libraries/SDL2/include",
		"%{prj.namme}/Source/",
		"%{prj.namme}/Source/Precompiled/"
	}

	links
	{
		"SDL2",
		"SDL2main"
	}

	libdirs
	{
		"Libraries/SDL2/lib/"
	}

		postbuildcommands
	{
		"{COPY} ../Libraries/SDL2/lib/SDL2.dll %{cfg.targetdir}"
	}

	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "Release"
		optimize "on"