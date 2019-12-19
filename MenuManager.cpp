#include "MenuManager.h"

MenuManager::MenuManager()
{
    users = fileWithUsers.loadUsersFromFile();
    idOfLoggedInUser = 0;
}

int MenuManager::getIdOfLoggedInUser()
{
    return idOfLoggedInUser;
}


void MenuManager::userRegistration()
{
    User user = enterNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User MenuManager::enterNewUserData()
{
    User user;
    user.setId(getNewUserId());
    string login = "", password = "", name = "", surname = "";
    do {
        system("cls");
        cout << "       >>> REJESTRACJA <<<" << endl;
        cout << "---------------------------------" << endl;
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(AuxiliaryMethods::firstCapitalRestLowercase(name));
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(AuxiliaryMethods::firstCapitalRestLowercase(surname));
    return user;
}

int MenuManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool MenuManager::isLoginExist(string login)
{
    for (int i=0; i < users.size(); i++) {
    if (users[i].getLogin() == login) {
        cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
        system("pause");
        return true;
    }
}
    return false;
}

void MenuManager::writeAllUsers()
{
    for(int i= 0; i < users.size(); i++)
   {
       cout << users[i].getId() << endl;
       cout << users[i].getLogin() << endl;
       cout << users[i].getPassword() << endl;
       cout << users[i].getName() << endl;
       cout << users[i].getSurname() << endl;
}
}

int MenuManager::userLogin() {
    string login = "", password = "";
    system("cls");
    cout << "        >>> LOGOWANIE <<<" << endl;
    cout << "---------------------------------" << endl;
    cout << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie poprawnie." << endl << endl;
                    system("pause");
                    idOfLoggedInUser = users[i].getId();
                    return idOfLoggedInUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Uzytkownik o podanym loginie nie istnieje" << endl << endl;
    system("pause");
    return 0;
}

bool MenuManager::whetherUserIsLoggedIn()
{
    if(idOfLoggedInUser > 0)
        return true;
    else
        return false;
}


void MenuManager::changingPasswordOfLoggedUser() {
    system("cls");
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i=0; i < users.size(); i++)
    {
        if (users[i].getId() == idOfLoggedInUser)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl;
            system("pause");
        }
    }
    fileWithUsers.changePasswordInFile(idOfLoggedInUser, newPassword);
}


void MenuManager::userLogOut() {
    idOfLoggedInUser = 0;
}
