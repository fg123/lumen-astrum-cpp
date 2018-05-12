cmake_minimum_required(VERSION 3.9)
project(lumen_astrum)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(resources)

file(GLOB sourceFiles "src/*.h" "src/*.cpp")
add_executable(lumen_astrum ${sourceFiles})
add_dependencies(lumen_astrum resources)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(SFML_ROOT "D:\\SFML-2.4.2")

find_package(SFML 2 REQUIRED network audio graphics window system)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(lumen_astrum ${SFML_LIBRARIES})
endif ()
