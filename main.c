#include <SDL.h>
#include "inline_font.h"
#include "font1.h" // Include your font header

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Bitmap Font Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Prepare the font
    inrenderer(renderer);
    prepare_inline_font(&font_v1_small); // Load your font

    // Main loop
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear to black
        SDL_RenderClear(renderer);

        // Render message
        inprint(renderer, "Hello World!! Spaces are rendered as white blocks.         .", 50, 50, 0xFFFFFFFF, 0xFF000000); // White text on black background

        SDL_RenderPresent(renderer);
    }

    // Clean up
    kill_inline_font();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

