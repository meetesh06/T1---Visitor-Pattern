CMAKE_MINIMUM_REQUIRED (VERSION 3.5)

PROJECT(visitorPattern)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set (project_dir "${PROJECT_SOURCE_DIR}/src")

file ( GLOB project_files "${project_dir}/*.cpp")

add_executable(visitorPattern ${project_files})