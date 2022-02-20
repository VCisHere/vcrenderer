#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <RendererEditor.h>
#include <Renderer.h>

class RendererEngine
{
private:
    unsigned int windowWidth;
    unsigned int windowHeight;
    GLFWwindow* window;
    World* world;
    RendererEditor* editor;
    Renderer* renderer;
    Context* context;

    void CreateWindow(unsigned int width, unsigned int height);
    void Render();
    void ProcessInput();
    
    static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
public:
    RendererEngine(unsigned int width, unsigned int height);
    void Run();
    World* GetWorld();
};

extern RendererEngine* Engine;