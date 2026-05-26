#include<iostream>
using namespace std;
#include "raylib.h"
#include <math.h>

class Ground {
    public:
    float speedOfGround = 5;
    Vector2 block = {0.0f, 0.0f};
    void update(){
        block.y = (float)GetRenderHeight() - ((150/991.0f)*GetRenderHeight());

        if(block.x + 450 == 0){
            block.x = GetRenderWidth();
        }
        block.x -= speedOfGround;
        
        
    }
    // Vector2 block2 = {450, GetRenderHeight() - (150/991.0)*GetRenderHeight()};
    // Vector2 block3 = {900, GetRenderHeight() - (150/991.0)*GetRenderHeight()};
    // Vector2 block4 = {1350, GetRenderHeight() - (150/991.0)*GetRenderHeight()};
    // Vector2 block5 = {1800, GetRenderHeight() - (150/991.0)*GetRenderHeight()};
    // Vector2 block6 = {2250, GetRenderHeight() - (150/991.0)*GetRenderHeight()};
};

class Bird{
    public:
    Vector2 position = {480.0f - 13.0f, 421.5f - 24.5f};
};

class UpTube{
    public:
    float speedOfTube = 5;
    Vector2 position = {1000, 0};
};

int main(){

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);

    
    int ScreenWidth = 1920;
    int ScreenHeight = 991;
    int gravity = -3; 
    
    InitWindow(ScreenWidth, ScreenHeight, "Flappy Bird");
    // ToggleFullscreen();
    SetTargetFPS(60);

    Image birdImage = LoadImage("images/bird.png");
    Texture2D ground = LoadTexture("images/ground5.png");
    Texture2D background = LoadTexture("images/background5.png");
    Texture2D bird = LoadTexture("images/bird2.png");
    Texture2D Tube = LoadTexture("images/tube1.png"); 

    SetWindowIcon(birdImage);
    UnloadImage(birdImage);

    Ground Block1;
    Ground Block2;
    Ground Block3;
    Ground Block4;
    Ground Block5;
    Ground Block6;
    Ground Block7;


    Block2.block.x = 450;
    Block3.block.x = 900;
    Block4.block.x = 1350; 
    Block5.block.x = 1800; 
    Block6.block.x = 2250; 
    Block7.block.x = 2250; 

    Bird birdPng;

    UpTube tube1;



     
    
    // MaximizeWindow();
    
    // cout << IsWindowFullscreen() ;
    while(WindowShouldClose() == false){

        Block1.update();
        Block2.update();
        Block3.update();
        Block4.update();
        Block5.update();
        Block6.update();
        Block7.update();

        if(IsKeyPressed(KEY_UP) == false){
            birdPng.position.y -= gravity; 

        }

        if(IsKeyDown(KEY_UP) == true){
            birdPng.position.y -= -100/(2*gravity) ; 
        }

        // int currentWidth = GetRenderWidth();
        int currentHeight = GetRenderHeight();

        BeginDrawing();
        ClearBackground(BLACK);
        // DrawText(TextFormat("True Width: %d", currentWidth), 50, 50, 40, GREEN);
        // DrawText(TextFormat("True Height: %d", currentHeight), 50, 100, 40, GREEN);
        
        // DrawTexture(ground, 0, currentHeight - (150/991.0)*currentHeight, WHITE);
        // DrawTexture(ground, 450, currentHeight - (150/991.0)*currentHeight, WHITE);
        // DrawTexture(ground, 900, currentHeight - (150/991.0)*currentHeight, WHITE);
        // DrawTexture(ground, 1350, currentHeight - (150/991.0)*currentHeight, WHITE);
        // DrawTexture(ground, 1800, currentHeight - (150/991.0)*currentHeight, WHITE);
        // DrawTexture(ground, 2250, currentHeight - (150/991.0)*currentHeight, WHITE);
        DrawTexture(background, 0, currentHeight-(843+(150/991.0f)*currentHeight), WHITE);

        DrawTextureV(ground, Block1.block, WHITE );
        DrawTextureV(ground, Block2.block, WHITE );
        DrawTextureV(ground, Block3.block, WHITE );
        DrawTextureV(ground, Block4.block, WHITE );
        DrawTextureV(ground, Block5.block, WHITE );
        DrawTextureV(ground, Block6.block, WHITE );
        DrawTextureV(ground, Block7.block, WHITE );

        DrawTextureV(bird, birdPng.position, WHITE);

        DrawTextureV(Tube, tube1.position, WHITE);
        
        
        
        EndDrawing();

    }
    
    CloseWindow();
    // int height = GetScreenHeight();
    // int width = GetScreenWidth();
    // cout << height << " "<< width;
    
    return 0;
}