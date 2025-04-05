#pragma once

#include <string>
#include <GL/glew.h>

class TextureLoader
{
public:
    static GLuint loadTexture(const std::string& filePath);
};
