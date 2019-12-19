#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    while(true) {
    if(!personalBudget.whetherUserIsLoggedIn()) {
      personalBudget.registrationMenu();
    }
    else {
        cout << "Panel Uzytkownika" << endl;
        system("pause");
        exit(0);
    }
}

    return 0;
}
