# cmake-opengl-cicd-template - Template repository for CMake OpenGL projects
# Copyright (C) 2025  krajcsozalan
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
cmake_minimum_required(VERSION 3.18)

# Project
project(
    CMake-OpenGL
    DESCRIPTION "Template repository for CMake OpenGL projects."
    HOMEPAGE_URL "https://github.com/krajcsozalan/cmake-opengl-cicd-template"
    LANGUAGES CXX
)

install(FILES LICENSE TYPE DOC)

# Executable
add_executable(
    main
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

set_target_properties(
    main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(
    main
    PRIVATE $<$<CONFIG:Debug>:$<IF:$<CXX_COMPILER_ID:MSVC>,/W4,-Wall;-Wextra;-Wpedantic>>
)

# OpenGL
find_package(OpenGL 4.6 REQUIRED)

target_link_libraries(main PRIVATE OpenGL::OpenGL)

# Test
include(CTest)

add_executable(
    test_main
    "${PROJECT_SOURCE_DIR}/src/tests/test_main.cpp"
)

add_test(NAME main COMMAND test_main)
