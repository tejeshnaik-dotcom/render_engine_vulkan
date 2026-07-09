#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

#include <iostream>

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Tell GLFW that we are NOT using OpenGL
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(
        800,
        600,
        "Vulkan Window",
        nullptr,
        nullptr);

    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Query Vulkan extensions
    uint32_t extensionCount = 0;

    vkEnumerateInstanceExtensionProperties(
        nullptr,
        &extensionCount,
        nullptr);

    std::cout << extensionCount
              << " Vulkan extensions are supported."
              << std::endl;

    // Test GLM
    glm::mat4 matrix(1.0f);          // Identity matrix
    glm::vec4 vector(1.0f, 2.0f, 3.0f, 1.0f);

    glm::vec4 result = matrix * vector;

    std::cout << "Matrix × Vector = ("
              << result.x << ", "
              << result.y << ", "
              << result.z << ", "
              << result.w << ")"
              << std::endl;

    // Keep the window open
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}