#pragma once
#include "H-menu.h"

#define window Window*
#define menu_bar Menu_bar*
struct  Menu_bar
{
	Uint32 x_location = 0;
	Uint32 y_loaction = 0;
	Uint32 menu_bar_width = default_menu_bar_width;
	Uint32 menu_bar_height = default_menu_bar_height;

	h_menu list_menu_bar_items = nullptr;

};
void add_items_list_to_menu_bar(menu_bar handle_to_menu_bar,h_menu list_menu_bar_items){
	handle_to_menu_bar->list_menu_bar_items = list_menu_bar_items;
}

struct  Window
{
	Uint32 x_location = 0;
	Uint32 y_location = 0;

	Uint32 window_width = Default_screen_width;
	Uint32 window_height = Default_screen_height;

	SDL_Color window_color = BLACK;
	menu_bar menu = nullptr;
	w_tab window_tab = nullptr;
};
void add_menu_bar(window handle_to_window, menu_bar handle_to_menu_bar) {
	handle_to_window->menu = handle_to_menu_bar;
}
void add_window_tab(window handle_to_window, w_tab handle_to_window_tab){
	handle_to_window->window_tab = handle_to_window_tab;
}

void draw_window(SDL_Renderer* render,window handle_to_window) {
	if (handle_to_window->window_tab != nullptr) {
		draw_w_tab(render, handle_to_window->window_tab,controler,controller_s);
	}
	if (handle_to_window->menu != nullptr) {
		drawRectangle(render, handle_to_window->menu->x_location, handle_to_window->menu->y_loaction, handle_to_window->menu->menu_bar_width, handle_to_window->menu->menu_bar_height,BLUE_3);
		draw_h_menu(handle_to_window->menu->list_menu_bar_items, render);
	}
	
}