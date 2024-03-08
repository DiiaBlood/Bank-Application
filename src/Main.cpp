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
#include "Interface.hpp"
#include "Global.hpp"

// Function definitions
void Setup();
void Run();
void Foo();
#ifdef DEBUG
void Debug();
#endif

// Program's constants
const float WinW = 960.0f;
const float WinH = 480.0f;
const Color WinColor = DARKGRAY;
const char* WinName = "Bank Application - Muktada A. Hatem";

List Notebook;
ItemList Accounts;

int main(){
    // Load the window
    InitWindow(WinW, WinH, WinName);
    // SetTargetFPS(60);

    // Load setup function
    Setup();

    while (!WindowShouldClose()){
        ClearBackground(WinColor);
        BeginDrawing();

        // Load the run function every frame
        Run();
        
        // Debug Code
        #ifdef DEBUG
        Debug();
        #endif

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
    
    
    Accounts.SetBounds({0, 0, 480, 480});
    Accounts.SetDepth(1000);
    Accounts.SetTitle("Accounts:");
    Accounts.SetData(&Notebook);
}

void Run(){
    Node Mewo{0, "EEEEEEEEEEEE", "234829", "sssssssss", "asfafqg", 129481, 0, "Bonk"};
    if (IsKeyReleased(KEY_HOME)) {Foo();}
    if (IsKeyReleased(KEY_ENTER)) {Accounts.Add_Item(Mewo); Notebook.Display(); }
    
    long Current_ID = Accounts.Render();
    if (Current_ID == 1){
        Accounts.Add_Item(Mewo);
    } else if (Current_ID > 10){
        cout << Current_ID << endl;
    }
}

// Test function
void Foo(){
    List Testbook;

    Node Test{0, "Aldskdskjakdja", "2418249", "ASkadkjadad", "Adkadka", 129481, 0, "Bonk"};
    Node Tast{0, "EEEEEEEEEEEE", "234829", "sssssssss", "asfafqg", 129481, 0, "Bonk"};

    cout << endl << "ADD" << endl;
    Test.ID = Testbook.Add(Test);
    Tast.ID = Testbook.Add(Tast);
    Notebook.Display();

    cout << endl << "EDIT" << endl;
    Testbook.Edit_Name(Test.ID, "TestingTestingTesting");
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

#ifdef DEBUG
void Debug(){
    cout << "MOUSE X, Y: " << GetMousePosition().x << ", " << GetMousePosition().y;
    DrawFPS(0, 0);
}
#endif