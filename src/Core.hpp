#include <iostream>

using namespace std;

struct Node{
    int ID;
    string Name;
    long Mobile_Number;
    string Email;
    string Profession;
    long Money;
    bool Account_Type;
    string Bank_Name;
    Node *Link = NULL;
};

class List{
private:
    Node *Tail = NULL; Node *Head = NULL;
public:
    void Display();
    Node *Search(int ID_);
    void Add(int ID_, string Name_, long Mobile_Number_, string Email_, string Profession_, long Money_, bool Account_Type_, string Bank_Name_);
    void Remove(int ID_);
    void Deposite(int ID_, long Cash);
    void Withdrawal(int ID_, long Cash);
    void Transfer(int From_ID, int To_ID, long Amount);
    float Annual_Interest(int ID_);
};