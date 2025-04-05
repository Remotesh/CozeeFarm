#include "SpriteRenderer.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

const char* vertexShaderSrc = R"(
#version 120
attribute vec2 position;
attribute vec2 texCoord;
uniform mat4 uTransform;
varying vec2 vTexCoord;

void main()
{
    vTexCoord = texCoord;
    gl_Position = uTransform * vec4(position, 0.0, 1.0);
}
)";

const char* fragmentShaderSrc = R"(
#version 120
varying vec2 vTexCoord;
uniform sampler2D uTexture;

void main()
{
    vec4 texColor = texture2D(uTexture, vTexCoord);
    if (texColor.a < 0.1)
        discard; // skips fully transparent pixels
    gl_FragColor = texColor;
}
)";
    

SpriteRenderer::SpriteRenderer()
    : vao(0), vbo(0), shaderProgram(0), vertexShader(0), fragmentShader(0), uTransformLoc(-1)
{
}

SpriteRenderer::~SpriteRenderer()
{
    shutdown();
}

bool SpriteRenderer::init()
{
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSrc, nullptr);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSrc, nullptr);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    uTransformLoc = glGetUniformLocation(shaderProgram, "uTransform");

    float vertices[] = {
        0.0f, 1.0f,  0.0f, 1.0f,
        1.0f, 0.0f,  1.0f, 0.0f,
        0.0f, 0.0f,  0.0f, 0.0f,

        0.0f, 1.0f,  0.0f, 1.0f,
        1.0f, 1.0f,  1.0f, 1.0f,
        1.0f, 0.0f,  1.0f, 0.0f
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(posAttrib);

    GLint texAttrib = glGetAttribLocation(shaderProgram, "texCoord");
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(texAttrib);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return true;
}

void SpriteRenderer::draw(GLuint textureID, const glm::vec2& position, const glm::vec2& size)
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);

    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(position, 0.0f));
    transform = glm::scale(transform, glm::vec3(size, 1.0f));

    glUniformMatrix4fv(uTransformLoc, 1, GL_FALSE, &transform[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    GLint uTexLoc = glGetUniformLocation(shaderProgram, "uTexture");
    glUniform1i(uTexLoc, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::shutdown()
{
    if (shaderProgram) glDeleteProgram(shaderProgram);
    if (vertexShader) glDeleteShader(vertexShader);
    if (fragmentShader) glDeleteShader(fragmentShader);
    if (vbo) glDeleteBuffers(1, &vbo);
    if (vao) glDeleteVertexArrays(1, &vao);
}
