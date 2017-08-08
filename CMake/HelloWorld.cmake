#!/bin/env bash
#[[
name=`basename "$0"`
name="${name%.*}";
if [ -e "CMakeLists.txt" ]; then
    mv "CMakeLists.txt" "${name}TmpCMakeLists.txt"
fi
cp $0 CMakeLists.txt
if [ ! -d build$name ]; then
    mkdir build$name
fi
cd build$name
cmake ../
cd ..
rm CMakeLists.txt
if [ -e "${name}TmpCMakeLists.txt" ]; then
    mv "${name}TmpCMakeLists.txt" "CMakeLists.txt"
fi
exit
]]
cmake_minimum_required (VERSION 3.6)

message("Hello, World!")

 ################## 
# Local Variables: #
# mode: CMAKE      #
# End:             #
 ################## 
