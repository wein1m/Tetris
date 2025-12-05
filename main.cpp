#include <raylib.h>

int main() {
  Color darkBlue = {44, 44, 127, 255};
  int screenW = 300;
  int screenH = 600;
  InitWindow(screenW, screenH, "Tetoriss~");
  SetTargetFPS(45);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
