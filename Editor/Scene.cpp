#include "Scene.h"
#include "RendererEngine.h"

#include <iostream>

void Scene::Render(Context* context)
{
    ImGui::Begin("Scene");

    // 窗体位置
    ImGui::SetWindowPos(ImVec2(windowPosition.x, windowPosition.y), ImGuiCond_Once);
    // 窗体大小
    ImGui::SetWindowSize(ImVec2(windowSize.x, windowSize.y), ImGuiCond_Once);
    
    float wheel = ImGui::GetIO().MouseWheel;
    if (wheel != 0 && ImGui::IsWindowHovered()) {
        Engine->GetWorld()->camera->ProcessMouseScroll(wheel);
    }

    windowPosition.x = ImGui::GetWindowPos().x;
    windowPosition.y = ImGui::GetWindowPos().y;
    windowSize.x = ImGui::GetWindowSize().x;
    windowSize.y = ImGui::GetWindowSize().y;

    ImGui::GetWindowDrawList()->AddImage(
        (void*)context->renderTexture,
        ImVec2(ImGui::GetCursorScreenPos()),
        ImVec2(ImGui::GetCursorScreenPos().x + windowSize.x, ImGui::GetCursorScreenPos().y + windowSize.y),
        ImVec2(0, 1),
        ImVec2(1, 0));

    ImGui::End();
}
