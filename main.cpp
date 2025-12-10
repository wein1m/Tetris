#include "game.h"
#include <cstdlib>
#include <ctime>
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
  Color darkBlue = {44, 44, 127, 255};
  int screenW = 300;
  int screenH = 600;
  InitWindow(screenW, screenH, "Tetoriss~");
  SetTargetFPS(45);

  Game game = Game();

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
