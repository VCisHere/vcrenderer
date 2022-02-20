#include "Material.h"

Material::Material(Shader* shader)
{
    this->shader = shader;
    SetColor(1, 1, 1);
}

void Material::SetColor(float r, float g, float b)
{
    color.x = r;
    color.y = g;
    color.z = b;
}

void Material::UpdateShader()
{
    shader->SetVec4("material.color", glm::vec4(color.x, color.y, color.z, 1.0f));
    shader->SetFloat("material.shininess", 32.0f);
}
