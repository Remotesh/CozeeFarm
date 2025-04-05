#include "Game.h"
#include <iostream>

Game::Game()
    : isInitialized(false)
{
}

Game::~Game()
{
    shutdown();
}

bool Game::init()
{
    std::cout << "Game init...\n";

    // In the future, init subsystems here (audio, assets, etc.)
    isInitialized = true;
    return true;
}

void Game::update(float deltaTime)
{
    if (isInitialized)
    {
        sceneManager.update(deltaTime);
    }
}

void Game::render()
{
    if (isInitialized)
    {
        sceneManager.render();
    }
}

void Game::shutdown()
{
    std::cout << "Shutting down game...\n";
    isInitialized = false;
}

SceneManager& Game::getSceneManager()
{
    return sceneManager;
}
