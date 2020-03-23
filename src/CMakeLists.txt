set(SOURCE_FILES
    main.cpp
    renderer/application.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
                        glfw Vulkan::Vulkan
                        ${VULKAN_SDK/lib})

# Options for debugging. Can be disabled later
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -g)

install(TARGETS odin DESTINATION ${ODIN_INSTALL_BIN_DIR})