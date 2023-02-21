#include "Game.hpp"

Game::Game()
{}

Game::~Game()
{}

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
            isRunning = false;
        }
    else
    {
        cout << "SDL initialized! \n";
        window = SDL_CreateWindow(tilte, xpos, ypos, width, height, flags);
        if (window == NULL)
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
            isRunning = false;
        }
        else
        {
            cout << "Window created! \n" << "\t window = " << window << "\n";
            isRunning == true;
            cout << "\t isRunning = " << isRunning << "\n";
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        cout << "\t renderer = " << renderer << "\n";
        if (renderer == NULL)
        {
            cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
            isRunning = false;
        }
        else
        {
            SDL_SetRenderDrawColor(renderer,123,200,221,255);
            cout << "Renderer created! \n";
            cout << "\t isRunning = " << isRunning << "\n";
            isRunning == true;
        }
        isRunning == true;
    }
    cout << "\t isRunning = " << isRunning << "\n";
}

void Game::handleEvent()
{
    SDL_Event event;
    SDL_PollEvent (&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        // case SDL_KEYDOWN:
        //     if (event.key.keysym.sym == SDLK_ESCAPE)
        //         isRunning = false;
        //     break;
        default:
            break;
    }
}

void Game::update()
{
    cnt++;
    cout << cnt << "\n";
}

void Game::render()
{
    // SDL_RenderClear (renderer);
    SDL_RenderPresent (renderer);
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