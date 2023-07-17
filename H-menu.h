#pragma once
#include"Window_tab.h"

#define h_menu H_menu*
struct  H_menu
{	
	TEXT name_h_menu = "";
	bool active = false;
	bool houver = false;

	Uint32 x_location = 0;
	Uint32 y_loaction = 0;

	int num_sub_menu = 0;
	int num_next_menu = 0;

	Uint32 h_menu_width = 100;
	Uint32 h_menu_height = 40;

	w_tab handle_to_wtab = nullptr;
	SDL_Color h_menu_color = DEFAULT_h_menu_COLOR;

	h_menu next_h_menu = nullptr;
	h_menu list_sub_menu = nullptr;

};
h_menu create_h_menu(TEXT name,w_tab window_tab_link) {
	h_menu curr_h_menu = new H_menu;

	curr_h_menu->name_h_menu = name;
	curr_h_menu->handle_to_wtab = window_tab_link;
	return curr_h_menu;
}
void set_h_menu(h_menu handle_to_h_menu,TEXT name, w_tab window_tab_link) {
	handle_to_h_menu->name_h_menu = name;
	handle_to_h_menu->handle_to_wtab = window_tab_link;
}
void add_sub_menu(h_menu F_hmenu, h_menu next_sub_menu) {
	
	h_menu curr_menu = F_hmenu;
	while (true) {
		if (curr_menu->list_sub_menu == nullptr) {
			curr_menu->list_sub_menu = next_sub_menu;
			break;
		}
		curr_menu = curr_menu->list_sub_menu;

	}
	F_hmenu->num_sub_menu = F_hmenu->num_sub_menu + 1;
	
	next_sub_menu->y_loaction = next_sub_menu->y_loaction + next_sub_menu->h_menu_height * F_hmenu->num_sub_menu ;
	next_sub_menu->x_location = F_hmenu->x_location;
}
void add_next_h_menu(h_menu handle_to_father_h_menu,h_menu handle_to_next_h_mneu) {
	h_menu curr_menu = handle_to_father_h_menu;
	while (true) {
		if (curr_menu->next_h_menu == nullptr) {
			curr_menu->next_h_menu = handle_to_next_h_mneu;
			break;
		}
		curr_menu = curr_menu->next_h_menu;

	}
	handle_to_father_h_menu->num_next_menu = handle_to_father_h_menu->num_next_menu + 1;
	handle_to_next_h_mneu->x_location = handle_to_next_h_mneu->x_location + handle_to_next_h_mneu->h_menu_width * handle_to_father_h_menu->num_next_menu;
}
void draw_h_menu(h_menu list_items,SDL_Renderer *render) {
	h_menu curr_menu = list_items;
	while (true) {
		if (curr_menu->next_h_menu != nullptr) {
			if (curr_menu->x_location<= x_mouse_clickL && x_mouse_clickL <=curr_menu->x_location + curr_menu->h_menu_width) {
				if (curr_menu->y_loaction <= y_mouse_clickL && y_mouse_clickL <= curr_menu->y_loaction + curr_menu->h_menu_height) {
					curr_menu->active = true;
					controler = curr_menu->name_h_menu;
				}
				else {
					curr_menu->active = false;
				}

			}
			else {
				curr_menu->active = false;
			}
			if (curr_menu->active == true) {
				drawRectangle(render, curr_menu->x_location, curr_menu->y_loaction, curr_menu->h_menu_width, curr_menu->h_menu_height, { 30,30,30,40 });
				drawText(render, curr_menu->x_location + 30, curr_menu->y_loaction + 15, curr_menu->name_h_menu, Consola_13);
				
				if (curr_menu->list_sub_menu != nullptr ) {
					
					// draw sub_menu 
					h_menu curr_menu_1 = curr_menu->list_sub_menu;
					while (curr_menu_1->list_sub_menu != nullptr) {
						if (curr_menu_1->x_location <= x_mouse_clickR && x_mouse_clickR <= curr_menu_1->x_location + curr_menu_1->h_menu_width) {
							if (curr_menu_1->y_loaction <= y_mouse_clickR && y_mouse_clickR <= curr_menu_1->y_loaction + curr_menu_1->h_menu_height) {
								curr_menu_1->houver = true;
								controller_s = curr_menu_1->name_h_menu;
							}
							else {
								curr_menu_1->houver = false;
								
							}

						}
						else {
							curr_menu_1->houver = false;
							
						}
						if(curr_menu_1->houver== false){
							drawRectangle(render, curr_menu_1->x_location, curr_menu_1->y_loaction, curr_menu_1->h_menu_width, curr_menu_1->h_menu_height, { 60,60,60,0 });
						    drawText(render, curr_menu_1->x_location + 10, curr_menu_1->y_loaction + 15, curr_menu_1->name_h_menu, Consola_13);
							
						}
						else {
							drawRectangle(render, curr_menu_1->x_location, curr_menu_1->y_loaction, curr_menu_1->h_menu_width, curr_menu_1->h_menu_height, { 30,30,30,0 });
							drawText(render, curr_menu_1->x_location + 10, curr_menu_1->y_loaction + 15, curr_menu_1->name_h_menu, Consola_13);
							
						}
						
						
						curr_menu_1 = curr_menu_1->list_sub_menu;
					}

				}
				curr_menu = curr_menu->next_h_menu;
			}
			else
			{
				drawRectangle(render, curr_menu->x_location, curr_menu->y_loaction, curr_menu->h_menu_width, curr_menu->h_menu_height, { 60,60,60,0 });
				drawText(render, curr_menu->x_location + 30, curr_menu->y_loaction + 15, curr_menu->name_h_menu, Consola_13);
				curr_menu = curr_menu->next_h_menu;
			}
			
		}
		else
		{
			break;
		}

	}

}