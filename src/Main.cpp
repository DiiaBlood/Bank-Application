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

// Main class that holds the data of the accounts
List Notebook;

// All new accounts start with this node than is edited later
Node Starter_Node{0, "EDIT ME!", "07700770077700", "EDIT@EMAIL.ME!", "EDIT PROFESSION!", 25000, 0, "EDIT BANK!"};

long Current_Working_ID = 0;

// UI Elemetns
ItemList Accounts;
EditMenu Name_Menu({500, 35, 200, 40}, 0, "EDIT ME!");
EditMenu Email_Menu({720, 35, 200, 40}, 0, "EDIT@EMAIL.ME!");
EditMenu Phone_Menu({500, 95, 200, 40}, 0, "07700770077700");
EditMenu Profession_Menu({720, 95, 200, 40}, 0, "EDIT PROFESSION!");
EditMenu Bank_Menu({500, 155, 420, 40}, 0, "EDIT BANK!");

string Old_Name, Old_Email, Old_Phone, Old_Profession, Old_Bank;

int main(){
    // Load the window
    InitWindow(WinW, WinH, WinName);
    SetTargetFPS(60);
    SetExitKey(KEY_DELETE);

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
    SetRandomSeed   (((long long)CurrentTime.wYear  * 1000000000000000) + 
                    ((long long)CurrentTime.wMonth  * 1000000000000) + 
                    ((long long)CurrentTime.wDay    * 1000000000) + 
                    ((long long)CurrentTime.wHour   * 1000000) +
                    ((long long)CurrentTime.wMinute * 1000) +
                    ((long long)CurrentTime.wSecond));
    
    
    Accounts.SetBounds({0, 0, 480, 480});
    Accounts.SetDepth(1000);
    Accounts.SetTitle("Accounts:");
    Accounts.SetData(&Notebook);
}

void Run(){
    if (IsKeyReleased(KEY_HOME)) {Foo();}
    Notebook.Display();
    // Accounts Panel
    long Running_ID;
    Running_ID = Accounts.Render();

    // Add button pressed (know from return)
    if (Running_ID == 1){
        Starter_Node.Name = "EDIT ME! " + to_string(GetRandomValue(0, 1000));
        Starter_Node.Email = "EDIT EMAIL! " + to_string(GetRandomValue(0, 1000));
        Starter_Node.Mobile_Number = to_string(GetRandomValue(100, 10000));
        Accounts.Add_Item(Starter_Node);
    } 
    
    // One of the accounts were selected
    else if (Running_ID > 10000){
        Current_Working_ID = Running_ID;

        Name_Menu.Set_State(1);
        Email_Menu.Set_State(1);
        Phone_Menu.Set_State(1);
        Profession_Menu.Set_State(1);
        Bank_Menu.Set_State(1);
    }
    
    // One of the accounts were deleted
    else if (Running_ID == 2){
        Current_Working_ID = 0;

        Name_Menu.Set_State(0);
        Email_Menu.Set_State(0);
        Phone_Menu.Set_State(0);
        Profession_Menu.Set_State(0);
        Bank_Menu.Set_State(0);
    }


    // Edit Panel
    GuiPanel({480, 0, 480, 240}, "Edit:");

    // // Name Menu
    if (Name_Menu.Get_Ticked() and Current_Working_ID > 10){
        if (Notebook.Edit_Name(Current_Working_ID, Name_Menu.Get_Content()) == -1){
            Name_Menu.Set_Content(Old_Name);   
        }
    }
    Old_Name = Name_Menu.Get_Content();
    Name_Menu.Render();

    // // Email Menu
    if (Email_Menu.Get_Ticked() and Current_Working_ID > 10){
        if (Notebook.Edit_Email(Current_Working_ID, Email_Menu.Get_Content()) == -1){
            Email_Menu.Set_Content(Old_Email);   
        }
    }
    Old_Email = Email_Menu.Get_Content();
    Email_Menu.Render();

    // // Phone Menu
    if (Phone_Menu.Get_Ticked() and Current_Working_ID > 10){
        if (Notebook.Edit_Phone_Number(Current_Working_ID, Phone_Menu.Get_Content()) == -1){
            Phone_Menu.Set_Content(Old_Phone);   
        }
    }
    Old_Phone = Phone_Menu.Get_Content();
    Phone_Menu.Render();

    // // Profession Menu
    if (Profession_Menu.Get_Ticked() and Current_Working_ID > 10){
        if (Notebook.Edit_Profession(Current_Working_ID, Profession_Menu.Get_Content()) == -1){
            Profession_Menu.Set_Content(Old_Profession);   
        }
    }
    Old_Profession = Profession_Menu.Get_Content();
    Profession_Menu.Render();

    // // Bank Menu
    if (Bank_Menu.Get_Ticked() and Current_Working_ID > 10){
        if (Notebook.Edit_Bank_Name(Current_Working_ID, Bank_Menu.Get_Content()) == -1){
            Bank_Menu.Set_Content(Old_Bank);   
        }
    }
    Old_Bank = Bank_Menu.Get_Content();
    Bank_Menu.Render();

    // Always show the selected account
    if (Current_Working_ID > 1000 and !Name_Menu.Get_Ticked()) {Name_Menu.Set_Content(Notebook.Search(Current_Working_ID)->Name);}
    if (Current_Working_ID > 1000 and !Email_Menu.Get_Ticked()) {Email_Menu.Set_Content(Notebook.Search(Current_Working_ID)->Email);}
    if (Current_Working_ID > 1000 and !Phone_Menu.Get_Ticked()) {Phone_Menu.Set_Content(Notebook.Search(Current_Working_ID)->Mobile_Number);}
    if (Current_Working_ID > 1000 and !Profession_Menu.Get_Ticked()) {Profession_Menu.Set_Content(Notebook.Search(Current_Working_ID)->Profession);}
    if (Current_Working_ID > 1000 and !Bank_Menu.Get_Ticked()) {Bank_Menu.Set_Content(Notebook.Search(Current_Working_ID)->Bank_Name);}

    // Finance Panel
    GuiPanel({480, 240, 480, 240}, "Finance:");

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
    cout << "MOUSE X, Y: " << GetMousePosition().x << ", " << GetMousePosition().y << endl;
    DrawFPS(0, 0);
}
#endif