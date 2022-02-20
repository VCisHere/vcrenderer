#pragma once

#include <CustomTypes.h>

class Light
{
public:
    CustomTypes::Vector3 direction;
    CustomTypes::Vector3 ambient;
    CustomTypes::Vector3 diffuse;
    CustomTypes::Vector3 specular;

    void SetDirection(float x, float y, float z)
    {
        direction = CustomTypes::Vector3(x, y, z);
    }

    void SetAmbient(float x, float y, float z)
    {
        ambient = CustomTypes::Vector3(x, y, z);
    }

    void SetDiffuse(float x, float y, float z)
    {
        diffuse = CustomTypes::Vector3(x, y, z);
    }

    void SetSpecular(float x, float y, float z)
    {
        specular = CustomTypes::Vector3(x, y, z);
    }
};