#pragma once

#include "SceneManager.h"

class Game
{
public:
    Game();
    ~Game();

    // Called once at the start
    bool init();

    // Per-frame update and render
    void update(float deltaTime);
    void render();

    // Called once at the end
    void shutdown();

    // Access the scene manager so main can load a scene
    SceneManager& getSceneManager();

private:
    SceneManager sceneManager;
    bool isInitialized;
};
