#ifndef TANSACTION_H
#define TANSACTION_H

#include <iostream>

using namespace std;

class Transaction {
int id;
int userId;
int date;
string item;
double amount;

public:

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

};

#endif
