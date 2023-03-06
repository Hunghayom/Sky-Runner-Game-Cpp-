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

void Game::loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path)
{
    texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL)
        std::cout << "Fail to load texture: " << SDL_GetError() << '\n';
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

    SDL_Event event;
    SDL_PollEvent(&event);

    SDL_Texture *texture[5];
    loadTexture(texture[0], getRenderer(), "Image/Background/pixel-art.png");
    loadTexture(texture[1], getRenderer(), "Image/up.bmp");
    loadTexture(texture[2], getRenderer(), "Image/down.bmp");
    loadTexture(texture[3], getRenderer(), "Image/left.bmp");
    loadTexture(texture[4], getRenderer(), "Image/right.bmp");

    render(getRenderer(), texture[0]);

    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        setRunning(false);
        break;
    case SDLK_ESCAPE:
        setRunning(false);
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            cout << "up \n";
            render(getRenderer(), texture[1]);
            break;
        case SDLK_DOWN:
            cout << "down \n";
            render(getRenderer(), texture[2]);
            break;
        case SDLK_LEFT:
            cout << "left \n";
            render(getRenderer(), texture[3]);
            break;
        case SDLK_RIGHT:
            cout << "right \n";
            render(getRenderer(), texture[4]);
            break;
        }
    default:
        break;
    }
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
