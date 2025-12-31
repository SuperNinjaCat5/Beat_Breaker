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

Chart Display::getCurrentChart() { return currentChart; }

std::array<Beatline, 12> &Display::getUpcomingBeats() { return upcomingBeats; }

// Actions ##############################
void Display::update(
    Metronome *metronome_) { // DISPLAY WORKS!! BUT JUDGEMENT IS COOKED FIXXXX
  screenWidth = GetScreenWidth();
  screenHeight = GetScreenHeight();

  currentJudgementLineBeat = metronome_->getLastBeat();

  for (int i = -3; i <= 8; i++) {
    Beatline beatline{};
    beatline.displayPosition = i;

    int targetBeat = metronome_->getLastBeat() + i;

    for (const auto &note : currentChart.notes) {
      if (note.beat == targetBeat) {
        beatline.hasBeat = true;
        break;
      }
    }

    upcomingBeats.at(i + 3) = beatline; // shoudl shfit index: -3 -> 0, 8 -> 11
  }
};

void Display::setChart(Composer *composer_) {
  currentChart = composer_->getCurrentChart();
};

// Draws
void Display::drawJudgementLine() {
  DrawLine(200, 0, 200, screenHeight, PURPLE); // JUDGEMENT LINE
};

void Display::makeBeatLines(Metronome *metronome_) {
  int judgementX = 200;
  int spacing = 100;

  for (const auto &line : upcomingBeats) {
    if (!line.hasBeat) {
      continue;
    }

    // Position 0 = judgment line, negative = left of judgment, positive = right
    int xPos = judgementX + (line.displayPosition * spacing);

    DrawCircle(xPos, 300, 50, BLUE);
  }
}