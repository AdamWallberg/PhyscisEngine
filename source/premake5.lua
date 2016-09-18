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
	
	targetdir "$(SolutionDir)../game/"
	debugdir "$(SolutionDir)../game/"
	
	includedirs {
		LIBRARY_FOLDER .. "glew-1.13.0/include/",
		LIBRARY_FOLDER .. "python/include/",
		"./code/"
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
	}
	
	configuration { "Win32" }
		
		includedirs{
			LIBRARY_FOLDER .. "glfw32/include/"
		}
		libdirs{
			LIBRARY_FOLDER .. "glew-1.13.0/lib/Release/Win32/",
			LIBRARY_FOLDER .. "glfw32/lib-vc2013/"
		}
	
	configuration { "Win64" }
		includedirs{
			LIBRARY_FOLDER .. "glfw/include/"
		}
		libdirs{
			LIBRARY_FOLDER .. "glew-1.13.0/lib/Release/x64/",
			LIBRARY_FOLDER .. "glfw/lib-vc2013/"
		}