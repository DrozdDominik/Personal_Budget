#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <sstream>
#include <cstdlib>


using namespace std;

class AuxiliaryMethods {
public:

    static string firstCapitalRestLowercase(string text);
    static string loadLine();
    static char loadSign();
    static int tmToInt(tm* &tmDate);
    static string intToString(int number);
    static string doubleToString(double number);
    static double stringToDouble(string number);
    static string intDateToStringDate(int intDate);
    static int stringDateTointDate(string stringDate);
};


#endif
