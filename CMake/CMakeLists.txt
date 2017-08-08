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
touch file1
touch file2
cmake ../ -DCMAKE_INSTALL_PREFIX:PATH=./install
make
make install
cd ..
rm CMakeLists.txt
if [ -e "${name}TmpCMakeLists.txt" ]; then
    mv "${name}TmpCMakeLists.txt" "CMakeLists.txt"
fi
exit
]]
cmake_minimum_required (VERSION 3.6)

function(run_on_install COMMAND)
  message("Will run on install: " ${COMMAND})
  install(
    CODE
    ${COMMAND}
  )
endfunction(run_on_install)

message("In Main CMake")

ADD_CUSTOM_COMMAND(
  OUTPUT file1.txt
  COMMAND touch file1.txt
  )

# IMPLICIT_DEPENDS(file1.txt)

run_on_install("message(\"Installing\")")

# install(TARGETS file1.txt DESTINATION folder)

 
 ################## 
# Local Variables: #
# mode: CMAKE      #
# End:             #
 ################## 
