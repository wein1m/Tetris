#include "blocks.cpp"
#include "grid.h"
#include <raylib.h>

int main() {
  Color darkBlue = {44, 44, 127, 255};
  int screenW = 300;
  int screenH = 600;
  InitWindow(screenW, screenH, "Tetoriss~");
  SetTargetFPS(45);

  Grid grid = Grid();
  grid.Print();

  ZBlock block1 = ZBlock();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);
    grid.Draw();
    block1.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
