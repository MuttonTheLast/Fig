prj_name = "Fig"
prj_kindof = "SharedLib"
prj_libs = {
    "%{cfg.buildcfg}/sdl3"

}

prj_postbuild = {
    "{COPY} %{wks.location}/build/bin/%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}/*"..SharedLibExt.." %{wks.location}/build/bin/%{cfg.architecture}/%{cfg.buildcfg}/Sandbox/"
}

prj_includes = {
    "%{prj.location}/src/Fig/",
}

prj_pch = "figpch.h"
prj_pchs = "%{prj.location}/src/Fig/figpch.cpp"

prj_configs = {
    ["DEBUG"] = {
        ["defines"] = {"DEBUG_TOOLS=3"},
    }
}


--[[
prj_name = nil -- "ProjectName" !important
prj_loc = nil -- "Better/Not/Change/"
prj_configs = nil -- (better use premake things by hand just implumented defines) 
usage (these are implumented by default) : { 
    ["Release"] = {
        ["defines"] = {"NDEBUG", "Release"},
    }
    ["Debug"] = 
    {
        ["defines"] = {"DEBUG", "_DEBUG"},
    }
}
prj_files = nil 
-- these are implumented {
    "%{prj.location}/**.hpp", "%{prj.location}/**.h" ,
    "%{prj.location}/**.c" , "%{prj.location}/**.cpp",
    "%{prj.location}/**.lua", "%{prj.location}/**.txt", "%{prj.location}/**.ini", "%{prj.location}/**.md", 
} 
prj_kindof = "ConsoleApp"
prj_includes = nil -- these are implumented { "%{prj.location}/include", "%{wks.location}/include" } 
prj_links = nil -- {"project1", "project2Name", "project3Chilly"}
prj_libfolder = nil -- better not cchange default is "%{wks.location}/lib/"
prj_libs = nil -- {"something.lib", "something2.lib", "something3.lib"}
prj_full_libs = nil -- same as up but with exact location for example "build/bin/x86_64/Debug/TestProject3.lib"

]]