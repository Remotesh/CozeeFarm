#include "SceneManager.h"
#include <iostream>

SceneManager::SceneManager()
{
    // Nothing to do yet
}

SceneManager::~SceneManager()
{
    if (currentScene)
    {
        currentScene->onExit();
    }
}

void SceneManager::changeScene(std::unique_ptr<IScene> newScene)
{
    if (currentScene)
    {
        currentScene->onExit();
    }

    currentScene = std::move(newScene);

    if (currentScene)
    {
        currentScene->onEnter();
    }
}

void SceneManager::update(float deltaTime)
{
    if (currentScene)
    {
        currentScene->update(deltaTime);
    }
}

void SceneManager::render()
{
    if (currentScene)
    {
        currentScene->render();
    }
}
