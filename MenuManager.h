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
    int idOfLoggedInUser;

    User enterNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    MenuManager();
    int getIdOfLoggedInUser();
    void userRegistration();
    int userLogin();
    bool whetherUserIsLoggedIn();
    void writeAllUsers();
};

#endif
