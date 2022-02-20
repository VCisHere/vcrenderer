#include "RendererEditor.h"
#include "RendererEngine.h"

RendererEditor::RendererEditor(GLFWwindow* window)
{
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 450");

    scene = new Scene(0, 19, 749, 749);
    inspector = new Inspector(749, 19, 275, 749);
}

RendererEditor::~RendererEditor()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void RendererEditor::Render(Context* context)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

    // 窗体风格
    ImGuiStyle& style = ImGui::GetStyle();
    // 窗体边框圆角
    style.WindowRounding = 0.0f;
    style.WindowPadding = ImVec2(1, 1);
    {
        bool openLoadModelPopup = false;
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("Start"))
            {
                if (ImGui::MenuItem("Load Model"))
                {
                    openLoadModelPopup = true;
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        if (openLoadModelPopup)
        {
            ImGui::OpenPopup("Load Model##Popup");
            ImVec2 center = ImGui::GetMainViewport()->GetCenter();
            ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        }

        if (ImGui::BeginPopupModal("Load Model##Popup", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            static char modelPath[512] = "";
            ImGui::InputText("Model Path", modelPath, 512);
            static char vertPath[512] = "";
            ImGui::InputText("Vert Shader Path", vertPath, 512);
            static char fragPath[512] = "";
            ImGui::InputText("Frag Shader Path", fragPath, 512);
            if (ImGui::Button("OK", ImVec2(120, 0)))
            {
                Engine->GetWorld()->LoadObject(modelPath, vertPath, fragPath);
                ImGui::CloseCurrentPopup();
            }
            if (ImGui::Button("Cancel", ImVec2(120, 0)))
            {
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }

        scene->Render(context);
        inspector->Render(context);
    }
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}
