#pragma once
#include "Var_def.h"
void init_font_file() {
 Time_13 = TTF_OpenFont("E:\\times.ttf", 13);
 Time_15 = TTF_OpenFont("E:\\times.ttf", 15);
 Time_17 = TTF_OpenFont("E:\\times.ttf", 17);
 Time_19 = TTF_OpenFont("E:\\times.ttf", 19);
 Time_21 = TTF_OpenFont("E:\\times.ttf", 21);
 Time_22 = TTF_OpenFont("E:\\times.ttf", 22);
 Time_23 = TTF_OpenFont("E:\\times.ttf", 23);
 Time_24 = TTF_OpenFont("E:\\times.ttf", 24);


 Consola_7 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 7);
 Consola_10 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 10);
 Consola_13 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 13);
 Consola_16 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 16);
 Consola_17 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 17);
 Consola_18 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 18);
 Consola_19 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 19);
 Consola_20 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 20);
 Consola_21 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 21);
 Consola_22 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 22);
 Consola_28 = TTF_OpenFont("E:\\BT_KTLT_III\\BTKTLT_ver3\\consola.ttf", 28);
}

void destroy_font() {
    TTF_CloseFont(Consola_7);
    TTF_CloseFont(Consola_10);
    TTF_CloseFont(Consola_13);
    TTF_CloseFont(Consola_16);
    TTF_CloseFont(Consola_17);
    TTF_CloseFont(Consola_18);
    TTF_CloseFont(Consola_19);
    TTF_CloseFont(Consola_20);
    TTF_CloseFont(Consola_21);
    TTF_CloseFont(Consola_28);
    TTF_CloseFont(Time_13);

    TTF_Quit();
}
void drawText(SDL_Renderer* renderer, int x, int y, const char* text, TTF_Font* font)
{
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Color textColor = { 255, 255, 255 }; // Đặt màu văn bản là màu xanh (R: 0, G: 0, B: 255)

    surface = TTF_RenderText_Solid(font, text, textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int width = surface->w;
    int height = surface->h;

    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
void draw_black_Text(SDL_Renderer* renderer, int x, int y, const char* text, TTF_Font* font)
{
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Color textColor = { 0, 0, 0 }; // Đặt màu văn bản là màu xanh (R: 0, G: 0, B: 255)

    surface = TTF_RenderText_Solid(font, text, textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int width = surface->w;
    int height = surface->h;

    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}