#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <CustomTypes.h>
#include <Shader.h>
#include <Camera.h>
#include <Model.h>
#include <World.h>
#include <Editor/Context.h>

class Renderer
{
private:
    unsigned int renderWidth;
    unsigned int renderHeight;

    unsigned int framebuffer;
    unsigned int colorbuffer;
    unsigned int renderbuffer;

    World* world;

    float lastX;
    float lastY;
    bool firstMouse;

    // timing
    float deltaTime;
    float lastFrame;

    void SetFrameBuffer();
    
public:
    Renderer(unsigned int width, unsigned int height, Context* context);
    
    void Render();

    void SetRenderSize(unsigned int width, unsigned int height);
    unsigned int GetRenderTexture();
    Camera* GetCamera();
};

