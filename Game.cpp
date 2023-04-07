#include "Game.hpp"


Game::Game()
{
}
Game::~Game()
{
}

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



SDL_Window *Game::getWindow()
{
    return window;
}
SDL_Renderer *Game::getRenderer()
{
    return renderer;
}

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

void Game::render(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect destinationRect)
{
    SDL_RenderCopy(renderer, texture, &sourceRect, &destinationRect);
}

void Game::loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path)
{
    texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL)
        cout << "Fail to load texture: " << SDL_GetError() << '\n';
}

void Game::Texture_loader(SDL_Texture *texture[], int n)
{
    enum texture_type {BACKGROUND_SKY, BACKGROUND_MOUNTAIN,BACKGROUND_PLAINS, CHARACTER};
    loadTexture(texture[BACKGROUND_SKY], getRenderer(), "Image/Background/Sky.png");
    loadTexture(texture[BACKGROUND_MOUNTAIN], getRenderer(), "Image/Background/mountain.png");
    loadTexture(texture[BACKGROUND_PLAINS], getRenderer(), "Image/Background/plains_ground.png");
    loadTexture(texture[CHARACTER], getRenderer(), "Image/Character/Character.png");
}


