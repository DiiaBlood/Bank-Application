// Include necessary files 
#include <iostream>
#include <algorithm>
#include "../include/raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "../include/raygui.h"

using std::cout, std::endl;
namespace windows{
    #include "windows.h"
}

// include other parts of the program
#include "Core.hpp"

// Program's constants
const float WinW = 480.0f;
const float WinH = 480.0f;
const Color WinColor = GRAY;
const char* WinName = "Bank Application - Muktada A. Hatem";


int main(){
    // Load the window
    InitWindow(WinW, WinH, WinName);

    List Notebook;
    for (int i = 0; i < 10; ++i){
    Notebook.Add(i, "Name Goes Here", 0770+(i*10000), "Interesting@Mail.com", "Doctor", 0, 0, "Nahrayen");
    Notebook.Deposite(i, 50000);
    }
    Notebook.Display();
    Notebook.Withdrawal(2, 50000); Notebook.Display();
    Notebook.Transfer(1, 2, 50000); Notebook.Display();
    Notebook.Remove(8); Notebook.Display();

    char buffer[64] = {"Write Here"};
    while (!WindowShouldClose()){
        // PollInputEvents();
        BeginDrawing();
        GuiTextBox({20, 20, 200, 44}, buffer, 64, true);
        // cout << buffer << endl;
        if (IsKeyPressed(KEY_ENTER)){
            Notebook.Add(0, buffer, 40129408, "EEEEEEEEEEEE", "asasasasa", 40000, 0, "asasasasa");
            Notebook.Display();
            cout << strlen(buffer) << endl;
            if (strlen(buffer) < 10 or strlen(buffer) > 30) { windows::MessageBoxA(NULL, (windows::LPCSTR)"Your name's length is either below the minimum or above the maximum character limit.", (windows::LPCSTR)"Error", MB_ICONERROR | MB_HELP | MB_OK); }
            // windows::ShellMessageBoxA(NULL, NULL, (windows::LPCSTR)"Nyahaha", (windows::LPCSTR)"Nyahaha", 0);
            std::fill(buffer, buffer+64, NULL);
        }
        ClearBackground(WinColor);
        EndDrawing();
    }

    // Close the window properly when exiting
    CloseWindow();
    return 0;
}