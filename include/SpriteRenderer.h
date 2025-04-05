#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class SpriteRenderer
{
public:
    SpriteRenderer();
    ~SpriteRenderer();

    bool init();
    void draw(GLuint textureID, const glm::vec2& position, const glm::vec2& size);
    void shutdown();

private:
    GLuint vao;
    GLuint vbo;
    GLuint shaderProgram;
    GLuint vertexShader;
    GLuint fragmentShader;
    GLint uTransformLoc;
};
