#pragma once

#include <SDL.h>
#include <GL/glew.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>

class ImGuiRenderer {
public:
    // Inicializa ImGui
    bool Init(SDL_Window* window, SDL_GLContext glContext);
    
    // Limpia los recursos de ImGui
    void Shutdown();
    
    // Configura la interfaz de usuario y renderiza
    void Render();
};
