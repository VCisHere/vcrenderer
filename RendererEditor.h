#pragma once

#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

#include <CustomTypes.h>
#include <Editor/Scene.h>
#include <Editor/Inspector.h>

class RendererEditor
{
private:

public:
    Scene* scene;
    Inspector* inspector;

    RendererEditor(GLFWwindow* window);
    ~RendererEditor();
    void Render(Context* context);
};

