#include "modules/Composer.hpp"
#include "modules/Judge.hpp"
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

  // Composer

  Composer composer;

  composer.loadChart("levels/level_temp/chart.json");

  // Music

  MusicPlayer musicPlayer;

  Music temp_song =
      LoadMusicStream(composer.getCurrentChart().songPath.c_str());

  musicPlayer.switchSong(&temp_song);

  musicPlayer.startPlayer();

  // Metronome

  Metronome metronome;

  metronome.setSongBpm(composer.getCurrentChart().bpm);

  metronome.startMetronome();

  // Judge (jury executioner FROM MARVEL RIVALSSSSSSSSSSSSSSS)

  Judge judge;

  judge.setChart(&composer);

  // #####################################
  // Main loop
  // #####################################

  while (!WindowShouldClose()) {
    BeginDrawing();

    // ########## Logic ##########

    musicPlayer.update();

    metronome.update(musicPlayer.getTimePositionMs());

    judge.update(metronome.getLastBeat());

    bool passed = judge.judgeJuryEXECUTIONER(&metronome);

    std::cout << passed << "\n";

    // ########## Display ##########

    ClearBackground(BLACK);

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