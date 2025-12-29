#pragma once
#include <raylib.h>

class Display {
private:
  int screenWidth;
  int screenHeight;

public:
  // Special
  Display(); // Constructor

  // Fetch
  int getScreenWidth();
  int getScreenHeight();

  // Actions ##############################
  void update();

  // Draws
  void drawJudgementLine();
  void makeBeatLines();
};

struct Beatline {
  int position; // 1-8 (1 judgment, 8 entrance)
};