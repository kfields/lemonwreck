project "LwAstCalc"
    includedirs {
        ".", 
    }
    files {
        "*.c",
        "*.h",
		"*.re",
		"*.y"
    }
	excludes {
		"lempar.c"
	}
	
	targetname "lwastcalc"
	
    configuration { "Debug" }
        kind    "ConsoleApp"
	  
	configuration { "Release" }
        kind    "ConsoleApp"