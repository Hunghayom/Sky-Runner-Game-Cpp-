#include "Game.hpp"
#include "Tilemap.hpp"

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

void Game::setScore(int score)
{
    this->score = score;
}
int Game::getScore()
{
    return score;
}

void Game::start()
{
    start_time = clock();
}
int Game::calculate_score()
{
    clock_t current_time = clock();
    double time_diff = (double)(current_time - start_time) / CLOCKS_PER_SEC;
    int score_diff = (int)(time_diff / 0.2) - score;
    if (score_diff > 0)
    {
        score += score_diff;
    }
    return score;
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
    enum texture_type
    {
        BACKGROUND_SKY,
        BACKGROUND_MOUNTAIN,
        BACKGROUND_PLAINS,
        CHARACTER
    };
    loadTexture(texture[BACKGROUND_SKY], getRenderer(), "Image/Background/Sky.png");
    loadTexture(texture[BACKGROUND_MOUNTAIN], getRenderer(), "Image/Background/mountain.png");
    loadTexture(texture[BACKGROUND_PLAINS], getRenderer(), "Image/Background/plains_ground.png");
    loadTexture(texture[CHARACTER], getRenderer(), "Image/Character/Character.png");
}

void Game::drawing_tilemap(Tilemap tilemap, Texture_box tilemap_texture, SDL_Texture *pTexture, int tilemap_pos_x)
{
    // cout << "Drawing tilemap " << tilemap.get_tilemap_index() << "\n";
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            switch (tilemap.get_tilemap(i, j))
            {
            case 1:
                tilemap_texture.set_destinationRect(tilemap_pos_x + j * 40, i * 40, 40, 40);
                tilemap_texture.set_sourceRect(0, 0, 40, 40);
                render(getRenderer(), pTexture, tilemap_texture.get_sourceRect(), tilemap_texture.get_destinationRect());
                break;

            case 2:
                tilemap_texture.set_destinationRect(tilemap_pos_x + j * 40, i * 40, 40, 40);
                tilemap_texture.set_sourceRect(40, 0, 40, 40);
                render(getRenderer(), pTexture, tilemap_texture.get_sourceRect(), tilemap_texture.get_destinationRect());
                break;

            default:
                break;
            }
        }
    }
}
int Game::random_tilemap(int n, int score)
{
    srand(time(0));
    int tilemap_index = rand() % n;
    if (tilemap_index !=0) 
        {
            return tilemap_index;
        }
    else return 1;
}

void Game::infinite_tilemap(Tilemap tilemap[], int n, Texture_box tilemap_texture, SDL_Texture *pTexture, int index_1, int index_2, int present_tilemap_pos_x, int next_tilemap_pos_x, int speed)
{
    drawing_tilemap(tilemap[index_1], tilemap_texture, pTexture, present_tilemap_pos_x); 
    drawing_tilemap(tilemap[index_2], tilemap_texture, pTexture, next_tilemap_pos_x);
}