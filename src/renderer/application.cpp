#include "renderer/application.hpp"

odin::Application::Application() {
  initWindow();
  initVulkan();
}

void odin::Application::cleanup() {
  // Vulkan cleanup
  vkDestroyInstance(instance, nullptr);

  // GLFW cleanup
  glfwDestroyWindow(window);
  glfwTerminate();
}

void odin::Application::createInstance() {
  vk::ApplicationInfo appInfo("Odin", VK_MAKE_VERSION(0, 1, 0), "No Engine",
                              VK_VERSION_1_2);

  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  vk::InstanceCreateInfo createInfo;
  createInfo.setPApplicationInfo(&appInfo);
  createInfo.setEnabledExtensionCount(glfwExtensionCount);
  createInfo.setPpEnabledExtensionNames(glfwExtensions);
  createInfo.setEnabledLayerCount(0);

  instance = vk::createInstance(createInfo);
  std::cout << "Created Instance" << std::endl;
}

void odin::Application::run() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  // Cleanup after window is closed
  cleanup();
}

void odin::Application::initVulkan() { createInstance(); }

void odin::Application::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(800, 600, "Odin", nullptr, nullptr);
}