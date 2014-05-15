/*
Pong in SDL2
Author: Davey Nicewander
Last Stop Time:
*/

#include <SDL.h>
#include <stdio.h>
#include <string>

#include "PlayerOnePaddle.h"
#include "PlayerTwoPaddle.h"
#include "Ball.h"



bool initSDL(); //Initializes SDL and creates window
void closeSDL(); //Shuts down SDL
bool checkCollision(Ball ball,SDL_Rect a,SDL_Rect b,SDL_Rect c); //checks for collision between two objects



SDL_Window* mainWindow = NULL;
SDL_Surface* screenSurface = NULL;

SDL_Surface* image = NULL;
SDL_Renderer* renderer = NULL;



int main(int argc, char* args[])
{

    SDL_Event gameEvent;
    PlayerOnePaddle p1;
    PlayerTwoPaddle p2;
    Ball gameBall;

    bool quit = false;


    if(!initSDL())
    {
        printf("Initialization Failure!\n");
    }
    else
    {
        renderer = SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED);
        while (!quit)
        {
            while(SDL_PollEvent(&gameEvent) != 0)
            {
                if(gameEvent.type==SDL_QUIT)
                {
                    quit = true;
                }
                p1.handleEvent(gameEvent);

                p2.handleEvent(gameEvent);
            }


            p1.makeMove();
            p2.makeMove();
            bool collision = false;
            collision = checkCollision(gameBall,gameBall.collider,p1.collider,p2.collider);
            gameBall.makeMove(collision);

            SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0xFF);
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
            for(int i = 0; i < SCREEN_HEIGHT;i++)
            {
                SDL_RenderDrawPoint(renderer,SCREEN_WIDTH/2,i);
            }
            p1.render(renderer);
            p2.render(renderer);
            gameBall.render(renderer);

            SDL_RenderPresent(renderer);
        }
    }


    closeSDL();
    return 0;
}








bool initSDL()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf("SDL failed to initialize! Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        mainWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                      SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(mainWindow == NULL)
        {
            printf("Window creation failed! Error %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(mainWindow);
        }
    }

    return success;
}


void closeSDL()
{

    SDL_FreeSurface(image);
    image = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;

    SDL_Quit();

    return;
}


bool checkCollision(Ball ball,SDL_Rect a,SDL_Rect b,SDL_Rect c)
{
    int leftA,leftB,leftC;
    int rightA,rightB,rightC;
    int topA,topB,topC;
    int bottomA,bottomB,bottomC;

    //first rect's sides
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //second rect's sides
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //third rect's sides
    leftC = c.x;
    rightC = c.x + c.w;
    topC = c.y;
    bottomC = c.y + c.h;

    if(bottomA <= topB && ball.getXPos()<=SCREEN_WIDTH/2)
    {
        return false;
    }
    if(topA >= bottomB && ball.getXPos()<=SCREEN_WIDTH/2)
    {
        return false;
    }
    if(rightA <= leftB && ball.getXPos()<=SCREEN_WIDTH/2)
    {
        return false;
    }
    if(leftA >= rightB && ball.getXPos()<=SCREEN_WIDTH/2)
    {
        return false;
    }
    if(bottomA <= topC && ball.getXPos()>=SCREEN_WIDTH/2)
    {
        return false;
    }
    if(topA >= bottomC && ball.getXPos()>=SCREEN_WIDTH/2)
    {
        return false;
    }
    if(rightA <= leftC && ball.getXPos()>=SCREEN_WIDTH/2)
    {
        return false;
    }
    if(leftA >= rightC && ball.getXPos()>=SCREEN_WIDTH/2)
    {
        return false;
    }

    //B and C have no physical way of colliding,
    //so no checks for those

    return true;
}


