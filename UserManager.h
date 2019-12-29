#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include "Transaction.h"
#include "FileWithTransactions.h"
#include "AuxiliaryMethods.h"
#include "User.h"

using namespace std;

class UserManager
{
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
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
    UserManager(string newIncomesFileName, string newExpensesFileName, User newLoggedUser) : INCOMES_FILENAME(newIncomesFileName), EXPENSES_FILENAME(newExpensesFileName), copyOfLoggedUser(newLoggedUser){
    incomes = fileWithTransactions.loadTransactionsFromFile(INCOMES_FILENAME, copyOfLoggedUser.getId());
    expenses = fileWithTransactions.loadTransactionsFromFile(EXPENSES_FILENAME, copyOfLoggedUser.getId());
    };
    string getUserFullName();
    void addIncome();
    void addExpense();
    void writeAllIncomes();
};


#endif
