#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Game {

private:

    int count = 0;
    bool isRunning;
    SDL_Window *window;


public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int heigth, bool FULLSCREEN);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

    static SDL_Renderer *renderer;
};
