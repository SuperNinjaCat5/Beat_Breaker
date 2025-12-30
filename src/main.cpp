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

    bool spacePressed = IsKeyPressed(KEY_SPACE);
    bool inputJudged = false;
    bool passed =
        judge.judgeJuryEXECUTIONER(&metronome, spacePressed, inputJudged);

    std::cout << referee.getLivesLeft() << "\n";

    if (!referee.update(passed, judge.getCurrentGoalBeat(),
                        metronome.getActiveBeat(), metronome.getLastBeat(),
                        inputJudged)) {
      break;
    };

    display.update(&metronome);

    // ########## Display ##########

    ClearBackground(BLACK);

    display.drawJudgementLine();
    display.makeBeatLines(&metronome, passed);

    EndDrawing();
  }

  // #####################################
  // Shutdown
  // #####################################

  referee.stopLevel(&musicPlayer, &metronome);

  // Windows

  CloseWindow();
}