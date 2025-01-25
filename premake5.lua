workspace "Hobot"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hobot"
  location "Hobot"
  kind "SharedLib"
  language "C++"

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
  
  filter "system:windows"
    cppdialect "C++20"
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

  filter "system:windows"
    cppdialect "C++20"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "_HOBOT_PLATFORM_WINDOWS_"
    }

    prebuildcommands
    {
      ("{COPY} ../bin/" .. outputDir .. "/Hobot/Hobot.dll ../bin/" .. outputDir .. "/Sandbox/")
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