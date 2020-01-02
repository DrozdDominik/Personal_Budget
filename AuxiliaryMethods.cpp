#include "AuxiliaryMethods.h"


string AuxiliaryMethods::firstCapitalRestLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}


string AuxiliaryMethods::loadLine()
{
    string enter = "";
    getline(cin, enter);
    return enter;
}

char AuxiliaryMethods::loadSign() {
    string input = "";
    char sign  = {0};
    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int AuxiliaryMethods::tmToInt(tm* &tmDate) {
    int intDate;
    intDate = (tmDate->tm_year + 1900) * pow(10,4) + (tmDate->tm_mon + 1) * pow (10,2) + tmDate->tm_mday;
    return intDate;
}

string AuxiliaryMethods::intToString(int number)
 {
    ostringstream ss;
    ss << number;
    string word = ss.str();
    return word;
}

string AuxiliaryMethods::doubleToString(double number)
{
    stringstream ss;
    string str;
    ss << number;
    ss >> str;
    return  str;
}

double AuxiliaryMethods::stringToDouble(string number) {
    double doubleNumber;
    istringstream iss(number);
    iss >> doubleNumber;
    return doubleNumber;
}

string AuxiliaryMethods::intDateToStringDate(int intDate)
{
    string stringDate, stringDay, stringMonth ,stringYear;

    int day, month, year, temp;

    day = intDate % 100;

    if(day < 10)
    {
    stringDay = "0" + intToString(day);
    }
    else
    {
    stringDay = intToString(day);
    }

    temp = intDate / 100;

    month = temp % 100;

    if(month < 10)
    {
    stringMonth = "0" + intToString(month);
    }
    else
    {
    stringMonth = intToString(month);
    }

    year = temp / 100;

    stringYear = intToString(year);

    stringDate = stringYear + "-" + stringMonth + "-" + stringDay;

    return stringDate;

}
