#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    while(true) {
    if(!personalBudget.whetherUserIsLoggedIn())
    {
      personalBudget.registrationMenu();
    }
    else {
        personalBudget.userMenu();
    }
}

    return 0;
}
