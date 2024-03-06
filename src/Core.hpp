#include <iostream>

using namespace std;

struct Node{
    unsigned long ID                = 0;
    string Name                      = "";
    string Mobile_Number             = "";
    string Email                     = "";
    string Profession                = "";
    unsigned long Amount             = 0;
    bool Account_Type                = 0;
    string Bank_Name                 = "";
    Node *Link                       = NULL;
};

class List{
private:
    Node *Tail = NULL; Node *Head = NULL;
public:
    Node *Search(unsigned long _ID);
    void Display();
    unsigned long Add(string _Name, string _Mobile_Number,
             string _Email, string _Profession, long _Money, 
             bool _Account_Type, string _Bank_Name);
    unsigned long Remove(unsigned long ID_);
    void Deposite(unsigned long _ID, long Cash);
    void Withdrawal(unsigned long _ID, long Cash);
    void Transfer(unsigned long From_ID, unsigned long To_ID, long Amount);
    // float Annual_Interest(int ID_);
};