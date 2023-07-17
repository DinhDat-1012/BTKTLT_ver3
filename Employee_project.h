#pragma once
#include "Employee.h"
#include "Project.h"

#pragma once
#include "Employee.h"
#include "Project.h"


#define emp_prj Emp_Prj*
struct Emp_Prj {
	std::string project_name = "";
	std::string employ_name = "";
	std::string role = "";

	emp_prj next_record = nullptr;
};

bool check_empty_ep_list(emp_prj head_record) {
	if (head_record->next_record == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

emp_prj create_new_ep_record(std::string prj_name, std::string emp_name, std::string role) {
	emp_prj new_record = new Emp_Prj;

	new_record->project_name = prj_name;
	new_record->employ_name = emp_name;
	new_record->role = role;

	new_record->next_record = nullptr;

	return new_record;
}
// add_record in tail of list_record

void add_ep_record(emp_prj head_record, emp_prj record) {
	if (check_empty_ep_list(head_record) == true) {
		head_record->next_record = record;
	}
	else {
		emp_prj curr_record = head_record;
		while (curr_record->next_record != nullptr) {
			curr_record = curr_record->next_record;
		}
		curr_record->next_record = record;
	}
}
// Ckeck point 1.
void print_ep_list_record(emp_prj head_record) {
	if (check_empty_ep_list(head_record) == true) {
		return;
	}
	else {
		emp_prj curr_record = head_record->next_record;
		while (curr_record->next_record != nullptr) {
			std::cerr << curr_record->employ_name << "  ";
			std::cerr << curr_record->project_name << std::endl;
			curr_record = curr_record->next_record;
		}
		std::cerr << curr_record->employ_name << "  ";
		std::cerr << curr_record->project_name << std::endl;

	}
}
emp_prj find_record_by_emp_name(emp_prj head_record, std::string name) {
	if (check_empty_ep_list(head_record) == true) {
		return nullptr;
	}
	else {
		emp_prj curr_record = head_record->next_record;
		while (curr_record->next_record != nullptr)
		{
			if (curr_record->employ_name == name) {
				return curr_record;
			}
			curr_record = curr_record->next_record;
		}
		if (curr_record->employ_name == name) {
			return curr_record;
		}
		else {
			return nullptr;
		}
	}
}

emp_prj find_record_by_project_name(emp_prj head_record, std::string name) {
	if (check_empty_ep_list(head_record) == true) {
		return nullptr;
	}
	else {
		emp_prj curr_record = head_record->next_record;
		while (curr_record->next_record != nullptr)
		{
			if (curr_record->project_name == name) {
				return curr_record;
			}
			curr_record = curr_record->next_record;
		}
		if (curr_record->project_name == name) {
			return curr_record;
		}
		else {
			return nullptr;
		}
	}
}
void remove_EPrecord_by_name(emp_prj head_record, std::string name) {
	if (head_record == nullptr) {
		return;
	}
	else {
		emp_prj curr_record = head_record->next_record;
		emp_prj temp = head_record;
		while (curr_record->next_record != nullptr) {
			if (curr_record->project_name == name) {
				emp_prj temp_2 = curr_record;
				temp->next_record = curr_record->next_record;
				delete temp_2;
				return;
			}
			curr_record = curr_record->next_record;
			temp = temp->next_record;
		}
		if (temp->next_record->project_name == name) {
			temp->next_record = nullptr;
			delete curr_record;
		}
	}

}
void set_EP_record_information(emp_prj record_list, std::string name, std::string new_employee_manage, std::string new_role) {
	emp_prj curr_record = find_record_by_project_name(record_list, name);
	curr_record->employ_name = new_employee_manage;
	curr_record->role = new_role;
}
