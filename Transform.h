#pragma once

#include <CustomTypes.h>

class Transform
{
public:
    CustomTypes::Vector3 position;
    CustomTypes::Vector3 rotation;
    CustomTypes::Vector3 scale;

    Transform() : position(), rotation(), scale(1, 1, 1) {}

    void SetPosition(float x, float y, float z);
    void SetRotation(float x, float y, float z);
    void SetScale(float x, float y, float z);
};
