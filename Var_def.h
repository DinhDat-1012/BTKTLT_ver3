#pragma once
#include "SDL_ttf.h"
#include "SDL.h"
#include "iostream"
#include"string"
#include <ctime>
#include <fstream>

#define _CTR_SECURE_NO_WARNINGS

#ifndef TEXT
#define TEXT const char*
#endif // !TEXT

static std::string time_system = "";
static std::string date_system = "";
static std::string log_string_1 = " ";
static std::string log_string_2 = "Save file Succeed !! ";

void get_log_string_1() {
    log_string_1 = "Time: " + time_system + " " + date_system + " : ";
}
static int x_mouse_location = -1;
static int y_mouse_location = -1;
static int x_mouse_clickL = -1;
static int y_mouse_clickL = -1;
static int x_mouse_clickR = -1;
static int y_mouse_clickR = -1;

static TTF_Font* Time_13 = nullptr;
static TTF_Font* Time_15 = nullptr;
static TTF_Font* Time_17 = nullptr;
static TTF_Font* Time_19 = nullptr;
static TTF_Font* Time_21 = nullptr;
static TTF_Font* Time_22 = nullptr;
static TTF_Font* Time_23 = nullptr;
static TTF_Font* Time_24 = nullptr;

static TTF_Font* Consola_7= nullptr;
static TTF_Font* Consola_10 = nullptr;
static TTF_Font* Consola_13 = nullptr;
static TTF_Font* Consola_16 = nullptr;
static TTF_Font* Consola_17 = nullptr;
static TTF_Font* Consola_18 = nullptr;
static TTF_Font* Consola_19 = nullptr;
static TTF_Font* Consola_20 = nullptr;
static TTF_Font* Consola_21 = nullptr;
static TTF_Font* Consola_22 = nullptr;
static TTF_Font* Consola_28 = nullptr;

static std::string controler = "Null";
static std::string controller_s = "Null";

static std::string input_text = "_";
static bool confim = false;               // dung xong nho tra lai ve false.

#ifndef Default_sceen_width
#define Default_screen_width (int)1240
#endif 
#ifndef Default_sceen_height
#define Default_screen_height (int)720
#endif 
#define default_menu_bar_width (int)1240
#define default_menu_bar_height (int)40

static SDL_Color WHITE = { 255,255,255,255 };
static SDL_Color BLACK = { 0,0,0,0 };
static SDL_Color BLUE_1 = { 0,255,255,255 };
static SDL_Color BLUE_2 = { 153,255,255,255 };
static SDL_Color BLUE_3 = { 51,51,85,255 };
static SDL_Color BLUE_4 = { 153,153,255,255 };
static SDL_Color VIOLET_0 = { 204,153,255,255 };
static SDL_Color VIOLET_1 = { 255,153,255,255 };
static SDL_Color VIOLET_2 = { 153,0,255,255 };
static SDL_Color PINK_0 = { 255,204,109,255 };
static SDL_Color PINK_1 = { 255,104,104,255 };
static SDL_Color DEFAULT_h_menu_COLOR = { 30,30,30,0 };

static Uint32 Time_process = 0;
static Uint32 Time_start_process = 0;
//thoi gian chay he thong.
char* convertUint32ToChar(Uint32 value)
{
	std::string strValue = std::to_string(value);
	strValue.append("ms");
	char* charValue = new char[strValue.length() + 1];
	strcpy_s(charValue, strValue.length() + 1, strValue.c_str());

	return charValue ;
}
void get_time_process(Uint32 *time_process) {
	Uint32 endTime = SDL_GetTicks();
	*time_process = (endTime - Time_start_process)/10;
}
std::string get_string_between(std::string start, std::string end, std::string text) {
    int size_start_str = start.length();
    int size_end_str = end.length();

    size_t start_a = text.find(start);
    size_t end_a = text.find(end);

    if (start_a == std::string::npos || end_a == std::string::npos) {
        return "";
    }
    else {
        start_a += start.length();
        return text.substr(start_a, end_a - start_a);
    }
}
void get_time_system() {

    std::time_t currentTime;
    std::time(&currentTime);

    std::tm localTime;
    localtime_s(&localTime, &currentTime);

    int date = localTime.tm_mday;
    int month = localTime.tm_mon;
    int year = localTime.tm_year;
    int hour = localTime.tm_hour;
    int minute = localTime.tm_min;
    int second = localTime.tm_sec;

    std::string time_sys;
    time_sys += std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    time_system = time_sys;
    if (hour <= 11) {
        time_system += " AM";
    }
    else
    {
        time_system += " PM";
    }
    std::string date_sys = "";
    date_sys += std::to_string(month + 1) + "/" + std::to_string(date) +"/" + std::to_string(year+1900);
    date_system = date_sys;
}
void write_log_file(std::string log_string) {
    std::string log_out = " ";
    log_out = log_string + "\n";
    std::ofstream log("E:\\BT_KTLT_III\\BTKTLT_ver3\\Data\\log.txt", std::ios::app);
    if (log.is_open()) {
        log.write(log_out.c_str(), log_out.size());
    }

    log.close();
}