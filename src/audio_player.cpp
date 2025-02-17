#include "audio_player.h"
#include <iostream>

bool AudioPlayer::Init() {
    av_register_all();
    avformat_network_init();
    return true;
}

void AudioPlayer::Play() {
    std::cout << "Reproduciendo..." << std::endl;
    // Implementar reproducción de audio usando FFmpeg
}

void AudioPlayer::Stop() {
    std::cout << "Detenido." << std::endl;
    // Detener la reproducción de audio
}

void AudioPlayer::SeekForward() {
    std::cout << "Adelantar." << std::endl;
    // Implementar adelantar
}

void AudioPlayer::SeekBackward() {
    std::cout << "Retroceder." << std::endl;
    // Implementar retroceder
}

void AudioPlayer::LoadAudio(const std::string& filePath) {
    std::cout << "Cargando archivo: " << filePath << std::endl;
    // Implementar la carga del archivo de audio con FFmpeg
}

void AudioPlayer::Close() {
    std::cout << "Cerrando..." << std::endl;
    // Liberar los recursos de FFmpeg
}
