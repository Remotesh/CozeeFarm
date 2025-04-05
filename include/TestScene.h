#pragma once

#include "IScene.h"
#include "SpriteRenderer.h"
#include <GL/glew.h>

class TestScene : public IScene
{
public:
    TestScene();
    ~TestScene();

    void onEnter() override;
    void onExit() override;
    void update(float deltaTime) override;
    void render() override;

private:
    SpriteRenderer spriteRenderer;
    GLuint testTexture;
};
