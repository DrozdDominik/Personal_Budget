#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include "Transaction.h"
#include "FileWithTransactions.h"
#include "AuxiliaryMethods.h"
#include "User.h"
#include "Date.h"

using namespace std;

class UserManager
{
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
    FileWithTransactions fileWithTransactions;
    User copyOfLoggedUser;

    struct Comparison
    {
        bool operator()(Transaction first, Transaction second)
        {
            if(first.getDate() < second.getDate())
            {
                return true;
            }
            else
            {
                return false;
            }
         }
    } dateComparison;

    double getTransactionAmount();
    bool whetherTransactionAmountIsCorrectValue(string stringValue);
    double convertStringValueToDouble(string stringValue);
    int getNewTransactionId(vector <Transaction> transactions);
    void addTransaction(vector <Transaction> &transactions, string fileName, string keyword);
    void showBalanceFromSelectedPeriod(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond);
    double sortAndDisplayTransactions (vector <Transaction> transactions, string keyword, int startDate, int endDate);
    void showBalanceFromCurrentMonth(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond);
    void showBalanceFromPreviousMonth(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond);

public:
    UserManager(string newIncomesFileName, string newExpensesFileName, User newLoggedUser) : INCOMES_FILENAME(newIncomesFileName), EXPENSES_FILENAME(newExpensesFileName), copyOfLoggedUser(newLoggedUser){
    incomes = fileWithTransactions.loadTransactionsFromFile(INCOMES_FILENAME, copyOfLoggedUser.getId());
    expenses = fileWithTransactions.loadTransactionsFromFile(EXPENSES_FILENAME, copyOfLoggedUser.getId());
    };
    string getUserFullName();
    void addIncome();
    void addExpense();
    void showSelectedPeriodBalance();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
};


#endif
