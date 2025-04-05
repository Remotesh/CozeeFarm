#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

#include "Game.h"

#include "TestScene.h"

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(800, 600, "CozeeFarm", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    glViewport(0, 0, 800, 600);


    if (glewInit() != GLEW_OK)
    {
        std::cerr << "GLEW initialization failed\n";
        return -1;
    }

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    


    // Enable VSync (optional)
    glfwSwapInterval(1);

    // --- Game Setup ---
    Game game;
    if (!game.init())
    {
        std::cerr << "Failed to initialize game systems\n";
        return -1;
    }

    game.getSceneManager().changeScene(std::make_unique<TestScene>());

    // Timing
    auto lastTime = std::chrono::high_resolution_clock::now();

    // --- Main Game Loop ---
    while (!glfwWindowShouldClose(window))
    {
        // Calculate deltaTime
        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        // Update game logic
        game.update(deltaTime);

        // Render scene
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        game.render();

        // Swap buffers and poll input
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    game.shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
