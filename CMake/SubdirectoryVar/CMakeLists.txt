cmake_minimum_required (VERSION 3.6)

set(MASTER_VAR master)
message("MASTER_VAR " ${MASTER_VAR})

add_subdirectory("Subdir")

message("SLAVE_VAR " ${SLAVE_VAR})