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
if [ -d extras ]; then
    rm -rf extras
fi
# touch file1
# touch file2
echo "********************"
echo $ cmake ../ -DCMAKE_INSTALL_PREFIX:PATH=../install$name
cmake ../ -DCMAKE_INSTALL_PREFIX:PATH=../install$name
printf "********************\n\n********************\n"
echo $ make
make
printf "********************\n\n********************\n"
echo $ make install
make install
echo "********************"
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

add_custom_command(
  OUTPUT file1.txt
  COMMAND echo "file #1" > ${CMAKE_CURRENT_BINARY_DIR}/file1.txt
  )
add_custom_target(file1 ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/file1.txt)

run_on_install("message(\"Installing\")")

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/file1.txt DESTINATION bin)

run_on_install("file(MAKE_DIRECTORY extras)")
run_on_install("execute_process(COMMAND echo \"file #2\" OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/extras/file2.txt)")
run_on_install("execute_process(COMMAND echo \"file #3\" OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/extras/file3.txt)")
run_on_install("message(\"Looking for Extras with: \" ${CMAKE_CURRENT_BINARY_DIR}/extras/*.txt)")
run_on_install("file(GLOB extras ${CMAKE_CURRENT_BINARY_DIR}/extras/*.txt)")
run_on_install("message(\"Extras Found: \" \"\${extras}\")")
run_on_install("file(INSTALL \${extras} DESTINATION \"\${CMAKE_INSTALL_PREFIX}/lib\")")
# install(FILES extras/* DESTINATION lib)

 
 ################## 
# Local Variables: #
# mode: CMAKE      #
# End:             #
 ################## 
