#include <raylib.h>

#define VERSION "v0.0.0"

#define WINDOW_NAME "Ruther"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_FPS 60

static void create_window(void);
static void destroy_window(void);

static void begin_frame(void);
static void end_frame(void);

int main() {
    create_window();

    while (!WindowShouldClose()) {
        begin_frame();
        end_frame();
    }

    destroy_window();
    return 0;
}

static void create_window(void) {
    InitWindow(
        WINDOW_WIDTH, WINDOW_HEIGHT,
        WINDOW_NAME " - " VERSION
    );

    SetTargetFPS(WINDOW_FPS);
}

static void destroy_window(void) {
    CloseWindow();
}

static void begin_frame(void) {
    BeginDrawing();
    ClearBackground(BLACK);
}

static void end_frame(void) {
    EndDrawing();
}
