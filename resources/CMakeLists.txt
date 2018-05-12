cmake_minimum_required(VERSION 3.9)
project(lumen_astrum)

add_subdirectory(resourceBuilder)
add_subdirectory(mapToBin)
file(REMOVE map.bin)
file(GLOB all RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.*")
message(STATUS "Globbed before exclude is ${all}")
list(FILTER all EXCLUDE REGEX "[.*]txt")

add_custom_target(resources)
add_custom_command(TARGET resources POST_BUILD
        COMMAND mapToBin ARGS map.txt map.bin
        COMMAND resourceBuilder ARGS ../bin/resources/A.bin ${all} map.bin
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM COMMENT "Generating resources ${all}")
