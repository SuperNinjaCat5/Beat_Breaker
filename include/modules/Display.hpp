#pragma once
#include "modules/Composer.hpp"
#include "modules/Metronome.hpp"
#include <array>
#include <raylib.h>

struct Beatline {
  int displayPosition; // -3 to 8 (-3=passed, 0=judgment, 8=entrance)
  bool hasBeat = false;
};

class Display {
private:
  int screenWidth;
  int screenHeight;
  int currentJudgementLineBeat;
  std::array<Beatline, 12> upcomingBeats;
  Chart currentChart;

public:
  // Special
  Display(); // Constructor

  // Fetch
  int getScreenWidth();
  int getScreenHeight();
  Chart getCurrentChart();
  std::array<Beatline, 12> &getUpcomingBeats();

  // Actions ##############################
  void update(Metronome *metronome_);
  void setChart(Composer *composer_);

  // Draws
  void drawJudgementLine();
  void makeBeatLines(Metronome *metronome_, bool passed);
};
