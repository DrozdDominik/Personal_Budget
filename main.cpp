#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    personalBudget.userRegistration();
    personalBudget.writeAllUsers();
    personalBudget.userRegistration();
    personalBudget.writeAllUsers();

    return 0;
}
