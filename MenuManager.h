#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <iostream>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include <vector>
#include <windows.h>

using namespace std;

class MenuManager
{
    vector <User> users;
    FileWithUsers fileWithUsers;

    User enterNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    MenuManager();
    void userRegistration();
    void writeAllUsers();
};

#endif
