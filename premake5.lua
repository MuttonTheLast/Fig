include "premake5-manager.lua"

workspace "Fig"  
    configurations { "Debug", "Release" } 
    architecture "x86_64"
    location "./"
    -- Include build.lua files in your project
    local buildScripts = NZA_findBuildScripts(".")
    for _, script in ipairs(buildScripts) do
        --group(string.gsub(string.match(script, "/.*"), "build.lua", ""))
        local projectLocation = string.gsub(script, "build.lua", "")
        group(NZA_RemoveLastFolder(projectLocation))
        NZA_include(script)
        prj_loc = projectLocation
        NZA_newProject()
        group("")
    end
