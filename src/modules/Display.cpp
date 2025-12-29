#include "modules/Display.hpp"
#include <raylib.h>

// Speical
Display::Display() {}; // Consturctor

// Fetch
int Display::getScreenWidth() { return screenWidth; }
int Display::getScreenHeight() { return screenHeight; }

// Actions ##############################
void Display::update() {
  screenWidth = GetScreenWidth();
  screenHeight = GetScreenHeight();
};

// Draws
void Display::drawJudgementLine() {
  DrawLine(100, 0, 100, screenHeight, PURPLE); // JUDGEMENT LINE
};

void Display::makeBeatLines() {
  for (int i = 1; i <= 7; i++) {
    DrawLine(((i * 100) + 100), 0, ((i * 100) + 100), screenHeight, BLUE);
  }
};