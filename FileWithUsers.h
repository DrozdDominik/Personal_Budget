#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers {
const string USERS_FILENAME;

public:
    FileWithUsers(string usersFileName): USERS_FILENAME(usersFileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePasswordInFile(User loggedUser);
};

#endif
