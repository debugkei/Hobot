workspace "Hobot"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release"
  }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Hobot/vendors/glfw-3.4" --Include another premake5 file, specific to glfw project

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
    "%{prj.name}/src/**.cpp"
  }
  

  pchheader "htpch.h"
  pchsource "Hobot/src/htpch.cpp"

  includedirs
  {
    "Hobot/src",
    "Hobot/vendors/glfw-3.4/include"
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
      "_HOBOT_PLATFORM_WINDOWS",
      "_HOBOT_BUILD_DLL"
    }

    files
    {
      "%{prj.name}/src/%{prj.name}/Platform/Windows/*.cpp",
      "%{prj.name}/src/%{prj.name}/Platform/Windows/*.h"
    }
    
    links
    {
      "Gdi32"
    }
  
  filter "system:linux"
    defines
    {
      "_HOBOT_PLATFORM_LINUX"
    }

  filter "configurations:Debug"
    defines
    {
      "_HOBOT_DEBUG",
      "_HOBOT_ENABLE_ASSERT"
    }
    symbols "On"
    runtime "Debug"

  filter "configurations:Release"
    defines "_HOBOT_RELEASE"
    optimize "On"
    runtime "Release"


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
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "Hobot/src"
  }
  
  links
  {
    "Hobot"
  }

  prebuildcommands
  {
    ("mkdir -p ../bin/" .. outputDir .. "/Sandbox/"),
    ("cp ../bin/" .. outputDir .. "/Hobot/Hobot.dll ../bin/" .. outputDir .. "/Sandbox/")
  }

  filter "system:windows"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "_HOBOT_PLATFORM_WINDOWS"
    }


  filter "configurations:Debug"
    defines
    {
      "_HOBOT_DEBUG",
      "_HOBOT_ENABLE_ASSERT"
    }
    symbols "On"
    runtime "Debug"

  filter "configurations:Release"
    defines "_HOBOT_RELEASE_"
    optimize "On"
    runtime "Release"