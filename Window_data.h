#pragma once
#include"_Window_.h"

static window new_window = new Window;
static menu_bar new_menu_bar = new Menu_bar;

static h_menu file = new H_menu;
static h_menu file_1 = new H_menu;
static h_menu file_2 = new H_menu;
static h_menu file_3 = new H_menu;
static h_menu file_4 = new H_menu;
static h_menu file_5 = new H_menu;
static h_menu file_6 = new H_menu;

static h_menu file_null = new H_menu;

static h_menu _opsition_1 = new H_menu;
static h_menu _opsition_2 = new H_menu;
static h_menu _opsition_3 = new H_menu;
static h_menu _opsition_4 = new H_menu;
static h_menu _opsition_5 = new H_menu;

static h_menu _opsition_11 = new H_menu;
static h_menu _opsition_12 = new H_menu;
static h_menu _opsition_13 = new H_menu;
static h_menu _opsition_14 = new H_menu;
static h_menu _opsition_15 = new H_menu;
static h_menu _opsition_16 = new H_menu;

static h_menu _opsition_21 = new H_menu;
static h_menu _opsition_22 = new H_menu;
static h_menu _opsition_23 = new H_menu;
static h_menu _opsition_24 = new H_menu;
static h_menu _opsition_25 = new H_menu;
static h_menu _opsition_26 = new H_menu;

static h_menu _opsition_31 = new H_menu;
static h_menu _opsition_32 = new H_menu;
static h_menu _opsition_33 = new H_menu;
static h_menu _opsition_34 = new H_menu;
static h_menu _opsition_35 = new H_menu;
static h_menu _opsition_36 = new H_menu;

static h_menu _opsition_41 = new H_menu;
static h_menu _opsition_42 = new H_menu;
static h_menu _opsition_43 = new H_menu;
static h_menu _opsition_44 = new H_menu;
static h_menu _opsition_45 = new H_menu;
static h_menu _opsition_46 = new H_menu;

void init_menu() {

	new_window->window_tab = file_1_tab;

	set_h_menu(file, "File", nullptr);
	set_h_menu(file_1, "Employee", nullptr);
	set_h_menu(file_2, "Project", nullptr);
	set_h_menu(file_3, "Emp Prj", nullptr);
	set_h_menu(file_4, "Search", nullptr);
	set_h_menu(file_5, "Help", nullptr);
	set_h_menu(file_6, "Window", nullptr);
	set_h_menu(file_null, "null", nullptr);

	set_h_menu(_opsition_1, "Opsition 1", nullptr);
	set_h_menu(_opsition_2, "Opsition 2", nullptr);
	set_h_menu(_opsition_3, "Opsition 3", nullptr);
	set_h_menu(_opsition_4, "Opsition 4", nullptr);

	set_h_menu(_opsition_11, "Add", nullptr);
	set_h_menu(_opsition_12, "Edit", nullptr);
	set_h_menu(_opsition_13, "Remove", nullptr);
	set_h_menu(_opsition_14, "Save", nullptr);
	set_h_menu(_opsition_15, "Opsition 14", nullptr);

	set_h_menu(_opsition_21, "Add", nullptr);
	set_h_menu(_opsition_22, "Edit", nullptr);
	set_h_menu(_opsition_23, "Remove", nullptr);
	set_h_menu(_opsition_24, "Save", nullptr);
	set_h_menu(_opsition_25, "Opsition 14", nullptr);

	set_h_menu(_opsition_31, "Add", nullptr);
	set_h_menu(_opsition_32, "Edit", nullptr);
	set_h_menu(_opsition_33, "Remove", nullptr);
	set_h_menu(_opsition_34, "Save", nullptr);
	set_h_menu(_opsition_35, "Opsition 14", nullptr);

	set_h_menu(_opsition_41, "Search Emp", nullptr);
	set_h_menu(_opsition_42, "Search Prj", nullptr);
	set_h_menu(_opsition_43, "Search E_P", nullptr);
	set_h_menu(_opsition_44, "Save", nullptr);
	set_h_menu(_opsition_45, "Null", nullptr);
	
	add_next_h_menu(file, file_1);
	add_next_h_menu(file, file_2);
	add_next_h_menu(file, file_3);
	add_next_h_menu(file, file_4);
	add_next_h_menu(file, file_5);
	add_next_h_menu(file, file_6);
	add_next_h_menu(file, file_null);

	add_sub_menu(file, _opsition_1);
	add_sub_menu(file, _opsition_2);
	add_sub_menu(file, _opsition_3);
	add_sub_menu(file, _opsition_4);

	add_sub_menu(file_1, _opsition_11);
	add_sub_menu(file_1, _opsition_12);
	add_sub_menu(file_1, _opsition_13);
	add_sub_menu(file_1, _opsition_14);
	add_sub_menu(file_1, _opsition_15);

	add_sub_menu(file_2, _opsition_21);
	add_sub_menu(file_2, _opsition_22);
	add_sub_menu(file_2, _opsition_23);
	add_sub_menu(file_2, _opsition_24);
	add_sub_menu(file_2, _opsition_25);

	add_sub_menu(file_3, _opsition_31);
	add_sub_menu(file_3, _opsition_32);
	add_sub_menu(file_3, _opsition_33);
	add_sub_menu(file_3, _opsition_34);
	add_sub_menu(file_3, _opsition_35);

	add_sub_menu(file_4, _opsition_41);
	add_sub_menu(file_4, _opsition_42);
	add_sub_menu(file_4, _opsition_43);
	add_sub_menu(file_4, _opsition_44);
	add_sub_menu(file_4, _opsition_45);


	add_menu_bar(new_window, new_menu_bar);
	add_items_list_to_menu_bar(new_menu_bar, file);

}