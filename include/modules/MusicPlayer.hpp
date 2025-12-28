#pragma once
#include "raylib.h"

class MusicPlayer {
private:
  float timePositionMs;
  Music *currentSong = nullptr;

public:
  bool hasSong = false;
  bool songPlaying = false;

  // Special
  MusicPlayer(); // Constructor
  bool assertSong();

  // Fetches
  float getTimePositionMs();
  Music *getCurrentSong();

  // Actions
  void startPlayer();
  void startPlayer(Music *song_);
  void stopPlayer();
  void switchSong(Music *newSong);

  // Main
  void update();
};