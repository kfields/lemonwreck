project "LwCalc"
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
	
	targetname "lwcalc"
	
    configuration { "Debug" }
        kind    "ConsoleApp"
	  
	configuration { "Release" }
        kind    "ConsoleApp"