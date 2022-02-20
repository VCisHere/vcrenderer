#pragma once

#include <Editor/WindowBase.h>
#include <Editor/Component/TransformEditor.h>
#include <RenderObject.h>

class Inspector : WindowBase
{
private:
    RenderObject* currentObject;
    TransformEditor* transformEditor;
public:
    Inspector(int x, int y, unsigned int width, unsigned int height)
        : WindowBase(x, y, width, height)
    {
        currentObject = nullptr;
        transformEditor = nullptr;
    };
    virtual void Render(Context* context) override;
};
