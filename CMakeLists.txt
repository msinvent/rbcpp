cmake_minimum_required(VERSION 3.8)

if (CMAKE_VERSION VERSION_GREATER "3.8.0")
    project(ROSBridgeClient VERSION 0.1
            DESCRIPTION "C++ ROSBridgeClient"
            LANGUAGES CXX)
else ()
    project(ROSBridgeClient VERSION 0.1
            LANGUAGES CXX)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_COMPILER_IS_GNUCXX AND NOT CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 6.0)
    message(FATAL_ERROR "Invalid Compiler: gcc >= 6.0 is needed")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "AppleClang" AND NOT CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 9.0.0.9000038)
    message(FATAL_ERROR "Invalid Compilter: apple clang >= 9.0.0.9000038 / xcode >= 9.1 is needed")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND NOT CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.0)
    message(FATAL_ERROR "Invalid Compiler: clang >= 5.0 is needed")
endif ()

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if (EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif ()

# openssl is not found on mac osx
if (CMAKE_CXX_COMPILER_ID MATCHES "AppleClang")
    set(OPENSSL_ROOT_DIR /usr/local/opt/openssl CACHE PATH "Sets Mac Openssl root dir" FORCE)
    set(OPENSSL_INCLUDE_DIR /usr/local/opt/openssl/include CACHE PATH "Sets Mac Openssl include dir" FORCE)
endif()

find_package(cpprestsdk REQUIRED)
find_package(Boost COMPONENTS system thread chrono REQUIRED)

add_library(librbc "")
add_subdirectory(src/rbc)
target_include_directories(librbc PUBLIC include)
target_compile_options(librbc PRIVATE -Wall -Wextra -Weffc++ -Wconversion -Wredundant-decls -Wunreachable-code -pedantic -Wcomment -Wcast-qual)
target_link_libraries(librbc
        cpprestsdk::cpprest
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_CHRONO_LIBRARY})

option(COMPILE_TEST "Compile all Tests" OFF)
if (COMPILE_TEST)
    message(STATUS "Compiling Tests as well")

    add_library(config_parser "")
    add_subdirectory(src/config_parser)
    target_include_directories(config_parser PUBLIC include)
    target_compile_options(config_parser PRIVATE -Wall -Wextra -Weffc++ -Wconversion -Wredundant-decls -Wunreachable-code -pedantic -Wcomment -Wcast-qual)
    target_link_libraries(config_parser
            cpprestsdk::cpprest
            ${Boost_SYSTEM_LIBRARY}
            ${Boost_THREAD_LIBRARY}
            ${Boost_CHRONO_LIBRARY})
    add_subdirectory(test)
endif ()
