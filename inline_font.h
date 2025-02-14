#ifndef INLINE_FONT_H
#define INLINE_FONT_H

#include <SDL.h>

typedef struct inline_font {
    const Uint8 *image_data;  // Pointer to BMP data
    int width;                // Texture width
    int height;               // Texture height
    int glyph_x;              // Character width
    int glyph_y;              // Character height
    int image_size;           // Size of image_data in bytes
} inline_font;

void prepare_inline_font(const struct inline_font *font);
void kill_inline_font(void);
void inrenderer(SDL_Renderer *renderer);
void inprint(SDL_Renderer *dst, const char *str, Uint32 x, Uint32 y, const Uint32 fgcolor, const Uint32 bgcolor);

#endif // INLINE_FONT_H

