#include "raylib.h"

int main() {
  InitWindow(800, 600, "Beat Breaker");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();
}