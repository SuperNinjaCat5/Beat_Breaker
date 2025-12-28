#include "modules\MusicPlayer.hpp"
#include "raylib.h"
#include <iostream>

// Special
MusicPlayer::MusicPlayer() {}; // Constructor
bool MusicPlayer::assertSong() {
  if (hasSong) {
    return true;
  } else {
    std::cerr << "Music player function was called without a given song or "
                 "current song to play";
    return false;
  }
};

// Fetches
float MusicPlayer::getTimePositionMs() {

  assertSong();

  float timePositionSec = GetMusicTimePlayed(currentSong);

  float timePositionMs = timePositionSec / 1000.0f;

  return timePositionMs;
};

Music MusicPlayer::getCurrentSong() {
  assertSong();
  return currentSong;
};

// Actions
void MusicPlayer::startPlayer() {

  assertSong();

  startPlayer(currentSong);
}

void MusicPlayer::startPlayer(Music &song_) {
  currentSong = song_;

  hasSong = true;
  songPlaying = true;

  PlayMusicStream(currentSong);
}

void MusicPlayer::stopPlayer() {

  assertSong();

  songPlaying = false;

  StopMusicStream(currentSong);
}

void MusicPlayer::switchSong(Music &newSong) {
  currentSong = newSong;
  hasSong = true;
};

// Main
void MusicPlayer::update() { // Should be called once per frame
  assertSong();
  timePositionMs = getTimePositionMs();
};