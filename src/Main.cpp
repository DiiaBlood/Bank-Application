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

List Notebook;


int main(){
    // Load the window
    InitWindow(WinW, WinH, WinName);

    // Load setup function
    Setup();

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

// Debug test function
void Foo(){
    List Testbook;

    Node Test{0, "Aldskdskjakdja", "2418249", "ASkadkjadad", "Adkadka", 129481, 0, "Bonk"};
    Node Tast{0, "EEEEEEEEEEEE", "234829", "sssssssss", "asfafqg", 129481, 0, "Bonk"};

    cout << endl << "ADD" << endl;
    Test.ID = Testbook.Add(Test);
    Tast.ID = Testbook.Add(Tast);
    Notebook.Display();

    cout << endl << "EDIT" << endl;
    Testbook.Edit_Name(Test.ID, "Cummmmmmmmmmmm");
    Testbook.Edit_Email(Test.ID, "SASASASASAEEE");
    Testbook.Edit_Name(Test.ID, "Test.Name.FuckThis");
    Testbook.Edit_Phone_Number(Test.ID, "2489218491");
    Testbook.Edit_Profession(Test.ID, "Prostitute");
    Testbook.Display();

    cout << endl << "DEPOSIT" << endl;

    Testbook.Deposite(Test.ID, 6969);
    Testbook.Display();

    cout << endl << "WIHTDRAWAL"<< endl;

    Testbook.Withdrawal(Test.ID, 100);
    Testbook.Display();

    cout << endl << "TRANSFER" << endl;

    Testbook.Transfer(Test.ID, Tast.ID, 3000);

    cout << endl << "ANNUAL INTEREST" << endl;

    Testbook.Annual_Interest(Test.ID, 2, 10);
    Testbook.Display();

    cout << endl << "REMOVE" << endl;

    Testbook.Remove(Test.ID);
    Testbook.Display();

    cout << endl << "------------------------------------------------------";
    cout << endl << "------------------------------------------------------" << endl;
    
}

void Run(){
    if (IsKeyReleased(KEY_HOME)) {Foo();}
}