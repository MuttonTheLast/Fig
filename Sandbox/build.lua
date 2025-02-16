prj_name = "Sandbox"

prj_libs = {
    "%{cfg.buildcfg}/sdl3.lib"

}

prj_includes = { "%{wks.location}/Engine/Fig/src", "%{wks.location}/Engine/Fig/include" } -- these are implumented { "%{prj.location}/include", "%{wks.location}/include" } 
prj_links = { "Fig" }
