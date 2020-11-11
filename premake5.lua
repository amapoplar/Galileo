workspace "Galileo"

    architecture "x64"
    configurations { 
        "Debug", 
        "Release",
        "Dist" 
    }
    
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


    --Include directories relative to root folder

    includeDirs = {}
    includeDirs["GLFW"]="Galileo/vendor/GLFW/include"
    includeDirs["GLAD"]="Galileo/vendor/Glad/include"
    includeDirs["ImGui"]="Galileo/vendor/imgui"

    include "Galileo/vendor/GLFW"
    include "Galileo/vendor/Glad"
    include "Galileo/vendor/imgui"

    project "Galileo"

        location "Galileo"
        kind "SharedLib"
        language "C++"

        targetdir("bin/"..outputdir.."/%{prj.name}")
        objdir("bin-int/"..outputdir.."/%{prj.name}")
        pchheader "glpch.h"
        pchsource "Galileo/src/glpch.cpp"

    
        files{
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
        }

        includedirs{
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include",
            "%{includeDirs.GLFW}",
            "%{includeDirs.GLAD}",
            "%{includeDirs.ImGui}"
        }

        links{
            "GLFW",
            "Glad",
            "ImGui",
            "opengl32.lib"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines{
                "GL_PLATFORM_WINDOWS",
                "GL_BUILD_DLL",
                "GLFW_INCLUDE_NONE"
            }

        	postbuildcommands{
                
                ("{COPY} %{cfg.buildtarget.relpath} \"../bin/"..outputdir.."/SandBox/\"")
            }

        filter "configurations:Debug"
            defines "GL_DEBUG"
            buildoptions "/MDd"
            symbols "On"

        filter "configurations:Release"
            defines "GL_RELEASE"
            buildoptions "/MD"
            optimize "On"

        filter "configurations:Dist"
            defines "GL_DIST"
            buildoptions "/MD"
            optimize "On"


    project "SandBox"
        location "SandBox"
        kind "ConsoleApp"
        language "C++"
        targetdir("bin/"..outputdir.."/%{prj.name}")
        objdir("bin-int/"..outputdir.."/%{prj.name}")

        files{
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
        }
    
        includedirs{
            "%{wks.name}/vendor/spdlog/include",
            "Galileo/src"
        }

        links{
            "Galileo"
        }
    
        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"
    
            defines{
                "GL_PLATFORM_WINDOWS"
            }
    
        filter "configurations:Debug"
            defines "GL_DEBUG"
            buildoptions "/MDd"
            symbols "On"
    
        filter "configurations:Release"
            defines "GL_RELEASE"
            buildoptions "/MD"
            optimize "On"
    
        filter "configurations:Dist"
            defines "GL_DIST"
            buildoptions "/MD"
            optimize "On"