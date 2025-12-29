#include "modules/Composer.hpp"
#include "modules/Judge.hpp"
#include "modules/Metronome.hpp"
#include "modules/MusicPlayer.hpp"
#include "modules/Referee.hpp"
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

  // Referee
  Referee referee;

  // Composer
  Composer composer;

  // Music
  MusicPlayer musicPlayer;

  // Metronome
  Metronome metronome;

  // Judge (jury executioner FROM MARVEL RIVALSSSSSSSSSSSSSSS)
  Judge judge;

  // ########## Setup ##########

  referee.setLevel(LEVELS::LEVEL_TEMP);

  referee.startLevel(&musicPlayer, &metronome, &composer, &judge);

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

    // ########## Display ##########

    ClearBackground(BLACK);

    EndDrawing();
  }

  // #####################################
  // Shutdown
  // #####################################

  referee.stopLevel(&musicPlayer, &metronome);

  // Windows

  CloseWindow();
}