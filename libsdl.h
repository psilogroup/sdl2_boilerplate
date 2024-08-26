#include <SDL3/SDL.h>
#include <string>
SDL_Window* window = NULL;    
SDL_Renderer* renderer = NULL;

SDL_Window* Startup(std::string title, int w, int h)
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return nullptr;
    }


    window = SDL_CreateWindow(title.c_str(), 1027, 768, 0);
    
    
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return nullptr;
    }

  //  screenSurface = SDL_GetWindowSurface( window );

    renderer = SDL_CreateRenderer(window,NULL );
    if( renderer == NULL )
    {
        printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
        return nullptr;
    }

    return window;
            
}


void CloseSDL()
{
    //Destroy window
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer(renderer);
    //Quit SDL subsystems
    SDL_Quit();
}

//draw filled circle
void DrawFilledCircle(int32_t centreX, int32_t centreY, int32_t radius, uint32_t color)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    //extract RGB from color
    uint8_t r = (color & 0xFF0000) >> 16;
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderLine(renderer, centreX - x, centreY - y, centreX + x, centreY - y);
        SDL_RenderLine(renderer, centreX - x, centreY + y, centreX + x, centreY + y);
        SDL_RenderLine(renderer, centreX - y, centreY - x, centreX + y, centreY - x);
        SDL_RenderLine(renderer, centreX - y, centreY + x, centreX + y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

//draw circle
void DrawCircle(int32_t centreX, int32_t centreY, int32_t radius, uint32_t color)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    //extract RGB from color
    uint8_t r = (color & 0xFF0000) >> 16;
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderPoint(renderer, centreX + x, centreY - y);
        SDL_RenderPoint(renderer, centreX + x, centreY + y);
        SDL_RenderPoint(renderer, centreX - x, centreY - y);
        SDL_RenderPoint(renderer, centreX - x, centreY + y);
        SDL_RenderPoint(renderer, centreX + y, centreY - x);
        SDL_RenderPoint(renderer, centreX + y, centreY + x);
        SDL_RenderPoint(renderer, centreX - y, centreY - x);
        SDL_RenderPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

//draw line
void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color)
{
    //extract RGB from color
    uint8_t r = (color & 0xFF0000) >> 16;
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    SDL_RenderLine(renderer, x1, y1, x2, y2);
}

//draw rectangle
void DrawRectangle(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
{
    //extract RGB from color
    uint8_t r = (color & 0xFF0000) >> 16;
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    SDL_Rect rect = { x, y, w, h };
    //SDL_RenderRect(renderer, &rect);
}

//draw filled rectangle
void DrawFilledRectangle(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)
{
    //extract RGB from color
    uint8_t r = (color & 0xFF0000) >> 16;
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    SDL_Rect rect = { x, y, w, h };
    //SDL_RenderFillRect(renderer, &rect);
}

//clear screen
void ClearScreen(uint32_t color)
{
    //extract RGB from color
    uint8_t r = (color & 0xFF0000) >> 16;
    uint8_t g = (color & 0x00FF00) >> 8;
    uint8_t b = (color & 0x0000FF);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
    
}

