#include "modules/Metronome.hpp"

// Special
Metronome::Metronome() {};

// Fetches
int Metronome::getBpm() { return bpm; };
float Metronome::getBeatDurationMs() { return beatDurationMs; };
int Metronome::getLastBeat() { return lastBeat; };
float Metronome::getNextBeatPosition() { return nextBeatPosition; };

// Actions

void Metronome::setSongBpm(int bpm_) {
  bpm = bpm_;
  beatDurationMs = (60.0f / bpm) * 1000.0f;
};

void Metronome::startMetronome() {
  float beatDurationMs = (60.0f / bpm) * 1000.0f;
  int lastBeat = 0;
  float nextBeatPosition = beatDurationMs;
};

void Metronome::stopMetronome() { // lwk does nothing jst for vibes
  int lastBeat = 0;
  float nextBeatPosition = beatDurationMs;
}

int Metronome::update(float currentTimePositionMs) { // call each frame, updates
                                                     // beat and returns beat #
  if (currentTimePositionMs >= nextBeatPosition) {
    lastBeat += 1;
    nextBeatPosition += beatDurationMs;
    return lastBeat;
  }
  return lastBeat;
};