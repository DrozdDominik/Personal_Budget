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

void PersonalBudget::userMenu() {
    system("cls");
    cout << "    >>> MENU UZYTKOWNIKA <<<     " << endl;
    cout << "---------------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------------" << endl;
    cout << "Twoj wybor: ";
    switch (AuxiliaryMethods::loadSign()) {
    case '1':
     //   addIncome();
        break;
    case '2':
     //   addExpense();
        break;
    case '3':
     //   showCurrentMonthBalance();
        break;
    case '4':
     //   showPreviousMonthBalance();
        break;
    case '5':
    //    showSelectedPeriodBalance();
        break;
    case '6':
        changingPasswordOfLoggedUser();
        break;
    case '7':
        userLogOut();
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

bool PersonalBudget::whetherUserIsLoggedIn()
{
    return menuManager.whetherUserIsLoggedIn();
}

void PersonalBudget::changingPasswordOfLoggedUser()
{
    menuManager.changingPasswordOfLoggedUser();
}

void PersonalBudget::userLogOut()
{
    menuManager.userLogOut();
}

void PersonalBudget::writeAllUsers()
{
    menuManager.writeAllUsers();
    system("pause");
}


