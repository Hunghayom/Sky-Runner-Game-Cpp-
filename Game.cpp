#include "Game.hpp"

Game::Game()
{}
Game::~Game()
{}

void Game::setRunning(bool running)
{
    isRunning = running;
}

void Game::init(const char *tilte, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << "\n";
        setRunning(false);
    }
    else
    {
        cout << "SDL initialized! \n";

        // Create window
        window = SDL_CreateWindow(tilte, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (window == NULL)
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
            setRunning(false);
        }
        if (renderer == NULL)
        {
            cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
            setRunning(false);
        }
        setRunning(true);
    }
}



void Game::render(SDL_Renderer *renderer, SDL_Texture *texture)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

SDL_Window *Game::getWindow()
{
    return window;
}
SDL_Renderer *Game::getRenderer()
{
    return renderer;
}

//--------------------------------------------------

void Game::handleEvent()
{
}

void Game::update()
{
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit;
    cout << "Game cleaned \n";
}

bool Game::running()
{
    return isRunning;
}
