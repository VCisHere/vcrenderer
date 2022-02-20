#pragma once

#include <glm/gtx/rotate_vector.hpp>

#include <list>
#include <RenderObject.h>
#include <Camera.h>
#include <Light.h>

class World
{
public:
    std::list<RenderObject*> objects;
    Camera* camera;
    Light* light;

    World(); 
    void LoadObject(string const& modelPath, const char* vertexPath, const char* fragmentPath);
    RenderObject* GetObject();
    void Render();
};

