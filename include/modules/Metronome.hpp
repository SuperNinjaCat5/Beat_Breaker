#pragma once

class Metronome {
private:
  int bpm = 120;
  float beatDurationMs = (60.0f / bpm) * 1000.0f;

  float nextBeatPosition = beatDurationMs;

  int lastBeat = 0;
  int marginMs = 80;

  int activeBeat = -1; // Open during the timeframe for beat
  float activeBeatStartPosition = nextBeatPosition - marginMs;
  float activeBeatEndPosition = nextBeatPosition + marginMs;

public:
  // Special
  Metronome();

  // Fetches
  int getBpm();
  float getBeatDurationMs();

  float getNextBeatPosition();

  int getLastBeat();
  int getMarginMs();

  int getActiveBeat();
  float getActiveBeatStartPosition();
  float getActiveBeatEndPosition();

  // Actions
  void setSongBpm(int bpm);
  void startMetronome();
  void stopMetronome();
  void update(float currentTimePositionMs);
};