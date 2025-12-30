#pragma once
#include "modules/Composer.hpp"
#include "modules/Metronome.hpp"
#include <raylib.h>

class Judge {
private:
  Chart currentChart;
  int currentGoalBeat;

public:
  // Special
  Judge(); // Constructor

  // Fetch
  Chart getCurrentChart();
  int getCurrentGoalBeat();

  // Actions
  void setChart(Composer *composer_);
  void update(int lastbeat);
  bool judgeJuryEXECUTIONER(Metronome *metronome, bool spacePressed,
                            bool &inputJudged);
};