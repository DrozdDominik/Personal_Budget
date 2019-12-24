#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include "Transaction.h"
#include "FileWithTransactions.h"
#include "AuxiliaryMethods.h"
//#include "MenuManager.h"
#include "User.h"

using namespace std;

class UserManager
{
    vector <Transaction> incomes;
    const string INCOMES_FILENAME;
    FileWithTransactions fileWithTransactions;
    User copyOfLoggedUser;

    int getCurrentDate();
    int getUserDate();
    bool whetherDateIsCorrect(string date);
    int convertStringDateToInt(string date);
    int daysInMonth(int year, int month);
    double getTransactionAmount();
    bool whetherTransactionAmountIsCorrectValue(string stringValue);
    double convertStringValueToDouble(string stringValue);
    int getNewTransactionId(vector<Transaction> transactions);
    void addTransaction(vector<Transaction> &transactions, string fileName, string keyword);

public:
    UserManager(string newIncomeFileName, User newLoggedUser) : INCOMES_FILENAME(newIncomeFileName), copyOfLoggedUser(newLoggedUser) /*menuManager(usersFileName)*/{};
    string getUserFullName();
    void addIncome();
};


#endif
