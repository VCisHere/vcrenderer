#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui/imgui_impl_glfw.h>
#include <Transform.h>

class TransformEditor
{
private:
    float position[3];
    float rotation[3];
    float scale[3];
    Transform* controlTransform;
public:
    TransformEditor(Transform* transform)
    {
        controlTransform = transform;

        position[0] = transform->position.x;
        position[1] = transform->position.y;
        position[2] = transform->position.z;

        rotation[0] = transform->rotation.x;
        rotation[1] = transform->rotation.y;
        rotation[2] = transform->rotation.z;

        scale[0] = transform->scale.x;
        scale[1] = transform->scale.y;
        scale[2] = transform->scale.z;
    }

    void Render()
    {
        if (ImGui::CollapsingHeader("Transform"))
        {
            if (ImGui::DragFloat3("Position", position, 0.1f, 0, 0, "%.2f"))
            {
                controlTransform->SetPosition(position[0], position[1], position[2]);
            }

            if (ImGui::DragFloat3("Rotation", rotation, 0.1f, 0, 0, "%.2f"))
            {
                controlTransform->SetRotation(glm::radians(rotation[0]), glm::radians(rotation[1]), glm::radians(rotation[2]));
            }

            if (ImGui::DragFloat3("Scale", scale, 0.1f, 0, 0, "%.2f"))
            {
                controlTransform->SetScale(scale[0], scale[1], scale[2]);
            }
        }
    }

};