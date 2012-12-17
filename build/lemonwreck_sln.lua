-- Avoid error when invoking premake4 --help.
if (_ACTION == nil) then
   return
end

solution "LemonWreck"
    language "C++"
    location ( _OPTIONS["to"] or "project/" .. _ACTION )
    configurations { "Debug", "Release" }
    
    includedirs {
      "../include",
      "../src",
    }
	
    targetdir "../bin"
	debugdir "../bin"
	objdir "obj"
	
    configuration { "Debug"}
        defines { "_DEBUG" }
        flags   { "Symbols" }
      
    configuration { "Release" }
        flags   { "OptimizeSpeed" }
    
    configuration { "vs*" }
        defines { "_CRT_SECURE_NO_WARNINGS", "_CRT_SECURE_NO_DEPRECATE" }

	configuration { "codeblocks" }
		--buildoptions { "-std=c++11" }
		--buildoptions { "-std=gnu++0x" }
		
	configuration { "gmake" }
		--buildoptions { "-std=c++11" }
		--buildoptions { "-std=gnu++0x" }

    include "../src/lwcalc"        
