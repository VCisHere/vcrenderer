#include "RenderObject.h"

RenderObject::RenderObject(string const& modelPath, const char* vertexPath, const char* fragmentPath)
{
    model = new Model(modelPath);
    shader = new Shader(vertexPath, fragmentPath);
    material = new Material(shader);
}
