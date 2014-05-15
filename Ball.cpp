#include "Ball.h"



Ball::Ball()
{
    xPos = SCREEN_WIDTH/2;
    yPos = SCREEN_HEIGHT/2;

    xVel = -BALL_VEL;
    yVel = 0;

    collider.w = BALL_WIDTH;
    collider.h = BALL_HEIGHT;
}

void Ball::makeMove(bool collision)
{
    if (xPos<0)
    {
        //score 1 for right paddle
        xPos = SCREEN_WIDTH/2;
        collider.x = xPos;
        xVel = -BALL_VEL;
        yVel = 0;
    }
    if (xPos+BALL_WIDTH>SCREEN_WIDTH)
    {
        //score 1 for left paddle
        xPos = SCREEN_WIDTH/2;
        collider.x = xPos;
        xVel = BALL_VEL;
        yVel = 0;
    }
    if(collision == true && xPos>=SCREEN_WIDTH/2)
    {
        yVel -= BALL_VEL;

        xVel -= BALL_VEL;
    }
    if(collision == true && xPos<=SCREEN_WIDTH/2)
    {
        yVel += BALL_VEL;

        xVel += BALL_VEL;
    }
    if(yPos<0)
    {
        yVel += BALL_VEL;
    }
    if(yPos+BALL_HEIGHT>SCREEN_HEIGHT)
    {
        yVel -= BALL_VEL;
    }

    yPos += yVel;
    collider.y = yPos;
    xPos += xVel;
    collider.x = xPos;
}

void Ball::render(SDL_Renderer* ballRenderer)
{
    SDL_Rect ball;

    ball.x = xPos;
    ball.y = yPos;
    ball.w = BALL_WIDTH;
    ball.h = BALL_HEIGHT;
    SDL_SetRenderDrawColor(ballRenderer,0xFF,0xFF,0xFF,0xFF);
    SDL_RenderFillRect(ballRenderer,&ball);
}

int Ball::getXPos()
{
    return xPos;
}


