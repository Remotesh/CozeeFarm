#pragma once

#include "IScene.h"
#include <memory>

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    // Set a new scene (replaces the current one)
    void changeScene(std::unique_ptr<IScene> newScene);

    // Called every frame to update the current scene
    void update(float deltaTime);

    // Called every frame to render the current scene
    void render();

private:
    std::unique_ptr<IScene> currentScene;
};
