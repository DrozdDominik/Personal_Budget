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
    User loggedUser;
    User enterNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    MenuManager(string usersFileName) : fileWithUsers(usersFileName){
        users = fileWithUsers.loadUsersFromFile();

    };

    void userRegistration();
    void userLogin();
    bool whetherUserIsLoggedIn();
    void changingPasswordOfLoggedUser();
    User getLoggedUser();
    void clearLoggedUser();
    void writeAllUsers();
};

#endif
