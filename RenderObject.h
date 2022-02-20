#pragma once

#include <Model.h>
#include <Shader.h>
#include <Transform.h>
#include <Material.h>

class RenderObject
{
public:
    Transform transform;
    Model* model;
    Material* material;
    Shader* shader;

    RenderObject(string const& modelPath, const char* vertexPath, const char* fragmentPath);
};
