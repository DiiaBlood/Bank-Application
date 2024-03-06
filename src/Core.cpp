#include <iostream>
#include <iomanip>

#include "../include/raylib.h"

using std::cout, std::endl;
namespace windows{
    #include "windows.h"
}

#include "Core.hpp"
#include "Global.h"

Node *List::Search(unsigned long _ID){
    Node *Temp = new Node;
    Temp = Head;
    while(Temp != NULL) {
        if (Temp->ID == _ID) {
            return Temp;
        }
        Temp = Temp->Link;
    }
}

unsigned long List::Add(string _Name, string _Mobile_Number,
             string _Email, string _Profession, long _Money, 
             bool _Account_Type, string _Bank_Name) {
    Node *Temp = new Node;

    // We do some checks to make sure everything is valid
    if (_Name.find_first_not_of("0123456789+=-_`~'\"/\\|<>,?!@#$%^&*()") != 0
        or _Name.length() < 10 or _Name.length() > 30){
        Error("Name is wrong");
        return -1;
    }
    
    if (_Mobile_Number.find_first_not_of("0123456789") == 0 or _Mobile_Number.length() < 3){
        Error("Phone number is wrong");
        return -1;
    }

    if (_Email.length() < 3 or _Email.length() > 30){
        Error("Email name is wrong");
        return -1;
    }

    if (_Profession.length() < 3 or _Profession.length() > 30){
        Error("Profession name is wrong");
        return -1;
    }

    if (_Money < 25000){
        Error("Initial deposit is too low (25,000 minimum)");
        return -1;
    }

    if (_Bank_Name.length() < 3 or _Bank_Name.length() > 30){
        Error("Bank Name is wrong");
        return -1;
    }

    // Generate ID
    Temp->ID = GetRandomValue(1000000, 10000000);

    // Temp->ID = _ID;
    Temp->Name = _Name;
    Temp->Mobile_Number = _Mobile_Number;
    Temp->Email = _Email;
    Temp->Profession = _Profession;
    Temp->Amount = _Money;
    Temp->Account_Type = _Account_Type;
    Temp->Bank_Name = _Bank_Name;

    if (Head == NULL) { Head = Temp; Tail = Temp;}
    else { Tail->Link = Temp; Tail = Temp;}

    return Temp->ID;
}

unsigned long List::Remove(unsigned long _ID){
    Node *Cur, *Pre = new Node;
    Cur = Head;

    while (Cur->ID != _ID){
        Pre = Cur;
        Cur = Cur->Link;
    }
    Pre->Link = Cur->Link;

    delete Cur;
    return Cur->ID;
}

void List::Deposite(unsigned long _ID, long Cash){
    Node *Temp = Search(_ID);
    Temp->Amount += Cash;
}

void List::Withdrawal(unsigned long _ID, long Cash){
    Node *Temp = Search(_ID);
    Temp->Amount -= Cash;
}

void List::Transfer(unsigned long From_ID, unsigned long To_ID, long Amount){
    Node *From_Temp = Search(From_ID); Node *To_Temp = Search(To_ID);
    From_Temp->Amount -= Amount; To_Temp->Amount += Amount;
}

// float List::Annual_Interest(int ID_){
//     Node *Temp = Search(ID_);
//     return (((float)Temp->Money * 360.0 * 0.1) / 100);
// }

void List::Display(){
    Node *Temp = new Node;
    Temp = Head;
    while(Temp != NULL) {
    
    cout << Temp->ID << " | " << Temp->Name << " | " << Temp->Mobile_Number << 
    " | " << Temp->Email << " | "  << Temp->Profession << " | " << Temp->Amount << 
    " | " << Temp->Account_Type << " | " << Temp->Bank_Name << endl;

    Temp=Temp->Link;
    }
}