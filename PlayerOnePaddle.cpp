#include "PlayerOnePaddle.h"








PlayerOnePaddle::PlayerOnePaddle()
{
    xPos = SCREEN_WIDTH/4;
    yPos = SCREEN_HEIGHT/2;

    xVel = 0;
    yVel = 0;

    collider.w = PADDLE_WIDTH;
    collider.h = PADDLE_HEIGHT;
}

void PlayerOnePaddle::handleEvent(SDL_Event &event)
{
    if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP        :yVel -= PADDLE_VEL;
                                 break;

            case SDLK_DOWN      :yVel += PADDLE_VEL;
                                 break;
        }
    }
    else if(event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP        :yVel += PADDLE_VEL;
                                 break;

            case SDLK_DOWN      :yVel -= PADDLE_VEL;
                                 break;
        }
    }

    return;
}


void PlayerOnePaddle::makeMove()
{
    yPos += yVel;
    collider.x = xPos;
    collider.y = yPos;

    if((yPos<0) || (yPos + PADDLE_HEIGHT > SCREEN_HEIGHT))
    {
        yPos -= yVel;
        collider.y = yPos;
        collider.x = xPos;
    }
}


void PlayerOnePaddle::render(SDL_Renderer* p1Renderer)
{
    SDL_Rect paddle;

    paddle.x = xPos;
    paddle.y = yPos;
    paddle.w = PADDLE_WIDTH;
    paddle.h = PADDLE_HEIGHT;
    SDL_SetRenderDrawColor(p1Renderer,0xFF,0xFF,0xFF,0xFF);
    SDL_RenderFillRect(p1Renderer,&paddle);
}
