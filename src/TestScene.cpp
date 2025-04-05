#include "TestScene.h"
#include "TextureLoader.h"
#include <iostream>
#include <glm/vec2.hpp>

TestScene::TestScene()
    : testTexture(0)
{
}

TestScene::~TestScene()
{
    onExit();
}

void TestScene::onEnter()
{
    std::cout << "[TestScene] Entering...\n";

    spriteRenderer.init();

    testTexture = TextureLoader::loadTexture("assets/sprites/turnip.png");
    std::cout << "Loaded texture ID: " << testTexture << "\n";
    if (!testTexture)
    {
        std::cerr << "[TestScene] Failed to load turnip texture\n";
    }
}

void TestScene::onExit()
{
    std::cout << "[TestScene] Exiting...\n";

    spriteRenderer.shutdown();

    if (testTexture)
    {
        glDeleteTextures(1, &testTexture);
        testTexture = 0;
    }
}

void TestScene::update(float deltaTime)
{
    // Nothing dynamic yet
}

void TestScene::render()
{
    spriteRenderer.draw(testTexture, glm::vec2(384, 284), glm::vec2(32, 32));
}
