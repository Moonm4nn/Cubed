#!/bin/bash

pushd ..
Walnut/vendor/bin/premake/Linux/premake5.lua --cc=clang --file=Build-Server.lua gmake2
popd