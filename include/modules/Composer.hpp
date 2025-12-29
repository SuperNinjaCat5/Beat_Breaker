#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

class Composer {
private:
  Chart currentChart;

public:
  // Special
  Composer(); // Constructor

  // Fetches
  Chart getCurrentChart();

  // Actions
  void loadChart(const std::string path);
};

Chart makeChart(const std::string path);

struct Note {
  int beat;
  int subBeat;
};

struct Chart {
  int bpm;
  std::string chartPath = "";
  std::string songPath = "";
  std::vector<Note> notes;
};