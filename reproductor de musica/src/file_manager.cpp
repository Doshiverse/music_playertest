#include "file_manager.h"
#include <iostream>

void FileManager::Init() {
    std::cout << "File Manager Inicializado" << std::endl;
}

void FileManager::LoadAudio(const std::string& filePath) {
    std::cout << "Archivo de audio cargado: " << filePath << std::endl;
    // Llamar a AudioPlayer para cargar y reproducir el archivo
}
