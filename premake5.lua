workspace "Hobot"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include dirs relative to the root folder (solution dir)
includeDirs = {}
includeDirs["glfw"] = "Hobot/vendor/glfw-3.4/include"

include "Hobot/vendor/glfw-3.4" --Include another premake5 file, specific to glfw project

project "Hobot"
  location "Hobot"
  kind "SharedLib"
  language "C++"
  cppdialect "C++latest"

  targetdir("bin/" .. outputDir .. "/%{prj.name}")
  objdir("bin-int/" .. outputDir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
  }

  pchheader "htpch.h"
  pchsource "Hobot/src/htpch.cpp"

  includedirs
  {
    "Hobot/src",
    "%{includeDirs.glfw}"
  }

  links
  {
    "glfw",
    "OpenGL32"
  }
  
  filter "system:windows"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "_HOBOT_PLATFORM_WINDOWS_",
      "_HOBOT_BUILD_DLL_"
    }

  filter "configurations:Debug"
    defines "_HOBOT_DEBUG_"
    optimize "On"

  filter "configurations:Release"
    defines "_HOBOT_RELEASE_"
    optimize "On"

  filter "configurations:Dist"
    defines "_HOBOT_DIST_"
    optimize "On"

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++latest"

  targetdir("bin/" .. outputDir .. "/%{prj.name}")
  objdir("bin-int/" .. outputDir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp",
    "%{prj.name}/src/**.ixx"
  }

  includedirs
  {
    "Hobot/src"
  }
  
  links
  {
    "Hobot"
  }

  filter "system:windows"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "_HOBOT_PLATFORM_WINDOWS_"
    }

    prebuildcommands
    {
      ("mkdir -p ../bin/" .. outputDir .. "/Sandbox/"),
      ("cp ../bin/" .. outputDir .. "/Hobot/Hobot.dll ../bin/" .. outputDir .. "/Sandbox/")
    }

  filter "configurations:Debug"
    defines "_HOBOT_DEBUG_"
    optimize "On"

  filter "configurations:Release"
    defines "_HOBOT_RELEASE_"
    optimize "On"

  filter "configurations:Dist"
    defines "_HOBOT_DIST_"
    optimize "On"