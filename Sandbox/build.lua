prj_name = "Sandbox"

prj_libs = {
    "%{cfg.buildcfg}/sdl3"

}

prj_includes = { "%{wks.location}/Engine/Fig/src/Fig",  "%{wks.location}/Engine/Fig/src", "%{wks.location}/Engine/Fig/include" } -- these are implumented { "%{prj.location}/include", "%{wks.location}/include" } 
prj_links = { "Fig" }

prj_configs = {
    ["DEBUG"] = {
        ["defines"] = {"DEBUG_TOOLS=3"},
    }
}