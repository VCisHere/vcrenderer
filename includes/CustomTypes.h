#pragma once
namespace CustomTypes
{
    class Vector2 {
    public:
        float x;
        float y;

        Vector2(float x = 0, float y = 0) : x(x), y(y) {};
    };

    class Vector3 {
    public:
        float x;
        float y;
        float z;

        Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {};
    };
};
