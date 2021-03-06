#include "game.hpp"
#include "textureManager.hpp"
#include "gameObject.hpp"


using namespace std;

GameObject *player;
GameObject *enemy;

SDL_Renderer *Game::renderer = nullptr;


Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int heigth, bool FULLSCREEN) {
    
    int flags = 0;
    if (FULLSCREEN) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystem Initialized" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, heigth, flags);
        if (window) {
            cout << "Window created!!" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 200, 120, 255, 255);
            cout << "Renderer created!!" << endl;
        }

        isRunning = true;
    }
    else {
        isRunning = false;
    }
    
    
    player = new GameObject("../assets/protagonist.png", 0, 0);
    enemy = new GameObject("../assets/enemy.png", 50, 50);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update() {
    player->Update();
    enemy->Update();
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Here we add stuff to render //
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

