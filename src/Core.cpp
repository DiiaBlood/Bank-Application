#include <iostream>

using namespace std;

#include "Core.hpp"

void List::Display(){
    Node *Temp = new Node;
    Temp = Head;
    while(Temp != NULL) {
    cout << Temp->ID << " / " << Temp->Name << " / " << Temp->Mobile_Number << " / " << Temp->Email << " / "  << Temp->Profession << " / " << Temp->Money << " / " << Temp->Account_Type << " / " << Temp->Bank_Name << endl;
    Temp=Temp->Link;
    }
}

Node *List::Search(int ID_){
    Node *Temp = new Node;
    Temp = Head;
    while(Temp != NULL) {
        if (Temp->ID == ID_) {
            return Temp;
        }
        Temp = Temp->Link;
    }
}

void List::Add(int ID_, string Name_, long Mobile_Number_, string Email_, string Profession_, long Money_, bool Account_Type_, string Bank_Name_){
    Node *Temp = new Node;

    if ((Name_.length() > 10 and Name_.length() < 30)
        and 1){
        Temp->ID = ID_;
        Temp->Name = Name_;
        Temp->Mobile_Number = Mobile_Number_;
        Temp->Email = Email_;
        Temp->Profession = Profession_;
        Temp->Money = Money_;
        
        Temp->Money = 25000;
        
        Temp->Account_Type = Account_Type_;
        Temp->Bank_Name = Bank_Name_;
    }

    if (Head == NULL) { Head = Temp; Tail = Temp;}
    else { Tail->Link = Temp; Tail = Temp;}
}

void List::Remove(int ID_){
    Node *Cur, *Pre = new Node;
    Cur = Head;

    while (Cur->ID != ID_){
        Pre = Cur;
        Cur = Cur->Link;
    }
    cout << "YAY" << endl;
    Pre->Link = Cur->Link;

    delete Cur;
}

void List::Deposite(int ID_, long Cash){
    if (Cash < 250000){
        Node *Temp = Search(ID_);
        Temp->Money += Cash;
    }
}

void List::Withdrawal(int ID_, long Cash){
    Node *Temp = Search(ID_);
    Temp->Money -= Cash;
}

void List::Transfer(int From_ID, int To_ID, long Amount){
    Node *From_Temp = Search(From_ID); Node *To_Temp = Search(To_ID);
    From_Temp->Money -= Amount; To_Temp->Money += Amount;
}

float List::Annual_Interest(int ID_){
    Node *Temp = Search(ID_);
    return (((float)Temp->Money * 360.0 * 0.1) / 100);
}