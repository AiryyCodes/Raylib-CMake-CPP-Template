#include <cstdio>
#include <cstdlib>

#include <raylib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Raylib Template"

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Thank you for using this template!", 190, 200, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}
