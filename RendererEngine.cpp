#include "RendererEngine.h"
#include <iostream>

RendererEngine::RendererEngine(unsigned int windowWidth, unsigned int windowHeight)
{
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    CreateWindow(windowWidth, windowHeight);

    stbi_set_flip_vertically_on_load(true);

    context = new Context();

    world = new World();

    renderer = new Renderer(1024, 1024, context);
    editor = new RendererEditor(window);

    context->renderTexture = renderer->GetRenderTexture();

}

void RendererEngine::CreateWindow(unsigned int width, unsigned int height)
{
    window = glfwCreateWindow(width, height, "vcrenderer", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    // glfwSwapInterval(1);
    // glfwSetScrollCallback(window, scrollFunc);
    // glfwSetCursorPosCallback(window, cursorPosFunc);
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glViewport(0, 0, 1024, 1024);
}

void RendererEngine::Run()
{
    if (window == NULL)
    {
        std::cout << "The window has not been created" << std::endl;
        exit(-1);
    }
    while (!glfwWindowShouldClose(window))
    {
        // input
        ProcessInput();

        // render
        Render();

        // 交换缓冲
        glfwSwapBuffers(window);
        // 检查IO事件
        glfwPollEvents();
    }
    glfwTerminate();
}

World* RendererEngine::GetWorld()
{
    return world;
}

void RendererEngine::Render()
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    
    renderer->Render();
    
    editor->Render(context);
}

// 询问GLFW是否按下/释放相关键，并做出相应反应
// --------------------------------------
void RendererEngine::ProcessInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

// 窗口大小改变时执行
// ----------------
void RendererEngine::FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    // viewport匹配新的窗口大小
    // glViewport(0, 0, width, height);
}
