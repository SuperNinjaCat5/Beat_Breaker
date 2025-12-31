#include "modules/Composer.hpp"
#include "modules/Display.hpp"
#include "modules/Judge.hpp"
#include "modules/Metronome.hpp"
#include "modules/MusicPlayer.hpp"
#include "modules/Referee.hpp"
#include "scenes/StartMenu.hpp"
#include <iostream>
#include <raylib.h>

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

  // Display
  Display display;

  StartMenu startMenu;

  // ########## Setup ##########

  referee.setLevel(LEVELS::LEVEL_TEMP);

  referee.startLevel(&musicPlayer, &metronome, &composer, &judge, &display);

  // #####################################
  // Main loop
  // #####################################

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    // #####################################
    // START MENU
    // #####################################

    if (!startMenu.getStartedGame()) {
      std::string startAction = startMenu.update();

      startMenu.draw();

      ClearBackground(BLACK);

      if (startAction == "Start Game") {
        EndDrawing();
        continue;
      }

      if (startAction == "Exit") {
        break;
      }

      if (startAction == "Settings") {
        EndDrawing();
        continue;
      }

      if (startAction == "None") {
        EndDrawing();
        continue;
      }
    }

    // #####################################
    // LEVEL SELECTION
    // #####################################

    // #####################################
    // LEVEL
    // #####################################

    // #####################################
    // GAME OVER
    // #####################################

    // ########## Logic ##########

    musicPlayer.update();

    metronome.update(musicPlayer.getTimePositionMs());

    judge.update(metronome.getLastBeat());

    bool passed = judge.judgeJuryEXECUTIONER(&metronome);

    if (passed) {
      std::cout << "I AM THE EYE THE TIGERRRR THRILL OF DA FIGHT" << "\n";
    }

    display.markJudgement(passed, 3);

    bool stillAlive = referee.update(passed, metronome.getActiveBeat());
    if (!stillAlive) {
      break;
    };

    display.update(&metronome);

    // ########## Display ##########

    display.drawJudgementLine();
    display.makeBeatLines(&metronome);

    EndDrawing();
  }

  // #####################################
  // Shutdown
  // #####################################

  referee.stopLevel(&musicPlayer, &metronome);

  // Windows

  CloseWindow();
}