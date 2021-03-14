cmake_minimum_required(VERSION 3.11)
project(pvsp_engine)
ADD_SUBDIRECTORY(include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(BINARY_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})

#find_package(raylib 3.0 QUIET)

#if (NOT raylib_FOUND)
#  include(FetchContent)
#
#  FetchContent_Declare(
#    raylib
#    URL https://github.com/raysan5/raylib/archive/master.tar.gz
#  )
#
#  FetchContent_GetProperties(raylib)
#  if (NOT raylib_POPULATED)
#    set(FETCHCONTENT_QUIET NO)
#    FetchContent_Populate(raylib)
#
#    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#
#    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
#
#  endif()
#
#endif()

include_directories("src")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib imgui)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC include)
