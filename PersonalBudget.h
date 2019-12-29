#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <windows.h>

#include "MenuManager.h"
#include "User.h"
#include "UserManager.h"

using namespace std;

class PersonalBudget {

MenuManager menuManager;
UserManager *userManager;
const string INCOMES_FILENAME;
const string EXPENSE_FILENAME;

public:
    PersonalBudget (string usersFileName, string incomesFileName, string expensesFileName)
        : menuManager(usersFileName), INCOMES_FILENAME(incomesFileName), EXPENSE_FILENAME(expensesFileName) {
        userManager = NULL;
    };
    ~PersonalBudget() {
        delete userManager;
        userManager = NULL;
    }
    void registrationMenu();
    void userRegistration();
    void userLogin();
    bool whetherUserIsLoggedIn();
    void userMenu();
    void writeAllUsers();
    void changingPasswordOfLoggedUser();
    void userLogOut();
    void addIncome();
    void addExpense();
    void writeAllIncomes();
};

#endif
