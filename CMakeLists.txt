cmake_minimum_required(VERSION 3.30.5)
project(dbfrag)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(ExternalProject)
set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third_party)

ExternalProject_Add(
    CLI11
    PREFIX ${THIRD_PARTY_DIR}
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.1.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    CMAKE_ARGS -DCLI11_BUILD_TESTS=OFF
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(CLI11 source_dir)
add_executable(dbfrag src/main.cpp)
add_dependencies(dbfrag CLI11)

target_include_directories(dbfrag PRIVATE ${source_dir}/include)
