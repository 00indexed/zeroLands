#include "raylib.h"
#include "stdbool.h"

bool running = true; 

enum {
    screenWidth = 1000,
    screenHeight = 480
};

Color bgColor = {147, 211, 196, 255};
Texture2D grassSprite; 
Texture2D playerSprite;
Rectangle playerDest; 
Rectangle playerSrc; 
float playerSpeed = 3.0; 

void drawScene() {
    Vector2 vector2 = {playerDest.width, playerDest.height};
    DrawTexture(grassSprite, 100, 50, WHITE);
    DrawTexturePro(playerSprite,playerSrc,playerDest,vector2,0,WHITE);
}

void input() {
    // Handle input here
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        playerDest.y -= playerSpeed;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        playerDest.y += playerSpeed;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        playerDest.x -= playerSpeed;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        playerDest.x += playerSpeed;
    }
}

void update() {
    running = !WindowShouldClose();
}

void render() {
    BeginDrawing();
    ClearBackground(bgColor);
    DrawText("Welcome to Zero Lands", 190, 200, 20, RAYWHITE);
    drawScene();
    EndDrawing();
}

void init() {
    InitWindow(screenWidth, screenHeight, "Zero Lands");
    SetExitKey(0);
    SetTargetFPS(60);
    grassSprite = LoadTexture("res/Tilesets/Grass.png");
    playerSprite = LoadTexture("res/Characters/BasicCharakterSpritesheet.png");
    playerSrc = (Rectangle){0, 0 , 48, 48};
    playerDest = (Rectangle){200, 200 , 100, 100};
}

void quit() {
    UnloadTexture(grassSprite);
    UnloadTexture(playerSprite);    // Unload the texture
    CloseWindow();
}

int main(void) {
    init();
    
    // Main game loop
    while (running) {
        input();
        update();
        render();
    }

    quit();
    return 0;
}
