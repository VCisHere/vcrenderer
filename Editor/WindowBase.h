#pragma once

#include <imgui/imgui_impl_glfw.h>
#include <CustomTypes.h>
#include <Editor/Context.h>

class WindowBase
{
protected:
    CustomTypes::Vector2 windowPosition;
    CustomTypes::Vector2 windowSize;

    WindowBase(int x = 0, int y = 0, unsigned int width = 400, unsigned int height = 300)
        : windowPosition(float(x), float(y)), windowSize(float(width), float(height)) {}

    virtual ~WindowBase() {};

public:
    virtual void Render(Context* context) = 0;

    CustomTypes::Vector2 GetWindowPosition() const
    {
        return CustomTypes::Vector2(windowPosition);
    }

    CustomTypes::Vector2 GetWindowSize() const
    {
        return CustomTypes::Vector2(windowSize);
    }
};
