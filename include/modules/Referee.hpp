#pragma once
#include "modules/Composer.hpp"
#include "modules/Judge.hpp"
#include "modules/Metronome.hpp"
#include "modules/MusicPlayer.hpp"
#include <string>
#include <vector>

struct Level {
  std::string levelName;
  std::string chartPath;

  Level();
  Level(std::string levelName_, std::string chartPath_);
};

namespace LEVELS {
extern Level LEVEL_TEMP;

extern std::vector<Level> LEVEL_LIST;
} // namespace LEVELS

class Referee {
private:
  Level currentLevel;
  bool hasLevel;
  bool levelStarted;

  // Player properties
  int livesLeft = 5;
  int score = 0;

public:
  // Special
  Referee(); // Constructor

  // Fetches
  Level getCurrentLevel();
  bool getHasLevel();
  bool getLevelStarted();

  // Actions
  void setLevel(Level level);
  void startLevel(MusicPlayer *musicPlayer_, Metronome *metronome_,
                  Composer *composer_, Judge *judge_);
  void stopLevel(MusicPlayer *musicPlayer_, Metronome *metronome_);
  bool update(bool &passed);
};
