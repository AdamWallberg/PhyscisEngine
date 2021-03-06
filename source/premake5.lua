require "settings"
require "modules/physcismath"

LIBRARY_FOLDER = "$(SolutionDir)../dependencies/"
EXTERNAL_LIB_FOLDER = "$(SolutionDir)../../../Libraries/"

FBX_ENABLED = false
FBX_PATH = EXTERNAL_LIB_FOLDER .. "FBX SDK/2017.0.1/"

--premake5.lua
 
solution (SOLUTION_NAME)
	configurations { "Debug", "Release" }
	
	platforms {
		"Win32", "Win64"
	}
	
	filter { "platforms:Win32" }
		system "Windows"
		architecture "x32"
		
	filter { "platforms:Win64" }
		system "Windows"
		architecture "x64"
		
	configuration { "Debug" }
		defines { "DEBUG" }
		flags { "Symbols" }
		linkoptions{ "/NODEFAULTLIB:msvcrt.lib" }
		
	configuration { "Release" }
		defines { "RELEASE", "NDEBUG" }
		optimize "On"
	
-- The framework. Used for testing engine features, and making games. 
project (FRAMEWORK_NAME)
	kind "ConsoleApp"
	language "C++"
	
	objdir ("$(SolutionDir)../build/")
	
	files { "**.h", "**.cpp", "**.hpp" }
	
	-- Enable libraries
	pm_enable()
	
	targetdir "$(SolutionDir)../game/"
	debugdir "$(SolutionDir)../game/"
	targetname(FRAMEWORK_NAME .. " - $(Configuration)")
	
	includedirs {
		LIBRARY_FOLDER .. "glew-1.13.0/include/",
		LIBRARY_FOLDER .. "python/include/",
		--FBX_PATH .. "include/",
		"./code/",
		"./code/Engine/"
	}
	
	libdirs { 
		LIBRARY_FOLDER .. "python/libs/"
	}
	
	links {
		"glew32",
		"glfw3",
		"opengl32",
		"_tkinter",
		"python3",
		"python35"
		--"libfbxsdk-md"
	}
	
	configuration { "Debug" }
		libdirs {
			--FBX_PATH .. "lib/vs2015/x86/debug/"
		}
		
	configuration { "Release" }
		libdirs{
			--FBX_PATH .. "lib/vs2015/x86/release/"
		}
	
	configuration { "Win32" }
		
		includedirs{
			LIBRARY_FOLDER .. "glfw32/include/"
		}
		libdirs{
			LIBRARY_FOLDER .. "glew-1.13.0/lib/Release/Win32/",
			LIBRARY_FOLDER .. "glfw32/lib-vc2015/"
		}
		
	configuration { "Win64" }
		
		includedirs{
			LIBRARY_FOLDER .. "glfw64/include/"
		}
		libdirs{
			LIBRARY_FOLDER .. "glew-1.13.0/lib/Release/x64/",
			LIBRARY_FOLDER .. "glfw64/lib-vc2015/"
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		