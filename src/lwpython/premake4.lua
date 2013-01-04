project "LwPython"
    includedirs {
        ".", 
    }
    files {
        "*.cpp",
        "*.h",
		"*.re",
		"*.y"
    }
	excludes {
		"lempar.cpp"
	}
	
	targetname "lwpython"
	
    configuration { "Debug" }
        kind    "ConsoleApp"
	  
	configuration { "Release" }
        kind    "ConsoleApp"