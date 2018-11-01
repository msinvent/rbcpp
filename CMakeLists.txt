cmake_minimum_required(VERSION 3.5)

if (CMAKE_VERSION VERSION_GREATER "3.8.0")
    project(ROSBridgeClient VERSION 0.1
            DESCRIPTION "C++ ROSBridgeClient"
            LANGUAGES CXX)
else ()
    project(ROSBridgeClient VERSION 0.1
            LANGUAGES CXX)
endif ()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMPILER "UNKNOWN")

if (CMAKE_COMPILER_IS_GNUCXX)
    set(COMPILER "G")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "AppleClang")
    set(COMPILER "Apple Clang")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "AppleClang")
    set(COMPILER "Clang")
endif ()

if ("${COMPILER}" STREQUAL "UNKNOWN")
    message(FATAL_ERROR "Invalid Compiler")
endif ()

message(STATUS "${COMPILER}++ Version: " ${CMAKE_CXX_COMPILER_VERSION})

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if (EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif ()

find_package(Catch2 REQUIRED)
find_package(cpprestsdk REQUIRED)
find_package(Boost COMPONENTS system thread chrono REQUIRED)

add_library(librbc "" src/msgs/geometry_msgs/accel_stamped.cxx include/ros_bridge_client/msgs/geometry_msgs/accel_stamped.h)
add_subdirectory(src)
target_include_directories(librbc PUBLIC include)
target_compile_options(librbc PRIVATE -Wall -Wextra -Weffc++ -Wconversion -Wredundant-decls -Wunreachable-code -pedantic -Wcomment -Wcast-qual)
target_link_libraries(librbc
        cpprestsdk::cpprest
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_CHRONO_LIBRARY})

add_subdirectory(test)