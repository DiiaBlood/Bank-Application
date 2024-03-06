#include <iostream>
#include "../include/raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "../include/raygui.h"

// We include the windows header in a namespace as to not collide with Raylib
using std::cout, std::endl;
namespace windows{
    #include "windows.h"
}

// include other parts of the program
#include "Core.hpp"
#include "Global.h"

// Function definitions
void Setup();
void Run();

// Program's constants
const float WinW = 480.0f;
const float WinH = 480.0f;
const Color WinColor = GRAY;
const char* WinName = "Bank Application - Muktada A. Hatem";

int main(){
    // Load the window
    InitWindow(WinW, WinH, WinName);

    // Load setup function
    Setup();

    List Notebook;

    char buffer[64] = {"Write Here"};
    char buffer2[64] = {"Write Here"};
    int Active = true;
    bool SS = false;
    Vector2 OO = {2, 3};
    Color something = BLACK;
    Rectangle OE = {94, 20, 50, 59};
    while (!WindowShouldClose()){
        // PollInputEvents();
        BeginDrawing();
        // if (GetCollisionRec({GetMousePosition().x, GetMousePosition().y, 1, 1}, {20, 20, 200, 44}).height){
        //     SS = true;
        // } else { SS = false; }
        // GuiTextBox({20, 20, 200, 44}, buffer, 64, SS);
        // Gui
        // GuiDropdownBox({40, 80, 200, 30}, "Something; something else; wow; cool!;2sd;sf;asf;asf;asf;as;f;asf;as;f;asf;as;f", &Active, true);
        // GuiComboBox({40, 80, 200, 30}, "Something;Interesting", &Active);
        // GuiScrollPanel({20, 160, 200, 44}, "EEE", {22, 165, 50, 50}, &OO, &OE);
        // GuiTextBox({20, 160, 200, 44}, buffer2, 64, true);
        
        // cout << buffer << endl;
        // if (IsKeyPressed(KEY_ENTER)){
        //     cout << strlen(buffer) << endl;
        //     Notebook.Add(buffer, "094843985", buffer, buffer, 696969, 0, buffer);
        //     Notebook.Display();
        //     std::fill(buffer, buffer+64, NULL);
        // }

        // Load the run function every frame
        Run();
        ClearBackground(WinColor);
        EndDrawing();
    }

    // Close the window properly when exiting
    CloseWindow();
    return 0;
}


void Setup(){
    // This program uses Random number generators
    // To generate a proper number, a random seed is required
    // Here, we just input the current time as a seed

    windows::SYSTEMTIME CurrentTime;
    windows::GetSystemTime(&CurrentTime);
    SetRandomSeed   (((long long)CurrentTime.wYear * 1000000000000000) + 
                    ((long long)CurrentTime.wMonth * 1000000000000) + 
                    ((long long)CurrentTime.wDay * 1000000000) + 
                    ((long long)CurrentTime.wHour * 1000000) +
                    ((long long)CurrentTime.wMinute * 1000) +
                    ((long long)CurrentTime.wSecond));
}

void Run(){
    
}