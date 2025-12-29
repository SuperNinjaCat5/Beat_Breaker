#include "modules/Metronome.hpp"

// Special
Metronome::Metronome() {};

// Fetches
int Metronome::getBpm() { return bpm; };
float Metronome::getBeatDurationMs() { return beatDurationMs; };

float Metronome::getNextBeatPosition() { return nextBeatPosition; };

int Metronome::getLastBeat() { return lastBeat; };
int Metronome::getMarginMs() { return marginMs; };

int Metronome::getActiveBeat() { return activeBeat; }; // USE THIS FOR CHECKS
float Metronome::getActiveBeatStartPosition() {
  return activeBeatStartPosition;
};
float Metronome::getActiveBeatEndPosition() { return activeBeatEndPosition; };

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

void Metronome::update(
    float currentTimePositionMs) { // call each frame, updates beat
  while (currentTimePositionMs >= nextBeatPosition) {
    lastBeat++;
    nextBeatPosition += beatDurationMs;
  }

  float beatTime = lastBeat * beatDurationMs;
  activeBeatStartPosition = beatTime - marginMs;
  activeBeatEndPosition = beatTime + marginMs;

  if (activeBeatEndPosition >= currentTimePositionMs &&
      currentTimePositionMs >= activeBeatStartPosition) {
    activeBeat = lastBeat;
  } else {
    activeBeat = -1;
  };
}
