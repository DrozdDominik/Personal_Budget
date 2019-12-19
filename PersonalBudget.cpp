#include "PersonalBudget.h"


void PersonalBudget::registrationMenu() {
    system("cls");
    cin.sync();
    cout << "     >>> MENU LOGOWANIA <<<" << endl;
    cout << "---------------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------------" << endl;
    cout << "Twoj wybor: ";
    switch (AuxiliaryMethods::loadSign()) {
    case '1':
        userRegistration();
        break;
    case '2':
        userLogin();
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }
}


void PersonalBudget::userRegistration()
{
    menuManager.userRegistration();
}

void PersonalBudget::userLogin()
{
    menuManager.userLogin();
}

bool PersonalBudget::whetherUserIsLoggedIn() {
    return menuManager.whetherUserIsLoggedIn();
}

void PersonalBudget::writeAllUsers()
{
    menuManager.writeAllUsers();
    system("pause");
}
