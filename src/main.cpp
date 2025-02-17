#include <SDL.h>
#include <GL/glew.h>
#include <imgui.h>
#include <SDL_opengl.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

#include "audio_player.h"
#include "spectrum_analyzer.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include "file_manager.h"

// Globales
SDL_Window* window;
SDL_GLContext glContext;
AudioPlayer audioPlayer;
SpectrumAnalyzer spectrumAnalyzer;
FileManager fileManager;

bool InitSDL2() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Music Player", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        return false;
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        SDL_Log("SDL_GL_CreateContext Error: %s", SDL_GetError());
        return false;
    }

    if (glewInit() != GLEW_OK) {
        SDL_Log("GLEW Initialization failed");
        return false;
    }

    return true;
}

void RenderUI() {
    ImGui_ImplSDL2_NewFrame(window);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Music Player");
    
    // Arrastrar y soltar archivos
    if (ImGui::BeginDragDropTarget()) {
        if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("FILE_PATH")) {
            std::string filePath = (const char*)payload->Data;
            fileManager.LoadAudio(filePath);
        }
        ImGui::EndDragDropTarget();
    }

    // Controles de audio
    if (ImGui::Button("Play")) {
        audioPlayer.Play();
    }
    if (ImGui::Button("Stop")) {
        audioPlayer.Stop();
    }
    if (ImGui::Button("Forward")) {
        audioPlayer.SeekForward();
    }
    if (ImGui::Button("Backward")) {
        audioPlayer.SeekBackward();
    }

    // Análisis de espectro
    spectrumAnalyzer.Render();

    ImGui::End();

    ImGui::Render();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    SDL_GL_SwapWindow(window);
}

int main(int argc, char** argv) {
    if (!InitSDL2()) {
        return -1;
    }

    audioPlayer.Init();
    spectrumAnalyzer.Init();
    fileManager.Init();

    ImGuiRenderer imguiRenderer;
    imguiRenderer.Init();

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        RenderUI();
        SDL_Delay(16);  // ~60 FPS
    }

    audioPlayer.Close();
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
