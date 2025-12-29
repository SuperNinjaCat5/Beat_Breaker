#pragma once

class Metronome {
private:
  int bpm = 120;
  float beatDurationMs = (60.0f / bpm) * 1000.0f;
  int lastBeat = 0;
  float nextBeatPosition = beatDurationMs;

public:
  // Special
  Metronome();

  // Fetches
  int getBpm();
  float getBeatDurationMs();
  int getLastBeat();
  float getNextBeatPosition();

  // Actions
  void setSongBpm(int bpm);
  void startMetronome();
  void stopMetronome();
  int update(float currentTimePositionMs);
};