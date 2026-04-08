#!/usr/bin/env python
import os
import sys

def print_error(*values):
    print("ERROR:", *values, file=sys.stderr)

libname = "cardgame"

local_env = Environment(tools=["default"], PLATFORM="")
customs = []
opts = Variables(customs, ARGUMENTS)
opts.Update(local_env)
Help(opts.GenerateHelpText(local_env))

env = local_env.Clone()

if not (os.path.isdir("godot-cpp") and os.listdir("godot-cpp")):
    print_error("godot-cpp is not available in this folder.")
    print_error("Run: git submodule update --init --recursive")
    sys.exit(1)

env = SConscript("godot-cpp/SConstruct", {"env": env, "customs": customs})

env.Append(CPPPATH=["src/", "include/"])

sources = Glob("src/*.cpp")

suffix = env["suffix"].replace(".dev", "").replace(".universal", "")
lib_filename = "{}{}{}{}".format(
    env.subst("$SHLIBPREFIX"),
    libname,
    suffix,
    env.subst("$SHLIBSUFFIX"),
)

library = env.SharedLibrary(
    "bin/{}/{}".format(env["platform"], lib_filename),
    source=sources,
)

Default(library)
