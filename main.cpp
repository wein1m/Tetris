#include "colors.h"
#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <raylib.h>

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
  if (GetTime() - lastUpdateTime >= interval) {
    lastUpdateTime = GetTime();
    return true;
  }
  return false;
}

int main() {
  // generate random seed to ensure rand() is random on every run
  std::srand((unsigned int)std::time(nullptr));
  int screenW = 500;
  int screenH = 620;
  InitWindow(screenW, screenH, "Tetoriss~");
  SetTargetFPS(45);

  Font fontMonogram = LoadFontEx("font/monogram.ttf", 64, 0, 0);

  Game game = Game();
  Grid grid = Grid();

  while (!WindowShouldClose()) {
    // delay when switching to next block (after prev block hit bottom)
    if (game.state == Game::SPAWN_DELAY) {
      if (GetTime() - game.spawnDelayStart >= 0.5) {
        game.state = Game::PLAYING;
      } else {
        continue;
      }
    }

    BeginDrawing();
    ClearBackground(darkBlue);

    DrawTextEx(fontMonogram, "SCORE", {355, 15}, 38, 2, WHITE);
    DrawRectangleRounded({320, 55, 170, 60}, 0.3f, 6, lightBlue);

    DrawTextEx(fontMonogram, "NEXT", {365, 175}, 38, 2, WHITE);
    DrawRectangleRounded({320, 215, 170, 180}, 0.15f, 6, lightBlue);

    if (game.gameOver) {
      DrawTextEx(fontMonogram, "GAME", {360, 450}, 44, 2, RED);
      DrawTextEx(fontMonogram, "OVER", {360, 485}, 44, 2, RED);
    }

    if (game.state == Game::PLAYING) {
      game.HandleInput();
      if (EventTriggered(0.2)) {
        game.MoveDown();
      }
    }
    game.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
