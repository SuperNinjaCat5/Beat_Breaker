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

bool Judge::judgeJuryEXECUTIONER(Metronome *metronome, bool spacePressed,
                                 bool &inputJudged) {
  inputJudged = false;

  if (spacePressed) {
    inputJudged = true;

    if (currentGoalBeat == -1) { // If space w/ no note fail
      return false;
    }

    if (currentGoalBeat == metronome->getActiveBeat()) { // if space & note pass
      return true;
    } else {
      return false;
    }
  } else {
    if (currentGoalBeat == metronome->getActiveBeat()) { // no space but note
      inputJudged = true;
      return false;
    }
  };

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