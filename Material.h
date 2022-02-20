#pragma once

#include <Shader.h>
#include <CustomTypes.h>

class Material
{
public:
    CustomTypes::Vector3 color;
    Shader* shader;

    Material(Shader* shader);
    void SetColor(float r, float g, float b);
    void UpdateShader();
};
