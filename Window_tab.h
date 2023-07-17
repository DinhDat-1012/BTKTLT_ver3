#pragma once
#include"Var_def.h"
#include<vector>
#include <string>
#include "draw_object.h"
#include "Text_render.h"
#include "File_handle.h"

#define w_tab Window_tab*
#define input_text_box Input_text_box*
struct Window_tab {
	std::vector <std::string> line_display;
	Uint32 line_display_width = default_menu_bar_width;
	Uint32 line_display_height = 30;

	SDL_Color line_color;
};

static w_tab file_1_tab = new Window_tab;
static w_tab file_2_tab = new Window_tab;
static w_tab file_3_tab = new Window_tab;

struct Input_text_box {
	Uint32 x_location = 80;
	Uint32 y_location = 640;

	Uint32 button_x_location = 0;
	Uint32 button_y_location = 0;

	SDL_Color color = PINK_0;
};
static input_text_box in_text_box = new Input_text_box;
void draw_information_employee(SDL_Renderer* render) {
	employee curr_record = record_list;
	TEXT out = " ";
	int i_code = 3;
	int i_name = 3;
	int i_sex = 3;
	int i_dob = 3;
	while (curr_record->next_record != nullptr)
	{

		std::string line_out = "";
		curr_record = curr_record->next_record;
		line_out = "Code: " + curr_record->emp_code + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 30, i_code * 20, out, Time_21);
		i_code++;

	}
	curr_record = record_list;
	while (curr_record->next_record != nullptr)
	{

		std::string line_out = "";
		curr_record = curr_record->next_record;
		line_out = "Name: " +curr_record->emp_name + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 200, i_name * 20, out, Time_21);
		i_name++;

	}
	curr_record = record_list;
	while (curr_record->next_record != nullptr)
	{

		std::string line_out = "";
		curr_record = curr_record->next_record;
		line_out ="Sex: "+ curr_record->emp_sex + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 600, i_sex * 20, out, Time_21);
		i_sex++;

	}
	curr_record = record_list;
	while (curr_record->next_record != nullptr)
	{

		std::string line_out = "";
		curr_record = curr_record->next_record;
		line_out = " Date of Birth: " + curr_record->emp_dob + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 800, i_dob * 20, out, Time_21);
		i_dob++;

	}
}
void draw_project_information(SDL_Renderer* render) {
	project project_list = prj_record_list;
	TEXT out = "";
	int i_code = 3;
	int i_name = 3;
	int i_begin = 3;
	int i_end = 3;
	int i_cost = 3;

	while (project_list->next_project_record != nullptr)
	{

		std::string line_out = "";
		project_list = project_list->next_project_record;
		line_out = "Code: " + project_list->project_code + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 30, i_code * 20, out, Time_21);
		i_code++;

	}
	project_list = prj_record_list;
	while (project_list->next_project_record != nullptr)
	{

		std::string line_out = "";
		project_list = project_list->next_project_record;
		line_out = "Name: " + project_list->project_name + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 200, i_name * 20, out, Time_21);
		i_name++;

	}
	project_list = prj_record_list;
	while (project_list->next_project_record != nullptr)
	{

		std::string line_out = "";
		project_list = project_list->next_project_record;
		line_out = "Begin: " + project_list->year_begin + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 550, i_begin * 20, out, Time_21);
		i_begin++;

	}
	project_list = prj_record_list;
	while (project_list->next_project_record != nullptr)
	{

		std::string line_out = "";
		project_list = project_list->next_project_record;
		line_out = "End: " + project_list->year_end + "           ";
		out = line_out.c_str();
		draw_black_Text(render, 750, i_end * 20, out, Time_21);
		i_end++;

	}
	project_list = prj_record_list;
	while (project_list->next_project_record != nullptr)
	{

		std::string line_out = "";
		project_list = project_list->next_project_record;
		line_out = "Cost: " + project_list->project_cost + " VND ";
		out = line_out.c_str();
		draw_black_Text(render, 950, i_cost * 20, out, Time_21);
		i_cost++;

	}

}
void draw_input_text_box(SDL_Renderer* render) {

	drawRectangle(render, in_text_box->x_location, in_text_box->y_location, 1000, 30, PINK_0);
	draw_black_Text(render, in_text_box->x_location + 15, in_text_box->y_location + 5, input_text.c_str(), Time_19);

	drawRectangle(render, in_text_box->x_location +1030, in_text_box->y_location, 50 , 30, PINK_1);
	draw_black_Text(render, in_text_box->x_location + 1030 + 15, in_text_box->y_location + 5, "ok" , Time_19);
	
}
void draw_e_p_inforamtion(SDL_Renderer* render) {
	emp_prj record = e_p_list;
	TEXT out = "";
	int i_name = 3;
	int i_prj = 3;
	int i_role = 3;

	while (record->next_record != nullptr)
	{

		std::string line_out = "";
		record = record->next_record;
		line_out = "Project: " + record->project_name + "   ";
		out = line_out.c_str();
		draw_black_Text(render, 50, i_prj * 20, out, Time_21);
		i_prj++;

	}
	record = e_p_list;
	while (record->next_record != nullptr)
	{

		std::string line_out = "";
		record = record->next_record;
		line_out = "Name: " + record->employ_name + "   ";
		out = line_out.c_str();
		draw_black_Text(render, 450, i_name * 20, out, Time_21);
		i_name++;

	}
	record = e_p_list;
	while (record->next_record != nullptr)
	{

		std::string line_out = "";
		record = record->next_record;
		line_out = "Role: " + record->role + "   ";
		out = line_out.c_str();
		draw_black_Text(render, 800, i_role * 20, out, Time_21);
		i_role++;

	}
	
}
void draw_help_tab(SDL_Renderer* render) {
	TEXT out = "Createed By Dinh Duc Dat 14/7/2023 ";
	draw_black_Text(render, 30, 60, out, Time_21);
	draw_black_Text(render, 30, 80,  "Github: https://github.com/DinhDat-1012 ", Time_21);
	draw_black_Text(render, 30, 100, "Facebook: https://www.facebook.com/profile.php?id=100047739422168 ", Time_21);
	draw_black_Text(render, 30, 120, "Mail: dinhdat1012vn@gmail.com ", Time_21);

	draw_black_Text(render, 30, 160, "List library: ", Time_21);

	draw_black_Text(render, 150, 180, " SDL_tft.h", Time_21);
	draw_black_Text(render, 150, 200, " SDL.h ", Time_21);
	draw_black_Text(render, 150, 220, " String ", Time_21);
	draw_black_Text(render, 150, 240, " Iostream ", Time_21);
	draw_black_Text(render, 150, 260, " Vector ", Time_21);
	draw_black_Text(render, 150, 280, " Ofstream.h ", Time_21);
	
	
	
	
}
void draw_w_tab(SDL_Renderer* render, w_tab handle_to_w_tab,std::string controller,std::string control_2) {

	drawRectangle(render, 0, default_menu_bar_height, 1240, 720, { 191,202,230,20 });
	if(controller == "Null") {

	}
	if (controler == "Employee") {
		draw_information_employee(render);
		if (control_2 == "Edit") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				edit_employee_record(input_text, record_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Add") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				add_employee_record_with_input(input_text, record_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Remove") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				remove_employee_record(input_text,record_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Save") {
			if (confim == true) {
				save();
				write_log_file(log_string_1 + log_string_2);
				input_text = "_";
				confim = false;
			}
			
		}
	}
	if (controller == "Project") {
		draw_project_information(render);
		if (control_2 == "Edit") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				edit_project(input_text, prj_record_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Add") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				add_new_project(input_text, prj_record_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Remove") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				remove_project(input_text, prj_record_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Save") {
			if (confim == true) {
				save();
				write_log_file(log_string_1 + log_string_2);
				input_text = "_";
				confim = false;
			}
			
		}
	}
	if(controller == "Emp Prj") {
		draw_e_p_inforamtion(render);
		if (control_2 == "Edit") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				edit_ep(input_text, e_p_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Add") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				add_ep(input_text, e_p_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Remove") {
			draw_input_text_box(render);
			if (confim == true) {
				// dosome thing.
				remove_ep(input_text, e_p_list);
				input_text = "_";
				confim = false;
			}
		}
		if (control_2 == "Save") {
			if (confim == true) {
				save();
				write_log_file(log_string_1 + log_string_2);
				input_text = "_";
				confim = false;
			}
			
		}
	}
	if (controller == "Help") {
		draw_help_tab(render);
	}
	
	
}