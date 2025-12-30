#include "modules/Referee.hpp"
#include "modules/Composer.hpp"
#include "modules/Display.hpp"
#include "modules/Judge.hpp"
#include "modules/Metronome.hpp"
#include "modules/MusicPlayer.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

// lvl ##########
Level::Level() {};
Level::Level(std::string levelName_, std::string chartPath_)
    : levelName(levelName_), chartPath(chartPath_) {};

namespace LEVELS {
Level LEVEL_TEMP("But First, A Word from our Sponsors...",
                 "levels/level_temp/chart.json");

std::vector<Level> LEVEL_LIST = {LEVEL_TEMP};
} // namespace LEVELS

// ##########

// Speical
Referee::Referee()
    : hasLevel(false), levelStarted(false), lastBeatTouched(-1) {};

// Fetches
Level Referee::getCurrentLevel() { return currentLevel; };

bool Referee::getHasLevel() { return hasLevel; };

bool Referee::getLevelStarted() { return levelStarted; };

int Referee::getLastBeatTouched() { return lastBeatTouched; };

int Referee::getLivesLeft() { return livesLeft; };

int Referee::getScore() { return score; };

// Actions

void Referee::setLevel(Level level) {
  currentLevel = level;
  hasLevel = true;
};

void Referee::startLevel(MusicPlayer *musicPlayer_, Metronome *metronome_,
                         Composer *composer_, Judge *judge_,
                         Display *display_) {
  if (!hasLevel) {
    std::cerr << "Referee could not start Level, set it first!";
    return;
  };

  // Set game

  livesLeft = 5;
  score = 0;
  lastBeatTouched = -1;
  levelStarted = true;

  // Load chart
  composer_->loadChart(currentLevel.chartPath);

  // Set music
  Music song = LoadMusicStream(composer_->getCurrentChart().songPath.c_str());
  musicPlayer_->switchSong(song);

  // Set metronome
  metronome_->setSongBpm(composer_->getCurrentChart().bpm);

  // Set judge
  judge_->setChart(&(*composer_));

  // Set display

  display_->setChart(composer_);

  // Start
  musicPlayer_->startPlayer();
  metronome_->startMetronome();
};

void Referee::stopLevel(MusicPlayer *musicPlayer_, Metronome *metronome_) {
  /// Music

  musicPlayer_->stopPlayer();
  UnloadMusicStream(musicPlayer_->getCurrentSong());

  // Metronome

  metronome_->stopMetronome();

  levelStarted = false;
};

bool Referee::update(bool &passed, int currentGoalBeat_, int activeBeat_,
                     int lastBeat_, bool inputJudged) {
  if (currentGoalBeat_ == -1) {
    return true;
  }
  if (!inputJudged) {
    return livesLeft > 0;
  }

  int beatToMark = (activeBeat_ != -1) ? activeBeat_ : lastBeat_;

  if (beatToMark != lastBeatTouched) {
    lastBeatTouched = beatToMark;

    if (!passed) {
      livesLeft--;
      if (livesLeft < 0)
        livesLeft = 0;
    } else {
      score++;
    }
  }

  return livesLeft > 0;
}