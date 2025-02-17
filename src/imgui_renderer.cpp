#include "imgui_renderer.h"

bool ImGuiRenderer::Init(SDL_Window* window, SDL_GLContext glContext) {
    // Inicializar el contexto de ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Configuración de ImGui (puedes personalizar esto según sea necesario)
    ImGui::StyleColorsDark();

    // Configurar SDL2 para usar ImGui
    ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    
    // Configurar OpenGL3 para usar ImGui
    ImGui_ImplOpenGL3_Init("#version 130");

    return true;
}

void ImGuiRenderer::Shutdown() {
    // Limpiar los recursos de ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiRenderer::Render() {
    // Llamamos a las funciones para preparar y renderizar la interfaz gráfica
    ImGui_ImplSDL2_NewFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();
    
    // Aquí iría tu código para construir la interfaz (ya lo hemos visto en `main.cpp`)

    ImGui::Render();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
