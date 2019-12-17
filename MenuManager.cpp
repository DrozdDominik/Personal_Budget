#include "MenuManager.h"

void MenuManager::userRegistration()
{
    User user = enterNewUserData();
    users.push_back(user);
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

