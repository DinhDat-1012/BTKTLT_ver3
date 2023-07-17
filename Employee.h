#pragma once
#include <iostream>
#include <string>

//stack list
#define employee Employee*

struct Employee {
	std::string emp_code = "";
	std::string emp_name = "";
	std::string emp_sex = "";
	std::string emp_dob = "";

	employee next_record = nullptr;

};


bool check_empty_list(employee head_record) {
	if (head_record->next_record == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

employee create_new_record(std::string code, std::string name, std::string sex, std::string dob) {
	employee new_record = new Employee();

	new_record->emp_code = code;
	new_record->emp_name = name;
	new_record->emp_sex = sex;
	new_record->emp_dob = dob;

	new_record->next_record = nullptr;

	return new_record;
}
// add_record in tail of list_record

void add_record(employee head_record, employee record) {
	if (check_empty_list(head_record) == true) {
		head_record->next_record = record;
	}
	else {
		employee curr_record = head_record;
		while (curr_record->next_record != nullptr) {
			curr_record = curr_record->next_record;
		}
		curr_record->next_record = record;
	}
}

void print_list_record(employee head_record) {
	if (check_empty_list(head_record) == true) {
		return;
	}
	else {
		employee curr_record = head_record->next_record;
		while (curr_record->next_record != nullptr) {
			std::cerr << curr_record->emp_name << std::endl;
			curr_record = curr_record->next_record;
		}
		std::cerr << curr_record->emp_name << std::endl;

	}
}
employee find_record_by_code(employee head_record, std::string code) {
	if (check_empty_list(head_record) == true) {
		return nullptr;
	}
	else {
		employee curr_record = head_record->next_record;
		while (curr_record->next_record != nullptr)
		{
			if (curr_record->emp_code == code) {
				return curr_record;
			}
			curr_record = curr_record->next_record;
		}
		if (curr_record->emp_code == code) {
			return curr_record;
		}
		else {
			return nullptr;
		}
	}
}

employee find_record_by_name(employee head_record, std::string name) {
	if (check_empty_list(head_record) == true) {
		return nullptr;
	}
	else {
		employee curr_record = head_record->next_record;
		while (curr_record->next_record != nullptr)
		{
			if (curr_record->emp_name == name) {
				return curr_record;
			}
			curr_record = curr_record->next_record;
		}
		if (curr_record->emp_name == name) {
			return curr_record;
		}
		else {
			return nullptr;
		}
	}
}
void remove_record_bycode(employee head_record, std::string code) {
	if (head_record == nullptr) {
		return;
	}
	else {
		employee curr_record = head_record->next_record;
		employee temp = head_record;
		while (curr_record->next_record != nullptr) {
			if (curr_record->emp_code == code) {
				employee temp_2 = curr_record;
				temp->next_record = curr_record->next_record;
				delete temp_2;
				return;
			}
			curr_record = curr_record->next_record;
			temp = temp->next_record;
		}
		if (temp->next_record->emp_code == code) {
			temp->next_record = nullptr;
			delete curr_record;
		}
	}

}
void remove_record_byname(employee head_record, std::string name) {
	if (head_record == nullptr) {
		return;
	}
	else {
		employee curr_record = head_record->next_record;
		employee temp = head_record;
		while (curr_record->next_record != nullptr) {
			if (curr_record->emp_name == name) {
				employee temp_2 = curr_record;
				temp->next_record = curr_record->next_record;
				delete temp_2;
				return;
			}
			curr_record = curr_record->next_record;
			temp = temp->next_record;
		}
		if (temp->next_record->emp_name == name) {
			temp->next_record = nullptr;
			delete curr_record;
		}
	}

}
void set_information(employee record_list, std::string code, std::string new_name, std::string new_sex, std::string new_date_o_birth) {
	employee curr_record = find_record_by_code(record_list, code);
	curr_record->emp_name = new_name;
	curr_record->emp_sex = new_sex;
	curr_record->emp_dob = new_date_o_birth;
}
void add_eployee_record(employee record_list, std::string data_in) {

}