#pragma once

class IScene
{
public:
    virtual ~IScene() = default;

    // Called once when the scene becomes active
    virtual void onEnter() = 0;

    // Called once when the scene is deactivated
    virtual void onExit() = 0;

    // Called every frame to update logic
    virtual void update(float deltaTime) = 0;

    // Called every frame to render
    virtual void render() = 0;
};
