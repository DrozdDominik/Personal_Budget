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
