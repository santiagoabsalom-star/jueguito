#!/bin/bash
set -e

cmake -B build -G Ninja -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
ln -sf build/compile_commands.json .
cmake --build build
./build/jueguito

