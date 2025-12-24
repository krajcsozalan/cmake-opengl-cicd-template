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

     return EXIT_SUCCESS;
}
