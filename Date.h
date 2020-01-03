#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <ctime>
#include "Transaction.h"
#include "FileWithTransactions.h"
#include "AuxiliaryMethods.h"
#include "User.h"

using namespace std;

class Date
{
public:

    static int getCurrentDate();
    static int getUserDate();
    static bool whetherDateIsCorrect(string date);
    static int convertStringDateToInt(string date);
    static int daysInMonth(int year, int month);
    static int getFirstDayOfMonth(int date);
    static int getFirstDayOFPreviousMonth(int date);
    static int getLastDayOFPreviousMonth(int date);
};

#endif
