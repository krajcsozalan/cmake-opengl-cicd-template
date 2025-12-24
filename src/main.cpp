/* cmake-opengl-cicd-template - Template repository for CMake OpenGL projects
 * Copyright (C) 2025  krajcsozalan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <cstdlib>

#include <iostream>
#include <string_view>

#include <glad/gl.h>

#include <GLFW/glfw3.h>

[[noreturn]] static void glfw_error_callback(int error_code,
                                             const char *description) {
    std::cerr << "GLFW error 0x" << std::hex << error_code << ": "
              << description << std::endl;

    std::exit(EXIT_FAILURE);
}

int main(int argc, const char *argv[]) {
    if (argc == 1) {
        std::cout
            << "cmake-opengl-cicd-template  Copyright (C) 2025  krajcsozalan\n"
               "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
               "This is free software, and you are welcome to redistribute it\n"
               "under certain conditions; type `show c' for details.\n";
    }

    for (int i = 1; i < argc - 1; ++i) {
        if (std::string_view(argv[i]) != "show")
            continue;

        if (std::string_view(argv[i + 1]) == "w") {
            std::cout
                << "This program is distributed in the hope that it will be useful,\n"
                   "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                   "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
                   "GNU General Public License for more details.\n"
                   "\n"
                   "You should have received a copy of the GNU General Public License\n"
                   "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";

            return EXIT_SUCCESS;
        } else if (std::string_view(argv[i + 1]) == "c") {
            std::cout
                << "This program is free software: you can redistribute it and/or modify\n"
                   "it under the terms of the GNU General Public License as published by\n"
                   "the Free Software Foundation, either version 3 of the License, or\n"
                   "any later version.\n"
                   "\n"
                   "You should have received a copy of the GNU General Public License\n"
                   "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";

            return EXIT_SUCCESS;
        }
    }

    glfwSetErrorCallback(glfw_error_callback);

    glfwInit();
    std::atexit(glfwTerminate);

    std::cout << "Initialized GLFW" << std::endl;

    GLFWwindow *window = glfwCreateWindow(
        640, 480, "CMake OpenGL CI/CD Template", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    std::cout << "Created window" << std::endl;

    int gl_version = gladLoadGL(glfwGetProcAddress);
    if (!gl_version) {
        std::cerr << "Failed to initialize glad!" << std::endl;

    std:
        exit(EXIT_FAILURE);
    }

    std::cout << "Initialized glad! OpenGL version: "
              << GLAD_VERSION_MAJOR(gl_version) << "."
              << GLAD_VERSION_MINOR(gl_version) << std::endl;

    glClearColor(.25f, .5f, 1.f, 1.f);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    return EXIT_SUCCESS;
}
