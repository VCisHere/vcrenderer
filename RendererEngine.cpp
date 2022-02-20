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

        // ��������
        glfwSwapBuffers(window);
        // ���IO�¼�
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

// ѯ��GLFW�Ƿ���/�ͷ���ؼ�����������Ӧ��Ӧ
// --------------------------------------
void RendererEngine::ProcessInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

// ���ڴ�С�ı�ʱִ��
// ----------------
void RendererEngine::FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    // viewportƥ���µĴ��ڴ�С
    // glViewport(0, 0, width, height);
}
