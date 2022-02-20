#include "World.h"

World::World()
{
    camera = new Camera(glm::vec3(0.0f, 0.0f, 5.0f));
    light = new Light();
    light->SetDirection(-0.2f, -1.0f, -0.3f);
    light->SetAmbient(0.2f, 0.2f, 0.2f);
    light->SetDiffuse(0.5f, 0.5f, 0.5f);
    light->SetSpecular(1.0f, 1.0f, 1.0f);
}

void World::LoadObject(string const& modelPath, const char* vertexPath, const char* fragmentPath)
{
    RenderObject* obj = new RenderObject(modelPath, vertexPath, fragmentPath);
    objects.clear();
    objects.push_back(obj);
}

RenderObject* World::GetObject()
{
    return objects.begin() != objects.end() ? *objects.begin() : nullptr;
}

void World::Render()
{
    for (std::list<RenderObject*>::iterator obj = objects.begin(); obj != objects.end(); obj++) {
        Transform transform = (*obj)->transform;
        Material* material = (*obj)->material;
        Shader* shader = (*obj)->shader;

        shader->Use();

        // material properties
        material->UpdateShader();

        // camera properties
        shader->SetVec3("viewPos", camera->Position);

        // light properties
        shader->SetVec3("light.direction", light->direction.x, light->direction.y, light->direction.z);
        shader->SetVec3("light.ambient", light->ambient.x, light->ambient.y, light->ambient.z);
        shader->SetVec3("light.diffuse", light->diffuse.x, light->diffuse.y, light->diffuse.z);
        shader->SetVec3("light.specular", light->specular.x, light->specular.y, light->specular.z);

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)1024 / (float)1024, 0.1f, 1000.0f);
        glm::mat4 view = camera->GetViewMatrix();
        shader->SetMat4("projection", projection);
        shader->SetMat4("view", view);

        // world transformation
        glm::vec3 xNorm(1.0, 0.0f, 0.0);
        glm::vec3 yNorm(0.0, 1.0f, 0.0);
        glm::vec3 zNorm(0.0, 0.0f, 1.0);

        glm::mat4 modelTransform = glm::mat4(1.0f);
        modelTransform = glm::translate(modelTransform, glm::vec3(transform.position.x, transform.position.y, transform.position.z));
        modelTransform = glm::scale(modelTransform, glm::vec3(transform.scale.x, transform.scale.y, transform.scale.z));
        modelTransform = glm::rotate(modelTransform, transform.rotation.y, yNorm);
        xNorm = glm::rotate(xNorm, -transform.rotation.y, xNorm);
        modelTransform = glm::rotate(modelTransform, transform.rotation.x, xNorm);
        zNorm = glm::rotate(zNorm, -transform.rotation.x, yNorm);
        modelTransform = glm::rotate(modelTransform, transform.rotation.z, zNorm);

        shader->SetMat4("model", modelTransform);

        (*obj)->model->Draw(*shader);
    }
}
