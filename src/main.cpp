#include <iostream>
#include <stdexcept>

#include "renderer/application.hpp"

int main() {
    try {
        odin::Application app;
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}