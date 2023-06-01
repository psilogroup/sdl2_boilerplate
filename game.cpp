#include "libsdl.h"

void Draw()
{
    uint32_t skyBlue = 0x87CEEB;
    ClearScreen(0x87CEEB);
 
    DrawFilledCircle(320, 240, 30, 0xFF0000);
    
    SDL_RenderPresent(renderer);
}

void mainloop()
{
    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }

            //handle escape key
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
            }

            Draw();
            
        }
        //SDL_Delay(16);
    }
}

int main(int argc, char **argv)
{
    if (Startup("Hello World", 640, 480) == nullptr)
    {
        return 1;
    }

    mainloop();


}

