#include "modules/Referee.hpp"
#include "modules/Composer.hpp"
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
Referee::Referee() {}; // Constructor

// Fetches
Level Referee::getCurrentLevel() { return currentLevel; };

bool Referee::getHasLevel() { return hasLevel; };

bool Referee::getLevelStarted() { return levelStarted; };

// Actions

void Referee::setLevel(Level level) {
  currentLevel = level;
  hasLevel = true;
};

void Referee::startLevel(MusicPlayer *musicPlayer_, Metronome *metronome_,
                         Composer *composer_, Judge *judge_) {
  if (!hasLevel) {
    std::cerr << "Referee could not start Level, set it first!";
    return;
  };

  // Load chart
  composer_->loadChart(currentLevel.chartPath);

  // Set music
  Music song = LoadMusicStream(composer_->getCurrentChart().songPath.c_str());
  musicPlayer_->switchSong(song);

  // Set metronome
  metronome_->setSongBpm(composer_->getCurrentChart().bpm);

  // Set judge
  judge_->setChart(&(*composer_));

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
};