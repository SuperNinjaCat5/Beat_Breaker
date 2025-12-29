#include "modules/Display.hpp"
#include "modules/Composer.hpp"
#include "modules/Metronome.hpp"
#include <array>
#include <raylib.h>

// Speical
Display::Display() {}; // Consturctor

// Fetch
int Display::getScreenWidth() { return screenWidth; }
int Display::getScreenHeight() { return screenHeight; }
Chart Display::getCurrentChart() { return currentChart; };
std::array<Beatline, 8> &Display::getUpcomingBeats() { return upcomingBeats; };

// Actions ##############################
void Display::update(Metronome *metronome_) {
  screenWidth = GetScreenWidth();
  screenHeight = GetScreenHeight();

  currentJudgementLineBeat = metronome_->getLastBeat();

  for (int i = 0; i <= 7; i++) {
    Beatline beatline;
    if ((currentJudgementLineBeat + i) < currentChart.notes.size()) {
      if (currentChart.notes.at(currentJudgementLineBeat + i).beat != -1) {
        beatline.hasBeat = true;
      };
    };
    beatline.displayPosition = i + 1;
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

void Display::makeBeatLines(Metronome *metronome_) { // redo later BROKENNNN
  int judgementX = 100;
  float speed = 200.0f;
  for (int i = 0; i < 8; i++) {
    if (!upcomingBeats.at(i).hasBeat)
      continue;

    int beatIndex = currentJudgementLineBeat + i;
    if (beatIndex >= currentChart.notes.size())
      continue;

    float beatTimeMs =
        currentChart.notes.at(beatIndex).beat * metronome_->getBeatDurationMs();

    float currentTimeMs =
        metronome_->getLastBeat() * metronome_->getBeatDurationMs();

    float timeUntilBeatMs = beatTimeMs - currentTimeMs;

    int xPos = judgementX + timeUntilBeatMs * speed / 1000.0f;

    DrawCircle(xPos, 300, 50, BLUE);
  }
}