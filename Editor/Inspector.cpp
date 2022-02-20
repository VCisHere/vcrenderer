#include "Inspector.h"
#include "RendererEngine.h"

#include <iostream>

class RendererEngine;
RendererEngine* Engine;

void Inspector::Render(Context* context)
{
    ImGui::Begin("Inspector");

    // 窗体位置
    ImGui::SetWindowPos(ImVec2(windowPosition.x, windowPosition.y), ImGuiCond_Once);
    // 窗体大小
    ImGui::SetWindowSize(ImVec2(windowSize.x, windowSize.y), ImGuiCond_Once);

    windowPosition.x = ImGui::GetWindowPos().x;
    windowPosition.y = ImGui::GetWindowPos().y;
    windowSize.x = ImGui::GetWindowSize().x;
    windowSize.y = ImGui::GetWindowSize().y;

    World* world = Engine->GetWorld();
    Camera* camera = world->camera;
    Light* light = world->light;
    currentObject = world->GetObject();

    if (ImGui::CollapsingHeader("Camera"))
    {
        static float cameraPosition[3] = { camera->Position.x, camera->Position.y, camera->Position.z };
        if (ImGui::DragFloat3("Pos", cameraPosition, 0.01f, 0, 0, "%.3f"))
        {
            camera->Position.x = cameraPosition[0];
            camera->Position.y = cameraPosition[1];
            camera->Position.z = cameraPosition[2];
        }
    }

    static float lightDirection[3] = { 
        glm::degrees(light->direction.x),
        glm::degrees(light->direction.y),
        glm::degrees(light->direction.z)
    };
    static float lightAmbient[3] = { light->ambient.x, light->ambient.y, light->ambient.z };
    static float lightdiffuse[3] = { light->diffuse.x, light->diffuse.y, light->diffuse.z };
    static float lightSpecular[3] = { light->specular.x, light->specular.y, light->specular.z };
    if (ImGui::CollapsingHeader("Light"))
    {
        if (ImGui::DragFloat3("Direction##Light", lightDirection, 0.1f, 0, 0, "%.2f"))
        {
            light->SetDirection(
                glm::radians(lightDirection[0]),
                glm::radians(lightDirection[1]),
                glm::radians(lightDirection[2])
            );
        }
        if (ImGui::ColorEdit3("Ambient##Light", lightAmbient))
        {
            light->SetAmbient(lightAmbient[0], lightAmbient[1], lightAmbient[2]);
        }
        if (ImGui::ColorEdit3("Diffuse##Light", lightdiffuse))
        {
            light->SetDiffuse(lightdiffuse[0], lightdiffuse[1], lightdiffuse[2]);
        }
        if (ImGui::ColorEdit3("Specular##Light", lightSpecular))
        {
            light->SetSpecular(lightSpecular[0], lightSpecular[1], lightSpecular[2]);
        }
    }

    if (currentObject != nullptr)
    {
        if (transformEditor == nullptr)
        {
            transformEditor = new TransformEditor(&currentObject->transform);
        }
        transformEditor->Render();

        static float materialColor[3] = {
            currentObject->material->color.x,
            currentObject->material->color.y,
            currentObject->material->color.z
        };
        if (ImGui::CollapsingHeader("Material"))
        {
            if (ImGui::ColorEdit3("Color##Material", materialColor))
            {
                currentObject->material->SetColor(materialColor[0], materialColor[1], materialColor[2]);
            }
        }
    }

    ImGui::End();
}
