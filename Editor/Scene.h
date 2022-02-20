#pragma once

#include <Editor/WindowBase.h>

class Scene: public WindowBase
{
private:
public:
    Scene(int x, int y, unsigned int width, unsigned int height)
        : WindowBase(x, y, width, height) {}

    virtual void Render(Context* context) override;
};
