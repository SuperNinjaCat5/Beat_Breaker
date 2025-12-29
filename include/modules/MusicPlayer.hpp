#pragma once
#include "raylib.h"

class MusicPlayer {
private:
  float timePositionMs;
  Music *currentSong = nullptr;
  bool hasSong = false;
  bool songPlaying = false;

public:
  // Special
  MusicPlayer(); // Constructor
  bool assertSong();

  // Fetches
  float getTimePositionMs();
  Music *getCurrentSong();
  bool getHasSong();
  bool getSongPlaying();

  // Actions
  void startPlayer();
  void startPlayer(Music *song_);
  void stopPlayer();
  void switchSong(Music *newSong);

  // Main
  void update();
};