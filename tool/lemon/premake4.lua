project "Lemon"
    includedirs {
        ".", 
    }
    files {
        "lemon.c"
    }
	targetname "lemon"
    targetdir "../../bin"
    --links { "BwCore", "BwAi", "BwAxl" }
    --libdirs {"C:/AAA/DevDepends/boost_1_51/lib"}
    configuration { "Debug" }
        kind    "ConsoleApp"
	  
	configuration { "Release" }
        kind    "ConsoleApp"
