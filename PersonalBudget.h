#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <windows.h>

#include "MenuManager.h"
#include "User.h"

using namespace std;

class PersonalBudget {

MenuManager menuManager;

public:
    void registrationMenu();
    void userRegistration();
    void userLogin();
    bool whetherUserIsLoggedIn();
    void writeAllUsers();
};

#endif
