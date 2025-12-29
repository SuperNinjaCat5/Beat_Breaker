#include "modules/Metronome.hpp"
#include "modules/MusicPlayer.hpp"
#include "raylib.h"
#include <iostream>

int main() {

  // #####################################
  // Setup
  // #####################################

  // Window

  InitWindow(800, 600, "Beat Breaker");
  InitAudioDevice();
  SetTargetFPS(60);

  // Music

  MusicPlayer musicPlayer;

  Music temp_song =
      LoadMusicStream("C:/Users/benel/dev/game/Beat_Breaker/assets/audio/"
                      "But-First-A-Word-from-our.mp3");

  musicPlayer.switchSong(&temp_song);

  musicPlayer.startPlayer();

  // Metronome

  Metronome metronome;

  metronome.setSongBpm(120);

  metronome.startMetronome();

  // #####################################
  // Main loop
  // #####################################

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    musicPlayer.update();

    metronome.update(musicPlayer.getTimePositionMs());

    std::cout << metronome.getLastBeat() << "\n";

    EndDrawing();
  }

  // #####################################
  // Shutdown
  // #####################################

  /// Music

  musicPlayer.stopPlayer();
  UnloadMusicStream(temp_song);

  // Metronome

  metronome.stopMetronome();

  // Windows

  CloseWindow();
}