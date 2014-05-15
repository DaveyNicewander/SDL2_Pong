#ifndef PLAYERTWOPADDLE_H_INCLUDED
#define PLAYERTWOPADDLE_H_INCLUDED

#include "PlayerOnePaddle.h"


class PlayerTwoPaddle
{
public:
    static const int PADDLE_HEIGHT = 100;
    static const int PADDLE_WIDTH = 10;

    static const int PADDLE_VEL = 3;

    SDL_Renderer* p2Renderer;

    SDL_Rect collider;

    PlayerTwoPaddle();

    void handleEvent(SDL_Event &event);

    void makeMove();

    void render(SDL_Renderer* p2Renderer);


private:
    int xPos, yPos;

    int xVel, yVel;

    SDL_Event event;
};








#endif // PLAYERTWOPADDLE_H_INCLUDED
