#pragma once
#include <raylib.h>

/*    DrawLine(100, 0, 100, screenHeight, PURPLE); // JUDGEMENT LINE
    for (int i = 1; i <= 7; i++) {
      DrawLine(((i * 100) + 100), 0, ((i * 100) + 100), screenHeight, BLUE);
    }*/

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
}