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

//--------------------------------------------------

//SDL_Surface Game::*loadSurface(string path)
//{
    //The final optimized image
	// SDL_Surface* optimizedSurface = NULL;

	// //Load image at specified path
	// SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	// if( loadedSurface == NULL )
	// {
	// 	printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	// }
    // 	else
	// {
	// 	//Convert surface to screen format
	// 	optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
	// 	if( optimizedSurface == NULL )
	// 	{
	// 		printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	// 	}

	// 	//Get rid of old loaded surface
	// 	SDL_FreeSurface( loadedSurface );
	// }

//	return optimizedSurface;

//}


bool Game::loadBackgroundMedia()
{
    bool success = true;

    // load default surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = SDL_LoadBMP("Image/Background/pixel-art.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        cout << "Unable to load image Image/Background/pixel-art.bmp! SDL Error: " << SDL_GetError() << "\n";
        success = false;
    }

    // Load up surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = SDL_LoadBMP("Image/up.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
    {
        cout << "Failed to load up image!\n";
        success = false;
    }

    // Load down surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = SDL_LoadBMP("Image/down.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
    {
        cout << "Failed to load down image!\n";
        success = false;
    }

    // Load left surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = SDL_LoadBMP("Image/left.bmp");
    ;
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
    {
        cout << "Failed to load left image!\n";
        success = false;
    }

    // Load right surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = SDL_LoadBMP("Image/right.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        cout << "Failed to load right image!\n";
        success = false;
    }

    return success;
}

void Game::blitSurface()
{
    SDL_BlitSurface(image, NULL, SDL_GetWindowSurface(window), NULL);
    SDL_UpdateWindowSurface(window);
}

SDL_Window* Game::getWindow() {
    return window;
}
SDL_Renderer* Game::getRenderer() {
    return renderer;
}



//--------------------------------------------------

void Game::handleEvent()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isRunning = false;
            else
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        cout << "up \n";
                        image = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                        break;
                    case SDLK_DOWN:
                        cout << "down \n";
                        image = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                        break;
                    case SDLK_LEFT:
                        cout << "left \n";
                        image = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                        break;
                    case SDLK_RIGHT:
                        cout << "right \n";
                        image = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                        break;
                    default:
                        image = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                        break;
                }
            }
            break;
        default:
            image = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
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


