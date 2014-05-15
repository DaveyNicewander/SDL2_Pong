#ifndef PLAYERONEPADDLE_H_INCLUDED
#define PLAYERONEPADDLE_H_INCLUDED

#include <SDL.h>

const int SCREEN_HEIGHT = 900;
const int SCREEN_WIDTH = 1700;


class PlayerOnePaddle
{
public:
    static const int PADDLE_HEIGHT = 200;
    static const int PADDLE_WIDTH = 10;

    static const int PADDLE_VEL = 3;

    SDL_Renderer* p1Renderer;

    SDL_Rect collider;

    PlayerOnePaddle();

    void handleEvent(SDL_Event &event);

    void makeMove();

    void render(SDL_Renderer* p1Renderer);


private:
    int xPos, yPos;

    int xVel, yVel;

    SDL_Event event;
};







#endif // PLAYERONEPADDLE_H_INCLUDED
