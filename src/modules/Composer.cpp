#include "modules/Composer.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

// Special
Composer::Composer() {}; // Constructor

// Fetches
Chart Composer::getCurrentChart() { return currentChart; };

// Actions
void Composer::loadChart(const std::string path) { // load chart from file
  Chart chart;
  chart.chartPath = path;

  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open chart");
  }

  json j;
  file >> j;

  chart.bpm = j["bpm"];
  chart.songPath = j["songPath"];

  for (auto &n : j["notes"]) {
    Note note;

    note.beat = n["beat"];
    note.subBeat = n["subBeat"];

    chart.notes.push_back(note);
  };

  currentChart = chart;
};

Chart makeChart(const std::string path) { // make a chart struct from json
  Chart chart;
  chart.chartPath = path;

  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open chart");
  }

  json j;
  file >> j;

  chart.bpm = j["bpm"];
  chart.songPath = j["songPath"];

  for (auto &n : j["notes"]) {
    Note note;

    note.beat = n["beat"];
    note.subBeat = n["subBeat"];

    chart.notes.push_back(note);
  };

  return chart;
};
