#include "Var_def.h"
#include "Text_render.h"
#include "draw_object.h"
#include "Mouse_event.h"
#include "Window_data.h"

int main(int argc,char* args[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    init_menu();
    Readfile();

    init_font_file();
    SDL_Window* _window_ = SDL_CreateWindow("Quan li du an.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Default_screen_width, Default_screen_height, SDL_WINDOW_SHOWN);
    static  SDL_Renderer* renderer = SDL_CreateRenderer(_window_, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    bool quit = false;
    write_log_file(log_string_1 + "Status : Open program sucessfuly.");
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                   x_mouse_clickL = event.button.x;
                   y_mouse_clickL = event.button.y;
                }
                if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    x_mouse_clickR = event.button.x;
                    y_mouse_clickR = event.button.y;
                }
            }
            if (event.type == SDL_TEXTINPUT)
            {
                // Lấy ký tự đã nhập từ bàn phím
                std::string text = event.text.text;

                // Thêm ký tự vào chuỗi
                input_text += text;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_RETURN)
                {
                    
                    confim = true;  
                }
                else if (event.key.keysym.sym == SDLK_BACKSPACE && !input_text.empty())
                {
                    if (input_text != "_") {
                        input_text.pop_back();
                    }
                }
            }
            
            get_mouse_location();
           

        }
        get_time_system();
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 50); 
        SDL_RenderClear(renderer); 
        //ve doi tuong.
        // drawRectangle(renderer, 0,0, 1240, 70,VIOLET_1);
        // drawText(renderer, 20, 50, "Hello, SDL!", Time);
        draw_window(renderer, new_window);
        drawText(renderer, 1150, 10, convertUint32ToChar(Time_process), Time_15);
        draw_black_Text(renderer, 1070, 690, time_system.c_str(), Time_15);
        draw_black_Text(renderer, 1160, 690, date_system.c_str(), Time_15);

        get_time_process(&Time_process);
        SDL_RenderPresent(renderer);
        get_log_string_1();
    }
  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window_);
    SDL_Quit();
    write_log_file(log_string_1 + "Status : Close program sucessfuly.");
    return 0;
}