#!/bin/bash

pushd ..
Walnut/vendor/bin/premake/Linux/Build-Server.lua --cc=clang --file=Build-Headless.lua gmake2
popd