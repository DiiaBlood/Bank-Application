#include <iostream>
#include <iomanip>

#include "../include/raylib.h"

using std::cout, std::endl;
namespace windows{
    #include "windows.h"
}

#include "Core.hpp"
#include "Global.h"

Node *List::Search(long _ID){
    Node *Temp = new Node;
    Temp = Head;
    while(Temp != NULL) {
        if (Temp->ID == _ID) {
            return Temp;
        }
        Temp = Temp->Link;
    }

    Error("ID could not be found");
    return NULL;
}

int List::Validate(Node* TestNode){
    // Make sure the pointer is correct
    if (TestNode == NULL) {Error("Can't validate NULL"); return -1;}

    // We do some checks to make sure everything is valid
    if (TestNode->Name.find_first_not_of("0123456789+=-_`~'\"/\\|<>,?!@#$%^&*()") != 0
        or TestNode->Name.length() < 10 or TestNode->Name.length() > 30){
        Error("Name is wrong");
        return -1;
    }
    
    if (TestNode->Mobile_Number.find_first_not_of("0123456789") == 0 or TestNode->Mobile_Number.length() < 3){
        Error("Phone number is wrong");
        return -1;
    }

    if (TestNode->Email.length() < 3 or TestNode->Email.length() > 30){
        Error("Email name is wrong");
        return -1;
    }

    if (TestNode->Profession.length() < 3 or TestNode->Profession.length() > 30){
        Error("Profession name is wrong");
        return -1;
    }

    if (TestNode->Amount < 25000){
        Error("Initial deposit is too low (25,000 minimum)");
        return -1;
    }

    if (TestNode->Bank_Name.length() < 3 or TestNode->Bank_Name.length() > 30){
        Error("Bank Name is wrong");
        return -1;
    }

    // After that, we check if some sensetive information is copied from a different account
    Node *Temp = new Node; Temp = Head;

    while(Temp != NULL && TestNode->ID != Temp->ID) {
        if ( Temp->ID == TestNode->ID) {Error("ID Error - Please try again"); return -1;}
        if ( Temp->Name == TestNode->Name) {Error("Name similar to another account"); return -1;}
        if ( Temp->Email == TestNode->Email) {Error("Email similar to another account"); return -1;}
        if ( Temp->Mobile_Number == TestNode->Mobile_Number) {Error("Mobiel Number similar to another account"); return -1;}
        Temp = Temp->Link;
    }

    return 0;
}

long List::Add(Node NewUser) {
    // Generate ID
    NewUser.ID = GetRandomValue(100000, 1000000);

    if (Validate(&NewUser) == -1) {return -1;}

    Node *Temp = new Node;

    Temp->ID = NewUser.ID;
    Temp->Name = NewUser.Name;
    Temp->Mobile_Number = NewUser.Mobile_Number;
    Temp->Email = NewUser.Email;
    Temp->Profession = NewUser.Profession;
    Temp->Amount = NewUser.Amount;
    Temp->Account_Type = NewUser.Account_Type;
    Temp->Bank_Name = NewUser.Bank_Name;

    if (Head == NULL) {Head = Temp; Tail = Temp;}
    else {Tail->Link = Temp; Tail = Temp;}

    return NewUser.ID;
}

int List::Edit_Name(long _ID, string _Name){
    Node* Temp = Search(_ID);
    if (Temp != NULL){
        Node BackUp = *Temp;
        Temp->Name = _Name;
        if (Validate(Temp) == -1) {Temp->Name = BackUp.Name; return -1;}
        return 0;
    }
    return -1;
}

int List::Edit_Phone_Number(long _ID, string _Mobile_Number){
    Node* Temp = Search(_ID);
    if (Temp != NULL){
        Node BackUp = *Temp;
        Temp->Mobile_Number = _Mobile_Number;
        if (Validate(Temp) == -1) {Temp->Mobile_Number = BackUp.Mobile_Number; return -1;}
        return 0;
    }
    return -1;
}

int List::Edit_Email(long _ID, string _Email){
    Node* Temp = Search(_ID);
    if (Temp != NULL){
        Node BackUp = *Temp;
        Temp->Email = _Email;
        if (Validate(Temp) == -1) {Temp->Email = BackUp.Email; return -1;}
        return 0;
    }
    return -1;
}
int List::Edit_Profession(long _ID, string _Profession){
    Node* Temp = Search(_ID);
    if (Temp != NULL){
        Node BackUp = *Temp;
        Temp->Profession = _Profession;
        if (Validate(Temp) == -1) {Temp->Profession = BackUp.Profession; return -1;}
        return 0;
    }
    return -1;
}
int List::Edit_Bank_Name(long _ID, string _Bank_Name){
    Node* Temp = Search(_ID);
    if (Temp != NULL){
        Node BackUp = *Temp;
        Temp->Bank_Name = _Bank_Name;
        if (Validate(Temp) == -1) {Temp->Bank_Name = BackUp.Bank_Name; return -1;}
        return 0;
    }
    return -1;
}

long List::Remove(long _ID){
    Node *Cur, *Pre = new Node;
    Cur = Head;

    if (Head == Tail && Head->ID == _ID) { delete Cur; Head = NULL; Tail = NULL; return 0;}

    while (Cur->ID != _ID){
        if (Cur == NULL) {Error("Can't remove non-existing ID"); return -1;}
        Pre = Cur;
        Cur = Cur->Link;
    }
    Pre->Link = Cur->Link;

    delete Cur; Head = NULL; Tail = NULL;
    return 0;
}

void List::Deposite(long _ID, long Cash){
    Node *Temp = Search(_ID);
    if (Temp != NULL)
    Temp->Amount += Cash;
}

void List::Withdrawal(long _ID, long Cash){
    Node *Temp = Search(_ID);
    if (Temp != NULL)
    Temp->Amount -= Cash;
}

void List::Transfer(long From_ID, long To_ID, long Amount){
    Node *From_Temp = Search(From_ID); Node *To_Temp = Search(To_ID);
    if (From_Temp != NULL && To_Temp != NULL)
    {From_Temp->Amount -= Amount; To_Temp->Amount += Amount;}
}

long List::Annual_Interest(int ID_, int Years, short Percentage){
    Node *Temp = Search(ID_);
    if (Temp != NULL)
    return (Temp->Amount+(Temp->Amount * (Years * (Percentage/100))));
    return -1;
}

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