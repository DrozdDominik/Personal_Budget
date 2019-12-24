#include "UserManager.h"

int UserManager::getCurrentDate()
{
    int currentDate;
    time_t t = time(0);
    tm* now = localtime(&t);
    currentDate = AuxiliaryMethods::tmToInt(now);
    return currentDate;
}

int UserManager::getUserDate()
{
    int integerUserDate = NULL;
    string stringUserDate = "";
    do {
        getline(cin, stringUserDate);
        if (whetherDateIsCorrect(stringUserDate)) {
            integerUserDate = convertStringDateToInt(stringUserDate);
            if (integerUserDate != 0)
                break;
        }
        cout << "Wpisz poprawna date: " << endl;
    } while (true);
    return integerUserDate;
}

bool UserManager::whetherDateIsCorrect(string date)
{
    int dashCounter = 0;
    if (date[0] == '-')
    {
        cout << "Zly format daty." << endl;
        return false;
    }
    for (int i = 0; i < date.size(); i++)
    {
        int sign = date[i];
        if (((sign < 48) || (sign > 57)) && (sign != 45))
        {
            cout << "Niedozwolony znak w dacie." << endl;
            return false;
        }
        else if (sign == 45 && int(date[i+1]) == 45) {
        cout << "Zly format daty." << endl;
        return false;
        }
        if (sign == 45)
        {
            dashCounter++;
        }
    }
    if ((dashCounter != 2) || (date[date.size() - 1] == 45))
    {
        cout << "Zly format daty." << endl;
        return false;
    }
    return true;
}

int UserManager::convertStringDateToInt(string date)
{
    int i = 0, year = 0, month = 0, day = 0, intDate = 0;
    time_t t = time(0);
    tm* now = localtime(&t);
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++)
    {
        year=year*10+int(date[i])-48;
    }
    i++;
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++)
    {
        month=month*10+int(date[i])-48;
    }
    i++;
    for(; i < date.size(); i++)
    {
        day=day*10+int(date[i])-48;
    }
    if ((year < 2000) || (year > (now->tm_year + 1900)))
    {
        cout << "Niepoprawny rok." << endl;
        return 0;
    }
    if ( ((month < 1) || (month > 12)) || (year == (now->tm_year + 1900) && month > (now->tm_mon + 1)) )
    {
        cout << "Niepoprawny miesiac." << endl;
        return 0;
    }
    if ((day == 0) || (day > daysInMonth(year,month)))
    {
        cout << "Niepoprawny dzien." << endl;
        return 0;
    }
    intDate = (year * pow (10,4)) + (month * pow (10,2)) + day;
    return intDate;
}

int UserManager::daysInMonth(int year, int month)
{
    if(month < 0 || month > 12)
    {
        cout << "Nie ma takiego miesiaca" << endl;
        return 0;
    }

    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month ==10 || month == 12)
    {
        return 31;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {if ((year%4==0 && year%100!=0) || year%400==0)
    {
        return 29;
    }
    else
        return 28;
    }
}


double UserManager::getTransactionAmount()
{
    double transactionAmount = 0;
    string stringAmount = "";
    do {
        stringAmount = AuxiliaryMethods::loadLine();
        if (whetherTransactionAmountIsCorrectValue(stringAmount)) {
            transactionAmount = convertStringValueToDouble(stringAmount);
            break;
        }
        cout << "Wpisz poprawna wartosc: " << endl;
    } while (true);
    return transactionAmount;
}

bool UserManager::whetherTransactionAmountIsCorrectValue(string stringAmount)
{
    int dotCounter = 0;
    for (int i = 0; i < stringAmount.size(); i++)
        {
        int sign = stringAmount[i];
        if (sign == 44 || sign == 46)
        {
            dotCounter++;
            if (stringAmount.size() > i+3)
            {
                cout << "Zly format kwoty. Dokladnosc do 0.01 ." << endl;
                return false;
            }
        }
        if (((sign < 48) || (sign > 57)) && (sign != 46)&& (sign != 44))
        {
            cout << "Niepoprawny znak w kwocie." << endl;
            return false;
        }
    }
    if (dotCounter > 1)
    {
        cout << "Zly format kwoty: zbyt wiele przecinkow." << endl;
        return false;
    }
    if (stringAmount.empty())
    {
        cout << "Nie wprowadzono kwoty." << endl;
        return false;
    }
    return true;
}

double UserManager::convertStringValueToDouble(string stringAmount)
{
    double doubleAmount = 0;
    for (int i = 0, j = stringAmount.size()-1; i < stringAmount.size(); i++, j--)
    {
        int sign = stringAmount[i];
        if (sign == 44 || sign == 46)
        {
            doubleAmount = doubleAmount / pow(10,j+1);
            j = 0;
        }
        else
        {
            doubleAmount = doubleAmount + ((sign - 48) * pow(10,j));
        }
    }
    return doubleAmount;
}

int UserManager::getNewTransactionId(vector <Transaction> transactions)
{
    if (transactions.empty() == true)
        return 1;
    else
        return transactions.back().getId() + 1;
}

void UserManager::addTransaction(vector<Transaction> &transactions, string fileName, string keyword)
{
    Transaction transaction;

    string item;
    transaction.setId(getNewTransactionId(transactions));
    transaction.setUserId(copyOfLoggedUser.getId());
    char choice = NULL;
    do {
        system("cls");
        cout << "   >>> DODAJ " << keyword << " <<<" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Czy dodac " << keyword << " z dzisiejsza data? (t/n)" << endl;
        cin.sync();
        choice = AuxiliaryMethods::loadSign();
        switch (choice) {
        case 't':
            transaction.setDate(getCurrentDate());
            break;
        case 'n':
            cout << "Wpisz date (yyyy-mm-dd): ";
            transaction.setDate(getUserDate());
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
            break;
        }
    } while (choice!='n' && choice!='t');
    cout << "Wpisz nazwe: ";
    item = AuxiliaryMethods::loadLine();
    transaction.setItem(item);
    cout << "Wpisz wartosc: ";
    transaction.setAmount(getTransactionAmount());
    transactions.push_back(transaction);
    fileWithTransactions.addTransactionToFile(transaction, fileName);
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    cout << "Dodano pozycje " << keyword << "." << endl << endl;
    system("pause");
}

void UserManager::addIncome()
{
    addTransaction(incomes, INCOMES_FILENAME, "PRZYCHOD");
}

string UserManager::getUserFullName()
{
    string fullname;
    fullname = copyOfLoggedUser.getName() + " " + copyOfLoggedUser.getSurname();
    return fullname;
}
