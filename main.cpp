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
};

class Bird{
    public:
    Vector2 position = {480.0f - 13.0f, 421.5f - 24.5f};
    float velocity = 0.0f;
    float jumpforce = -9.5f;
};

class UpTube{
    public:
    float speedOfTube = 5;
    // Vector2 position = {0.0f, (float)(GetRandomValue(100, 320) - 320)};
    Vector2 position = {1920.0f, 0.0f};

    void update(){
        position.x -= speedOfTube;

    }

};

class DownTube{
    public:
    float speedOfTube = 5;
    Vector2 position = {1920.0f, 480.0f};

    void update(){
        position.x -= speedOfTube;
    }
};

int main(){

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);

    
    int ScreenWidth = 1920;
    int ScreenHeight = 991;
    float gravity = 0.4f; 
    // bool birdShouldRise = false;
    
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

        float x1 = (float)GetRandomValue(-493, -30);
        float x2 = (593 + x1) + 180;

        upTubes[i].position.y = x1;
        downTubes[i].position.y = x2;
    }


    // UpTube upTube1;
    // UpTube upTube2;
    // UpTube upTube3;
    // UpTube upTube4;
    // UpTube upTube5;
    // UpTube upTube6;

    // upTube1.position.x = 1920.0f;
    // upTube2.position.x = 2220.0f;
    // upTube3.position.x = 2520.0f;
    // upTube4.position.x = 2820.0f;
    // upTube5.position.x = 3120.0f;
    // upTube6.position.x = 3420.0f;

    
    // DownTube downTube1;
    // DownTube downTube2;
    // DownTube downTube3;
    // DownTube downTube4;
    // DownTube downTube5;
    // DownTube downTube6;

    // downTube1.position.x = 1920.0f;
    // downTube2.position.x = 2220.0f;
    // downTube3.position.x = 2520.0f;
    // downTube4.position.x = 2820.0f;
    // downTube5.position.x = 3120.0f;
    // downTube6.position.x = 3420.0f;

    // float timer = 0.0f;

    while(WindowShouldClose() == false){

        // timer += GetFrameTime();
        
        // if(timer >= 1.0f){
        //     upTube1.speedOfTube = -5;

        //     timer -= 1.0f;
        // }



        Block1.update();
        Block2.update();
        Block3.update();
        Block4.update();
        Block5.update();
        Block6.update();
        Block7.update();

        // upTube1.update();
        // upTube2.update();
        // upTube3.update();
        // upTube4.update();
        // upTube5.update();
        // upTube6.update();

        // downTube1.update();
        // downTube2.update();
        // downTube3.update();
        // downTube4.update();
        // downTube5.update();
        // downTube6.update();

        for(int i=0; i<numTubes; i++){
            upTubes[i].update();
            downTubes[i].update();
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

                float x1 = (float)GetRandomValue(-493, -30);
                float x2 = (593 + x1) + 180;

                upTubes[i].position.y = x1;
                downTubes[i].position.y = x2;
            }

        }

        // for(int i = 0; i<numTubes; i++){
        //     if(upTubes[i].position.x == 1920.0f){
        //         float x1 = (float)GetRandomValue(-493, -30);
        //         float x2 = (593 + x1) + 180;

        //         upTubes[i].position.y = x1;
        //         downTubes[i].position.y = x2;
        //     }
        // }


        
        birdPng.velocity += gravity; 
            
        
        if(IsKeyPressed(KEY_UP) == true){
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
        
        // DrawTextureV(upTube, upTube1.position, WHITE);
        // DrawTextureV(upTube, upTube2.position, WHITE);
        // DrawTextureV(upTube, upTube3.position, WHITE);
        // DrawTextureV(upTube, upTube4.position, WHITE);
        // DrawTextureV(upTube, upTube5.position, WHITE);
        // DrawTextureV(upTube, upTube6.position, WHITE);


        // DrawTextureV(downTube, downTube1.position, WHITE);
        // DrawTextureV(downTube, downTube2.position, WHITE);
        // DrawTextureV(downTube, downTube3.position, WHITE);
        // DrawTextureV(downTube, downTube4.position, WHITE);
        // DrawTextureV(downTube, downTube5.position, WHITE);
        // DrawTextureV(downTube, downTube6.position, WHITE);


        DrawTextureV(ground, Block1.block, WHITE );
        DrawTextureV(ground, Block2.block, WHITE );
        DrawTextureV(ground, Block3.block, WHITE );
        DrawTextureV(ground, Block4.block, WHITE );
        DrawTextureV(ground, Block5.block, WHITE );
        DrawTextureV(ground, Block6.block, WHITE );
        DrawTextureV(ground, Block7.block, WHITE );

        DrawTextureV(bird, birdPng.position, WHITE);

        
        EndDrawing();

    }
    
    CloseWindow();
    
    return 0;
}