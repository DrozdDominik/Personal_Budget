#include "MenuManager.h"


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

void MenuManager::userLogin() {
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
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUser = users[i];
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Uzytkownik o podanym loginie nie istnieje" << endl << endl;
    system("pause");
}

bool MenuManager::whetherUserIsLoggedIn() {

if (loggedUser.getId() > 0)
        return true;
    else
        return false;
}
void MenuManager::clearLoggedUser() {
    loggedUser.clearUser();
}
void MenuManager::changingPasswordOfLoggedUser() {
    system("cls");
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i=0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedUser.getId())
        {
            users[i].setPassword(newPassword);
            loggedUser.setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
   fileWithUsers.changePasswordInFile(loggedUser);
}

User MenuManager::getLoggedUser() {
    return loggedUser;
}
