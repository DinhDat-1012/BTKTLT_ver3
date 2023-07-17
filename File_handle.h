#pragma once
#include <fstream>
#include "Var_def.h"
#include <string>
#include "Employee_project.h"

static employee record_list = new Employee;
static project prj_record_list = new Project;
static emp_prj e_p_list = new Emp_Prj;
bool check_date(std:: string data) {
    return true;
}
int get_date(std::string data) {
    int return_value = 0;
    for (int i = 0; i <= data.size(); i++) {

    }
    return return_value;
}

void employee_data_solution(std::string data, employee list_record) {
    std::string code = get_string_between("<code>", "</code>", data);
    std::string name = get_string_between("<name>", "</name>", data);
    std::string sex = get_string_between("<sex>", "</sex>", data);
    std::string dob = get_string_between("<dob>", "</dob>", data);
    add_record(record_list, create_new_record(code, name, sex, dob));

}
void project_data_solution(std::string data, project list_record) {
    std::string code = get_string_between("<code>", "</code>", data);
    std::string name = get_string_between("<name>", "</name>", data);
    std::string begin = get_string_between("<begin>", "</begin>", data);
    std::string end = get_string_between("<end>", "</end>", data);
    std::string cost = get_string_between("<cost>", "</cost>", data);
    add_prj_record(prj_record_list, create_new_prj_record(code, name, begin, end, cost));
}
void  emp_proj_data_solution(std::string data, emp_prj list_record) {
    std::string name = get_string_between("<name>", "</name>", data);
    std::string project_ = get_string_between("<project>", "</project>", data);
    std::string role = get_string_between("<role>", "</role>", data);
    add_ep_record(e_p_list, create_new_ep_record(project_, name, role));
}


void Readfile() {

    std::ifstream inFileNV("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\NV.bin", std::ios::binary);
    std::ifstream inFileDT("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\DT.bin", std::ios::binary);
    std::ifstream inFileNVDT("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\NVDT.bin", std::ios::binary);
    if (!inFileNV) {
        write_log_file(log_string_1 + "Status : Failed opened file NV.bin : Error code: 001FCO\n");
        write_log_file(log_string_1 + "Link : 'E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\NV.bin' \n");
        return;
    }
    else if (!inFileDT) {
        write_log_file(log_string_1 + "Status : Failed opened file DT.bin : Error code: 001FCO\n");
        write_log_file(log_string_1 + "Link : 'E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\DT.bin' \n");
        return;
    }
    else if (!inFileNVDT) {
        write_log_file(log_string_1 + "Status : Failed opened file NVDT.bin : Error code: 001FCO\n");
        write_log_file(log_string_1 + "Link : 'E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\NVDT.bin' \n");
        return;
    }
    else {
        write_log_file(log_string_1 + "Status: Open File NV.bin successfuly.\n");
        write_log_file(log_string_1 + "Status: Open File DT.bin successfuly.\n");
        write_log_file(log_string_1 + "Status: Open File NVDT.bin successfuly.\n");
    }

    std::string line;
    while (std::getline(inFileNV, line)) {
        employee_data_solution(line, record_list);
    }
    while (std::getline(inFileDT, line)) {
        project_data_solution(line, prj_record_list);
    }
    while (std::getline(inFileNVDT, line)) {
        emp_proj_data_solution(line, e_p_list);
    }

    inFileNV.close();
    inFileDT.close();
    inFileNVDT.close();
    write_log_file(log_string_1 + "Status: Close File NV.bin successfuly.\n");
    write_log_file(log_string_1 + "Status: Close File DT.bin successfuly.\n");
    write_log_file(log_string_1 + "Status: Close File NVDT.bin successfuly.\n");
}
void Write_file() {
    std::ofstream outFileNV("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\test.bin", std::ios::app);
    std::ofstream outFileDT("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\test.bin", std::ios::app);
    std::ofstream outFileNVDT("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\test.bin", std::ios::app);

    std::string out_line_NV = "";
    std::string out_line_DT = "";
    std::string out_line_NVDT = "";

    if (outFileNV.is_open()) {
        employee curr_record = record_list->next_record;
        while (curr_record->next_record != nullptr) {
            out_line_NV += "<code>" + curr_record->emp_code + "</code>";
            out_line_NV += "<name>" + curr_record->emp_name + "</name>";
            out_line_NV += "<sex>" + curr_record->emp_sex + "</sex>";
            out_line_NV += "<dob>" + curr_record->emp_dob + "</dob>\n";
            outFileNV.write(out_line_NV.c_str(), out_line_NV.size());

            curr_record = curr_record->next_record;
            out_line_NV = "";
        }

        out_line_NV = "";
        out_line_NV += "<code>" + curr_record->emp_code + "</code>";
        out_line_NV += "<name>" + curr_record->emp_name + "</name>";
        out_line_NV += "<sex>" + curr_record->emp_sex + "</sex>";
        out_line_NV += "<dob>" + curr_record->emp_dob + "</dob>\n";
        outFileNV.write(out_line_NV.c_str(), out_line_NV.size());

        outFileNV.close();
    }
    else {
        std::cout << "Failed to create binary file." << std::endl;
    }


    if (outFileDT.is_open()) {
        project curr_record = prj_record_list->next_project_record;
        while (curr_record->next_project_record != nullptr) {
            out_line_DT += "<code>" + curr_record->project_code + "</code>";
            out_line_DT += "<name>" + curr_record->project_name + "</name>";
            out_line_DT += "<begin>" + curr_record->year_begin + "</begin>";
            out_line_DT += "<end>" + curr_record->year_end + "</end>";
            out_line_DT += "<cost>" + curr_record->project_cost + "</cost>\n";
            outFileDT.write(out_line_DT.c_str(), out_line_DT.size());

            curr_record = curr_record->next_project_record;
            out_line_DT = "";
        }

        out_line_DT = "";
        out_line_DT += "<code>" + curr_record->project_code + "</code>";
        out_line_DT += "<name>" + curr_record->project_name + "</name>";
        out_line_DT += "<begin>" + curr_record->year_begin + "</begin>";
        out_line_DT += "<end>" + curr_record->year_end + "</end>";
        out_line_DT += "<cost>" + curr_record->project_cost + "</cost>\n";
        outFileDT.write(out_line_DT.c_str(), out_line_DT.size());

        outFileDT.close();
    }
    else {
        std::cout << "Failed to create binary file." << std::endl;
    }


    if (outFileNVDT.is_open()) {
        emp_prj curr_record = e_p_list->next_record;
        while (curr_record->next_record != nullptr) {
            out_line_NVDT += "<name>" + curr_record->employ_name + "</name>";
            out_line_NVDT += "<project>" + curr_record->project_name + "</project>";
            out_line_NVDT += "<role>" + curr_record->role + "</role>\n";
            outFileNVDT.write(out_line_NVDT.c_str(), out_line_NVDT.size());

            curr_record = curr_record->next_record;
            out_line_DT = "";
        }

        out_line_DT = "";
        out_line_NVDT += "<name>" + curr_record->employ_name + "</name>";
        out_line_NVDT += "<project>" + curr_record->project_name + "</project>";
        out_line_NVDT += "<role>" + curr_record->role + "</role>\n";
        outFileNVDT.write(out_line_NVDT.c_str(), out_line_NVDT.size());

        outFileDT.close();
    }
    else {
        std::cout << "Failed to create binary file." << std::endl;
    }

}

void Format_file() {
    std::ofstream outFileNV("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\test.bin", std::ios::binary);
    std::ofstream outFileDT("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\test.bin", std::ios::binary);
    std::ofstream outFileNVDT("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\test.bin", std::ios::binary);

    outFileNV.close();
    outFileDT.close();
    outFileDT.close();
}
void add_employee_record_with_input(std::string input_text, employee record_list) {
    std::string code = get_string_between("<code>", "</code>", input_text);
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string sex = get_string_between("<sex>", "</sex>", input_text);
    std::string dob = get_string_between("<dob>", "</dob>", input_text);
    employee check_record = nullptr;
    check_record = find_record_by_code(record_list,code);
   
    if (check_record == nullptr && code != " " && dob!= " " && sex!= " ") {
        if (sex == "male" || sex == "female" || sex == "Male" || sex == "Female") {
      add_record(record_list, create_new_record(code, name, sex, dob));
      write_log_file(log_string_1 + "Status: Successfuly added new employee record : <" + code + ">" );
        }
        else {
        write_log_file(log_string_1 + "Status: Failed added new employee record : <" + code + ">" + ": Error code: 0001F");
        }
      
    }
    else {
        write_log_file(log_string_1 + "Status: Failed added new employee record : <" + code + ">" + ": Error code: 0002F");
    }
}
void edit_employee_record(std::string input_text, employee record_list) {
    std::string code = get_string_between("<code>", "</code>", input_text);
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string sex = get_string_between("<sex>", "</sex>", input_text);
    std::string dob = get_string_between("<dob>", "</dob>", input_text);
    employee check_record = nullptr;
    check_record = find_record_by_code(record_list, code);
    if (check_record != nullptr && code != " " && dob != " " && sex != " ") {
        if (sex == "male" || sex == "female"||sex == "Male" ||sex == "Female\n") {
        check_record->emp_name = name;
        check_record->emp_sex = sex;
        check_record->emp_dob = dob;
        write_log_file(log_string_1 + "Status: Successfuly edited new employee record : <" + code + ">\n");
        }
        else {
        write_log_file(log_string_1 + "Status: Failed edited new employee record : <" + code + ">" + ": Error code: 0001F\n");
        }
       
    }
    else {
        write_log_file(log_string_1 + "Status: Failed edited new employee record : <" + code + ">" + ": Error code: 0003F\n");
    }

}
void remove_employee_record(std::string input_text, employee record_list) {
    std::string code = get_string_between("<code>", "</code>", input_text);
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string sex = get_string_between("<sex>", "</sex>", input_text);
    std::string dob = get_string_between("<dob>", "</dob>", input_text);
    employee check_record = nullptr;
    check_record = find_record_by_code(record_list, code);
    if (check_record != nullptr ) {
        write_log_file(log_string_1 + "Status: Successfuly removed new employee record : <" + code + ">\n");
        remove_record_bycode(record_list, code);
    }
    else {
        write_log_file(log_string_1 + "Status: Failed removed new employee record : <" + code + ">\n");
    }
}
void add_new_project(std::string input_text, project prj_list_record) {
    std::string code = get_string_between("<code>", "</code>", input_text);
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string begin = get_string_between("<begin>", "</begin>", input_text);
    std::string end = get_string_between("<end>", "</end>", input_text);
    std::string cost = get_string_between("<cost>", "</cost>", input_text);
    project check_project = nullptr;
    check_project = find_prj_record_by_code(prj_list_record, code);

    if (check_project == nullptr && name != " " && begin != " " &&  end != " " &&  cost != " ") {
           add_prj_record(prj_record_list, create_new_prj_record(code, name, begin, end, cost));
           write_log_file(log_string_1 + "Status: Successfuly added new project record : Code: <" + code + ">\n");
    }
    else {
           write_log_file(log_string_1 + "Status: Failed added new employee record : Code: <" + code + ">\n");
    }
    
}
void edit_project(std::string input_text, project prj_record_list) {
    std::string code = get_string_between("<code>", "</code>", input_text);
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string begin = get_string_between("<begin>", "</begin>", input_text);
    std::string end = get_string_between("<end>", "</end>", input_text);
    std::string cost = get_string_between("<cost>", "</cost>", input_text);
    project check_project = nullptr;
    check_project = find_prj_record_by_code(prj_record_list, code);
    if (check_project == nullptr && name != " " && begin != " " && end != " " && cost != " ") {
        check_project->project_name = name;
        check_project->year_begin = begin;
        check_project->year_end = end;
        check_project->project_cost = cost;
        write_log_file(log_string_1 + "Status: Successfuly edited project record : <" + code + ">\n");
    }
    else {
        write_log_file(log_string_1 + "Status: Failed edited project record : <" + code + ">\n");
    }

}
void remove_project(std::string input_text, project prj_record_list) {
    std::string code = get_string_between("<code>", "</code>", input_text);
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string begin = get_string_between("<begin>", "</begin>", input_text);
    std::string end = get_string_between("<end>", "</end>", input_text);
    std::string cost = get_string_between("<cost>", "</cost>", input_text);
    project check_project = nullptr;
    check_project = find_prj_record_by_code(prj_record_list, code);
    if (check_project != nullptr) {
        write_log_file(log_string_1 + "Status: Successfuly removed  employee record : Code: <" + code + ">\n");
        remove_prj_record_bycode(prj_record_list, code);
    }
    else {
        write_log_file(log_string_1 + "Status: Failed remove project record : Code: <" + code + ">\n");
    }
}
void add_ep(std::string input_text,emp_prj ep_lisst) {
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string project_ = get_string_between("<project>", "</project>", input_text);
    std::string role = get_string_between("<role>", "</role>", input_text);
    project check_project = nullptr;
    employee check_employee = nullptr;
    check_project = find_prj_record_by_name(prj_record_list,project_);
    check_employee =  find_record_by_name(record_list, name);
    if (check_employee!= nullptr && check_project != nullptr && role != " ") {
        write_log_file(log_string_1 + "Status: Sucessfuly added employee project record : Name: <" + name + ">\n");
     add_ep_record(e_p_list, create_new_ep_record(project_, name, role));
    }
    else {
        write_log_file(log_string_1 + "Status: Failed added employee project record : Name: <" + name + ">\n");
    }
    
}
void edit_ep(std::string input_text, emp_prj ep_lisst) {
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string project_ = get_string_between("<project>", "</project>", input_text);
    std::string role = get_string_between("<role>", "</role>", input_text);
    project check_project = nullptr;
    employee check_employee = nullptr;
    check_project = find_prj_record_by_name(prj_record_list, project_);
    check_employee = find_record_by_name(record_list, name);

    emp_prj check_ep = find_record_by_project_name(e_p_list, project_);

    if (check_employee != nullptr && check_project != nullptr && check_ep != nullptr) {
        check_ep->role = role;
       
        write_log_file(log_string_1 + "Status: Succesfuly edited employee project record : Name: <" + name + ">\n");
    }
    else {
        write_log_file(log_string_1 + "Status: Failed edited project record : Name: <" + name + ">\n");
    }
}
void remove_ep(std::string input_text, emp_prj e_p_list) {
    std::string name = get_string_between("<name>", "</name>", input_text);
    std::string project_ = get_string_between("<project>", "</project>", input_text);
    std::string role = get_string_between("<role>", "</role>", input_text);
    project check_project = nullptr;
    employee check_employee = nullptr;
    check_project = find_prj_record_by_name(prj_record_list, project_);
    check_employee = find_record_by_name(record_list, name);

    emp_prj check_ep = find_record_by_project_name(e_p_list, project_);

    if (check_ep != nullptr) {
        write_log_file(log_string_1 + "Status: Succesfuly remove employee project record : Name: <" + name + ">\n");
        remove_EPrecord_by_name(e_p_list,check_ep->project_name);
    }
    else {
        write_log_file(log_string_1 + "Status: Failed edited employee project record : Name: <" + name + ">\n");
    }
}
void save() {
    Format_file();
    Write_file();
}