#include "modules/Judge.hpp"
#include "modules/Composer.hpp"
#include "modules/Metronome.hpp"
#include <raylib.h>

// Special
Judge::Judge() {}; // Constructor

// Fetch
Chart Judge::getCurrentChart() { return currentChart; };
int Judge::getCurrentGoalBeat() { return currentGoalBeat; };

// Actions

void Judge::setChart(Composer *composer_) {
  currentChart = composer_->getCurrentChart();
};

bool Judge::judgeJuryEXECUTIONER(Metronome *metronome) {
  int activeBeat = metronome->getActiveBeat();

  if (currentGoalBeat == -1) {
    return true;
  };

  if (IsKeyPressed(KEY_SPACE)) {
    return activeBeat == currentGoalBeat;
  };

  if (activeBeat == currentGoalBeat) {
    return false;
  }

  return true;
}

void Judge::update(int lastbeat) {
  for (auto &note : currentChart.notes) {
    if (note.beat >= lastbeat) {
      currentGoalBeat = note.beat;
      return;
    }
  };
  currentGoalBeat = -1; // god please no
};