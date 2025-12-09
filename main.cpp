#include "game.h"
#include <cstdlib>
#include <ctime>
#include <raylib.h>

int main() {
  // generate random seed to ensure rand() is random on every run
  std::srand(std::time(nullptr));
  Color darkBlue = {44, 44, 127, 255};
  int screenW = 300;
  int screenH = 600;
  InitWindow(screenW, screenH, "Tetoriss~");
  SetTargetFPS(45);

  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);

    game.Draw();
    game.HandleInput();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
