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
cmake_minimum_required(VERSION 3.24)

# Project
project(
    CMake-OpenGL
    DESCRIPTION "Template repository for CMake OpenGL projects."
    HOMEPAGE_URL "https://github.com/krajcsozalan/cmake-opengl-cicd-template"
    LANGUAGES C CXX
)

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

if (NOT TARGET OpenGL::OpenGL)
    add_library(OpenGL::OpenGL ALIAS OpenGL::GL)
endif()

target_link_libraries(main PRIVATE OpenGL::OpenGL)

# GLFW
include(FetchContent)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.10
    GIT_SHALLOW ON
    FIND_PACKAGE_ARGS 3.3.10 NAMES glfw3
)

FetchContent_MakeAvailable(glfw)

target_link_libraries(main PRIVATE glfw)

# glad
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG v2.0.8
    GIT_SHALLOW ON
    SOURCE_SUBDIR cmake
)

FetchContent_MakeAvailable(glad)

glad_add_library(glad API gl:core=4.6)

target_link_libraries(main PRIVATE glad)

# Test
include(CTest)

add_executable(
    test_main
    "${PROJECT_SOURCE_DIR}/src/tests/test_main.cpp"
)

add_test(NAME main COMMAND test_main)

# Package
install(FILES LICENSE TYPE DOC)
install(TARGETS main glad)

if(glfw_FOUND)
	install(IMPORTED_RUNTIME_ARTIFACTS glfw)
else()
	install(TARGETS glfw)
endif()

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "krajcsozalan")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Template repository for CMake OpenGL projects")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPack Component Example")
set(CPACK_PACKAGE_EXECUTABLES "main" "${PROJECT_NAME}")
set(CPACK_CREATE_DESKTOP_LINKS "main")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

set(CPACK_NSIS_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_NSIS_INSTALLED_ICON_NAME "bin/main.exe")

include(CPack)
