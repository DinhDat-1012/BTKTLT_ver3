#pragma once
#include "Var_def.h"

void get_mouse_location() {
	Uint32 mouseState = SDL_GetMouseState(&x_mouse_location, &y_mouse_location);
}
