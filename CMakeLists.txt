cmake_minimum_required(VERSION 3.13.4)
project(odin VERSION 0.1 LANGUAGES CXX)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SUPPRESS_REGENERATION true)

find_package(glfw3 3.3 REQUIRED)
find_package(Vulkan 1.2 REQUIRED)

# Include custom Vulkan bindings
set(VULKAN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/deps/vulkan)

set(ODIN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ODIN_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

include_directories(${VULKAN_INCLUDE_DIR})
include_directories(${ODIN_INCLUDE_DIR})

add_subdirectory(src)