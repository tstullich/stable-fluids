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
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Odin";
    appInfo.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_VERSION_1_2;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }

    std::cout << "Created Instance" << std::endl;
}

void odin::Application::run() {
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    // Cleanup after window is closed
    cleanup();
}

void odin::Application::initVulkan() {
    createInstance();
}

void odin::Application::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(800, 600, "Odin", nullptr, nullptr);
}