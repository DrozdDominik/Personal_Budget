#ifndef TANSACTION_H
#define TANSACTION_H

#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Transaction {
int id;
int userId;
int date;
string item;
double amount;
string stringDate;
string stringAmount;

public:
    Transaction() : id(0), userId(0), date(0), item(""), amount(0), stringAmount("") {};
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
    string getStringAmount();
    string getStringDate();


};

#endif
