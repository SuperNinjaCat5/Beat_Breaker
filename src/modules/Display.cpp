#include "modules/Display.hpp"
#include "modules/Composer.hpp"
#include "modules/Metronome.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

// Speical
Display::Display() {}; // Consturctor

// Fetch
int Display::getScreenWidth() { return screenWidth; }
int Display::getScreenHeight() { return screenHeight; }
Chart Display::getCurrentChart() { return currentChart; };
std::array<Beatline, 8> &Display::getUpcomingBeats() { return upcomingBeats; };

// Actions ##############################
void Display::update(Metronome *metronome_,
                     float currentMusicTimeMs) { // STILL CRAP REDO!!!!
  screenWidth = GetScreenWidth();
  screenHeight = GetScreenHeight();

  currentJudgementLineBeat = metronome_->getLastBeat();

  float beatDuration = metronome_->getBeatDurationMs();
  float lastBeatTime = metronome_->getLastBeat() * beatDuration;
  beatProgress = (currentMusicTimeMs - lastBeatTime) / beatDuration;

  if (beatProgress < 0.0f)
    beatProgress = 0.0f;
  if (beatProgress > 1.0f)
    beatProgress = 1.0f;

  for (int i = 0; i <= 7; i++) {
    Beatline beatline;

    beatline.hasBeat = false;
    beatline.displayPosition = i + 1;

    int targetBeat = currentJudgementLineBeat + i;

    if (i == 0) {
      int activeBeat = metronome_->getActiveBeat();
      if (activeBeat != -1) {
        for (const auto &note : currentChart.notes) {
          if (note.beat == activeBeat) {
            beatline.hasBeat = true;
            break;
          }
        }
      }
    } else {
      for (const auto &note : currentChart.notes) {
        if (note.beat == targetBeat) {
          beatline.hasBeat = true;
          break;
        }
      }
    }

    upcomingBeats.at(i) = beatline;
  };
};

void Display::setChart(Composer *composer_) {
  currentChart = composer_->getCurrentChart();
};

// Draws
void Display::drawJudgementLine() {
  DrawLine(100, 0, 100, screenHeight, PURPLE); // JUDGEMENT LINE
};

void Display::makeBeatLines(Metronome *metronome_) {
  int judgementX = 100;
  int spacingBetweenLines = 100;

  for (auto &line : upcomingBeats) {
    if (line.hasBeat == true) {
      int xPos = line.displayPosition * 100;

      DrawCircle(xPos, 300, 50, BLUE);
    }
  };
}