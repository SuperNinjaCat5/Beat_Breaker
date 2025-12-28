#include "modules\MusicPlayer.hpp"
#include "raylib.h"
#include <iostream>

MusicPlayer::MusicPlayer() {}

void MusicPlayer::startPlayer() {
  if (hasSong) {
    startPlayer(currentSong);
  } else {
    std::cerr
        << "Music player was started with a given song or current song to play";
  }
}

void MusicPlayer::startPlayer(Music &song_) {
  hasSong = true;

  currentSong = song_;

  PlayMusicStream(currentSong);
}

void 