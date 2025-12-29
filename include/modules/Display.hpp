#pragma once
#include "modules/Composer.hpp"
#include "modules/Metronome.hpp"
#include <array>
#include <raylib.h>

struct Beatline {
  int displayPosition; // 1-8 (1 judgment, 8 entrance)
  bool hasBeat;
};

class Display {
private:
  int screenWidth;
  int screenHeight;
  int currentJudgementLineBeat;
  std::array<Beatline, 8> upcomingBeats;
  Chart currentChart;

public:
  // Special
  Display(); // Constructor

  // Fetch
  int getScreenWidth();
  int getScreenHeight();
  Chart getCurrentChart();
  std::array<Beatline, 8> &getUpcomingBeats();

  // Actions ##############################
  void update(Metronome *metronome_);
  void setChart(Composer *composer_);

  // Draws
  void drawJudgementLine();
  void makeBeatLines(Metronome *metronome_);
};
