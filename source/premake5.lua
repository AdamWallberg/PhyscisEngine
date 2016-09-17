require 'settings'

LIBRARY_FOLDER = "$(SolutionDir)../libraries/"

--premake5.lua
 
solution (SOLUTION_NAME)
	configurations { "Debug", "Release" }
	
	platforms {
		"Win32",
		"Win64"
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
		
	configuration { "Release" }
		defines { "RELEASE", "NDEBUG" }
		optimize "On"
	
-- The framework. Used for testing engine features, and making games. 
project (FRAMEWORK_NAME)
	kind "ConsoleApp"
	language "C++"
	
	objdir ("$(SolutionDir)../build/")
	
	files { "**.h", "**.cpp", "**.hpp" }
	
	includedirs {
		LIBRARY_FOLDER .. "glew-1.13.0/include",
		"./code/"
	}
	
	links {
		"glew32",
		"glfw3",
		"opengl32"
	}
	
	configuration { "Win32" }
		targetdir "$(SolutionDir)../game/bin32/"
		includedirs{
			LIBRARY_FOLDER .. "glfw32/include"
		}
		libdirs{
			LIBRARY_FOLDER .. "glew-1.13.0/lib/Release/Win32",
			LIBRARY_FOLDER .. "glfw32/lib-vc2013"
		}
	
	configuration { "Win64" }
		targetdir "$(SolutionDir)../game/bin64/"
		includedirs{
			LIBRARY_FOLDER .. "glfw/include"
		}
		libdirs{
			LIBRARY_FOLDER .. "glew-1.13.0/lib/Release/x64",
			LIBRARY_FOLDER .. "glfw/lib-vc2013"
		}