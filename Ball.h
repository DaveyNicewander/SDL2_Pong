#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED


#include "PlayerOnePaddle.h"

class Ball
{
public:
    static const int BALL_HEIGHT = 10;
    static const int BALL_WIDTH = 10;

    static const int BALL_VEL = 1;

    SDL_Renderer* ballRenderer;

    SDL_Rect collider;

    Ball();

    void makeMove(bool collision);

    void render(SDL_Renderer* ballRenderer);

    bool checkCollision(SDL_Rect a, SDL_Rect b);

    int getXPos();

private:
    int xPos, yPos;

    int xVel, yVel;
};













#endif // BALL_H_INCLUDED
