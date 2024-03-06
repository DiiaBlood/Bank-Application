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
void Foo();

// Program's constants
const float WinW = 800.0f;
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
        ClearBackground(WinColor);
        BeginDrawing();

        GuiScrollPanel({0, 20, 480, 460}, "Accounts", {0, 0, 0, 1200}, &OO, &OE);

        BeginScissorMode(0, 42, 465, 438);
        GuiButton({4, 45+OO.y, 460, 40}, "+");
        DrawCircle(100, 600 + OO.y, 50, RED);        
        EndScissorMode();

        // Load the run function every frame
        Run();
        EndDrawing();
    }

    // Close the window properly when exiting
    CloseWindow();
    return 0;
}


void Setup(){
    // This program uses Random number generator
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
    if (IsKeyReleased(KEY_HOME)) {Foo();}
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