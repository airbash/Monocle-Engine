
-- Monocle Library
project "MonocleCore"
	kind "StaticLib"
	language "C++"
	
	monocle_os_defines();
	
	basedir	( _BUILD_BASE.."/MonocleCore" )
	
	files { "monocle/**.h", "monocle/**.cpp", "monocle/**.c" }

	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" } 