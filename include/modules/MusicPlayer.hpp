#pragma once
#include "raylib.h"

class MusicPlayer {
private:
  float timePositionMs;
  bool hasSong = false;

public:
  Music currentSong;

  MusicPlayer(); // Constructor

  // Fetches
  float getTimePositionMs();

  // Actions
  void startPlayer();
  void startPlayer(Music &song_);
  void switchSong(Music &newSong);
};