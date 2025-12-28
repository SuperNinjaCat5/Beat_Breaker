#include "modules/MusicPlayer.hpp"
#include "raylib.h"
#include <iostream>

int main() {
  InitWindow(800, 600, "Beat Breaker");
  InitAudioDevice();
  SetTargetFPS(60);

  MusicPlayer musicPlayer;

  Music temp_song =
      LoadMusicStream("C:/Users/benel/dev/game/Beat_Breaker/assets/audio/"
                      "But-First-A-Word-from-our.mp3");

  musicPlayer.switchSong(&temp_song);

  musicPlayer.startPlayer();

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    musicPlayer.update();
    std::cout << musicPlayer.getTimePositionMs() << "\n";

    EndDrawing();
  }

  musicPlayer.stopPlayer();
  UnloadMusicStream(temp_song);

  CloseWindow();
}