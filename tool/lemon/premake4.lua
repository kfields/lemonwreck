project "Lemon"
    includedirs {
        ".", 
    }
    files {
        "lemon.c"
    }
	targetname "lemon"
    targetdir "../../bin"
	
    configuration { "Debug" }
        kind    "ConsoleApp"
	  
	configuration { "Release" }
        kind    "ConsoleApp"

project "LemonCpp"
    includedirs {
        ".", 
    }
    files {
        "lemoncpp.c"
    }
	targetname "lemoncpp"
    targetdir "../../bin"
	
    configuration { "Debug" }
        kind    "ConsoleApp"
	  
	configuration { "Release" }
        kind    "ConsoleApp"
		