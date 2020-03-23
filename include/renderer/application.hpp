#pragma once

#include "vulkan/vulkan.hpp"
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

namespace odin {
class Application {
public:
  Application();

  void run();

private:
  void cleanup();
  void createInstance();
  void initVulkan();
  void initWindow();

  GLFWwindow *window;
  vk::Instance instance;
};
} // namespace odin