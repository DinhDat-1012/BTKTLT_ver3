#pragma once
#include <iostream>

#define project Project*
struct Project {
	std::string project_code = "";
	std::string project_name = "";
	std::string year_begin = "";
	std::string year_end = "";
	std::string project_cost = "";

	project next_project_record = nullptr;
};

bool check_empty_prj_list(project head_record) {
	if (head_record->next_project_record == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

project create_new_prj_record(std::string code, std::string name, std::string year_begin, std::string year_end, std::string cost) {
	project new_record = new Project();

	new_record->project_code = code;
	new_record->project_name = name;
	new_record->year_begin = year_begin;
	new_record->year_end = year_end;
	new_record->project_cost = cost;

	new_record->next_project_record = nullptr;

	return new_record;
}
// add_record in tail of list_record

void add_prj_record(project head_record, project record) {
	if (check_empty_prj_list(head_record) == true) {
		head_record->next_project_record = record;
	}
	else {
		project curr_record = head_record;
		while (curr_record->next_project_record != nullptr) {
			curr_record = curr_record->next_project_record;
		}
		curr_record->next_project_record = record;
	}
}

void print_prj_list_record(project head_record) {
	if (check_empty_prj_list(head_record) == true) {
		return;
	}
	else {
		project curr_record = head_record->next_project_record;
		while (curr_record->next_project_record != nullptr) {
			std::cerr << curr_record->project_name << std::endl;
			curr_record = curr_record->next_project_record;
		}
		std::cerr << curr_record->project_name << std::endl;

	}
}
project find_prj_record_by_code(project head_record, std::string code) {
	if (check_empty_prj_list(head_record) == true) {
		return nullptr;
	}
	else {
		project curr_record = head_record->next_project_record;
		while (curr_record->next_project_record != nullptr)
		{
			if (curr_record->project_code == code) {
				return curr_record;
			}
			curr_record = curr_record->next_project_record;
		}
		if (curr_record->project_code == code) {
			return curr_record;
		}
		else {
			return nullptr;
		}
	}
}

project find_prj_record_by_name(project head_record, std::string name) {
	if (check_empty_prj_list(head_record) == true) {
		return nullptr;
	}
	else {
		project curr_record = head_record->next_project_record;
		while (curr_record->next_project_record != nullptr)
		{
			if (curr_record->project_name == name) {
				return curr_record;
			}
			curr_record = curr_record->next_project_record;
		}
		if (curr_record->project_name == name) {
			return curr_record;
		}
		else {
			return nullptr;
		}
	}
}
void remove_prj_record_bycode(project head_record, std::string code) {
	if (head_record == nullptr) {
		return;
	}
	else {
		project curr_record = head_record->next_project_record;
		project temp = head_record;
		while (curr_record->next_project_record != nullptr) {
			if (curr_record->project_code == code) {
				project temp_2 = curr_record;
				temp->next_project_record = curr_record->next_project_record;
				delete temp_2;
				return;
			}
			curr_record = curr_record->next_project_record;
			temp = temp->next_project_record;
		}
		if (temp->next_project_record->project_code == code) {
			temp->next_project_record = nullptr;
			delete curr_record;
		}
	}

}
void remove_prj_record_byname(project head_record, std::string name) {
	if (head_record == nullptr) {
		return;
	}
	else {
		project curr_record = head_record->next_project_record;
		project temp = head_record;
		while (curr_record->next_project_record != nullptr) {
			if (curr_record->project_name == name) {
				project temp_2 = curr_record;
				temp->next_project_record = curr_record->next_project_record;
				delete temp_2;
				return;
			}
			curr_record = curr_record->next_project_record;
			temp = temp->next_project_record;
		}
		if (temp->next_project_record->project_name == name) {
			temp->next_project_record = nullptr;
			delete curr_record;
		}
	}

}
void set_information(project record_list, std::string code, std::string new_name, std::string new_year_begin, std::string new_year_end, std::string project_cosst) {
	project curr_record = find_prj_record_by_code(record_list, code);
	curr_record->project_name = new_name;
	curr_record->year_begin = new_year_begin;
	curr_record->year_end = new_year_end;
	curr_record->project_cost = project_cosst;
}
