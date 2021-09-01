cmake_minimum_required (VERSION 3.5.1)

project(amalgam)
add_executable(amalgam amalgam.cc)

project(stucturedMixins)
add_executable(stucturedMixins stucturedMixins.cc)

project(iteratorstability)
add_executable(iteratorstability iteratorstability.cc)

project(nestedvariadic)
add_executable(nestedvariadic nestedvariadic.cc)

add_subdirectory(lib/nlohmannjson)

project(snowflake)
add_executable(snowflake snowflake.cc)
target_link_libraries(snowflake nlohmann_json::nlohmann_json)

