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
        personalBudget.userMenu();
    }
}

    return 0;
}
