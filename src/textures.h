#ifndef TEXTURES_H
#define TEXTURES_H

extern unsigned int ID;
extern int sky_texture;

enum TextureID {
    TEX_CEIL          = 1,
    TEX_WALL          = 2,
    TEX_FLOOR         = 3,
    TEX_SWAPNO        = 4,
    TEX_GRASS         = 5,
    TEX_WINDOW        = 6,
    TEX_REDSTRIPE     = 7,
    TEX_SALE          = 8,
    TEX_ROAD          = 9,
    TEX_BRICK         = 10,
    TEX_FENCE         = 11,
    TEX_FUELPUMPLOWER = 12,
    TEX_FUELPUMPUPPER = 13,
    TEX_BLACK         = 14,
    TEX_WOOD          = 15,
    TEX_NOODLES       = 16,
    TEX_KITTEN        = 17,
    TEX_CHEF          = 18,
    TEX_OAT           = 19,
    TEX_CHILLI        = 20,
    TEX_CHOCO1        = 21,
    TEX_CHOCO2        = 22,
    TEX_AC            = 23,
    TEX_SIGNS         = 24,
    TEX_ICE_CREAM     = 25,
    TEX_FREEZER_INSIDE = 26,
    TEX_FROZEN_FOOD   = 27,
    TEX_COLA          = 28,
    TEX_SKY           = 29,
    TEX_NIGHTSKY      = 30
};

void LoadTexture(const char *filename);

#endif
