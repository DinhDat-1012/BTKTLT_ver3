#pragma once
#include "Var_def.h"

void drawSquare(SDL_Renderer* renderer, int x, int y, int size)
{
    SDL_Rect rect = { x, y, size, size };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
void drawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height,SDL_Color color)
{
    SDL_Rect rect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Đặt màu vẽ là màu đỏ (R: 255, G: 0, B: 0, Alpha: 255)
    SDL_RenderFillRect(renderer, &rect); 
}
void drawRoundedSquare(SDL_Renderer* renderer, int x, int y, int size, int cornerRadius, SDL_Color color)
{
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect outerRect = { x, y, size, size };
    SDL_RenderDrawRect(renderer, &outerRect);

    int innerSize = size - 2 * cornerRadius;
    SDL_Rect innerRect = { x + cornerRadius, y + cornerRadius, innerSize, innerSize };
    SDL_RenderDrawRect(renderer, &innerRect);

    int centerX = x + size / 2;
    int centerY = y + size / 2;

    SDL_RenderDrawLine(renderer, x + cornerRadius, y, x + size - cornerRadius, y);
    SDL_RenderDrawLine(renderer, x, y + cornerRadius, x, y + size - cornerRadius);
    SDL_RenderDrawLine(renderer, x + cornerRadius, y, x, y + cornerRadius);

    SDL_RenderDrawLine(renderer, x + size - cornerRadius, y, x + size, y + cornerRadius);
    SDL_RenderDrawLine(renderer, x + size, y + cornerRadius, x + size, y + size - cornerRadius);
    SDL_RenderDrawLine(renderer, x + size - cornerRadius, y + size, x + size, y + size - cornerRadius);

    SDL_RenderDrawLine(renderer, x, y + size - cornerRadius, x + cornerRadius, y + size);
    SDL_RenderDrawLine(renderer, x, y + size - cornerRadius, x + cornerRadius, y + size - cornerRadius);
    SDL_RenderDrawLine(renderer, x + cornerRadius, y + size, x, y + size - cornerRadius);

    SDL_RenderDrawLine(renderer, x + size - cornerRadius, y + size, x + size, y + size - cornerRadius);
    SDL_RenderDrawLine(renderer, x + size, y + size - cornerRadius, x + size - cornerRadius, y + size - cornerRadius);
    SDL_RenderDrawLine(renderer, x + size - cornerRadius, y + size, x + size, y + size - cornerRadius);
}