#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers {

public:

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePasswordInFile(int idOfLoggedInUser, string password);
};

#endif
