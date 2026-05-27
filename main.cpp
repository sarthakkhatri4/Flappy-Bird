#include<iostream>
using namespace std;
#include "raylib.h"
#include <math.h>

class Ground {
    public:
    inline static float speedOfGround = 0;
    Vector2 block = {0.0f, 0.0f};
    void update(){
        block.y = (float)GetRenderHeight() - ((150/991.0f)*GetRenderHeight());

        if(block.x + 450 == 0){
            block.x = GetRenderWidth();
        }
        block.x -= speedOfGround;
        
        
    }
};

class Bird{
    public:
    Vector2 position = {480.0f - 13.0f, 421.5f - 24.5f};
    float velocity = 0.0f;
    float jumpforce = -6.0f;
};

class UpTube{
    public:
    inline static float speedOfTube = 0;
    Vector2 position = {1920.0f, 0.0f};

    bool isPassed = false;

    void update(){
        position.x -= speedOfTube;

    }

};

class DownTube{
    public:
    inline static float speedOfTube = 0;
    Vector2 position = {1920.0f, 480.0f};

    void update(){
        position.x -= speedOfTube;
    }
};

int main(){

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);

    
    int ScreenWidth = 1920;
    int ScreenHeight = 991;
    float gravity = 0.0;
    bool gameOver = true;
    bool isCollision = false;
    
    int score = 0;
    
    
    InitWindow(ScreenWidth, ScreenHeight, "Flappy Bird");
    // ToggleFullscreen();
    SetTargetFPS(60);

    Image birdImage = LoadImage("images/bird.png");
    Texture2D ground = LoadTexture("images/ground5.png");
    Texture2D background = LoadTexture("images/background5.png");
    Texture2D bird = LoadTexture("images/bird2.png");
    Texture2D upTube = LoadTexture("images/uptube2.png"); 
    Texture2D downTube = LoadTexture("images/downtube.png");

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

    const int numTubes = 7;
    
    UpTube upTubes[numTubes];
    DownTube downTubes[numTubes];

    for(int i = 0; i<numTubes; i++){
        upTubes[i].position.x = 1920.0f + 300*i;
        downTubes[i].position.x = 1920.0f + 300*i;

        float x1 = (float)GetRandomValue(-493, -100);
        float x2 = (593 + x1) + 250;

        upTubes[i].position.y = x1;
        downTubes[i].position.y = x2;
    }


    while(WindowShouldClose() == false){


        if(IsKeyPressed(KEY_SPACE) == true && gameOver == true){
            gameOver = false;
            Ground::speedOfGround = 5;
            UpTube::speedOfTube = 5;
            DownTube::speedOfTube = 5;
            gravity = 0.25f; 

        }

        string scoreChar = to_string(score);
        string* scoreCharPtr = &scoreChar;

        if(isCollision == true){
            gameOver = true;
            birdPng.velocity = 0.0f;

        }
        if(birdPng.position.y <= 0){
            gameOver = true;
            birdPng.position.y = 0;
            birdPng.velocity = 0.0f;
        }

        if(birdPng.position.y >=843-49){
            gameOver = true;
            birdPng.position.y = 843-49;
            birdPng.velocity = 0.0f;
        }

        if(gameOver == true){
            Ground::speedOfGround = 0;
            UpTube::speedOfTube = 0;
            DownTube::speedOfTube = 0;
            gravity = 0.0f; 
        }

        Block1.update();
        Block2.update();
        Block3.update();
        Block4.update();
        Block5.update();
        Block6.update();
        Block7.update();


        for(int i=0; i<numTubes; i++){
            upTubes[i].update();
            downTubes[i].update();

            Rectangle upPipeBox = {
                upTubes[i].position.x,
                upTubes[i].position.y,
                76,
                593
            };

            Rectangle downPipeBox = {
                downTubes[i].position.x,
                downTubes[i].position.y,
                76,
                593
            };
            Rectangle birdBox = {
                birdPng.position.x,
                birdPng.position.y,
                68,
                49
            };
            if(CheckCollisionRecs(upPipeBox, birdBox) || CheckCollisionRecs(downPipeBox, birdBox)){
                isCollision = true;
            }
            if(upTubes[i].position.x <= birdPng.position.x && upTubes[i].isPassed == false){
                upTubes[i].isPassed = true;
                score += 1;
            }
            
        }

        for(int i = 0; i<numTubes; i++){
            if(upTubes[i].position.x <= -76){
                if(i == 0){
                    upTubes[i].position.x = upTubes[6].position.x + 300;
                    downTubes[i].position.x = downTubes[6].position.x + 300;

                }
                else{
                    upTubes[i].position.x = upTubes[i-1].position.x + 300;
                    downTubes[i].position.x = downTubes[i-1].position.x + 300;
                }

                float x1 = (float)GetRandomValue(-493, -100);
                float x2 = (593 + x1) + 250;

                upTubes[i].position.y = x1;
                downTubes[i].position.y = x2;

                upTubes[i].isPassed = false;
            }
            
        }
        
        birdPng.velocity += gravity; 
            
        
        if(IsKeyPressed(KEY_UP) == true && gameOver == false){
            birdPng.velocity = birdPng.jumpforce;
        }

        birdPng.position.y += birdPng.velocity; 
        
        
        // int currentWidth = GetRenderWidth();
        int currentHeight = GetRenderHeight();

        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawTexture(background, 0, currentHeight-(843+(150/991.0f)*currentHeight), WHITE);

        for(int i = 0; i<numTubes; i++){
            DrawTextureV(upTube, upTubes[i].position, WHITE);
            DrawTextureV(downTube, downTubes[i].position, WHITE);

        }

        DrawTextureV(ground, Block1.block, WHITE );
        DrawTextureV(ground, Block2.block, WHITE );
        DrawTextureV(ground, Block3.block, WHITE );
        DrawTextureV(ground, Block4.block, WHITE );
        DrawTextureV(ground, Block5.block, WHITE );
        DrawTextureV(ground, Block6.block, WHITE );
        DrawTextureV(ground, Block7.block, WHITE );

        DrawTextureV(bird, birdPng.position, WHITE);

        DrawText(scoreCharPtr->c_str(), 1920/2 - 40, 20, 80, BLACK);

        
        EndDrawing();

    }
    
    CloseWindow();
    
    return 0;
}