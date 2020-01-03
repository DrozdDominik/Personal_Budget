#include "UserManager.h"

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
            transaction.setDate(Date::getCurrentDate());
            break;
        case 'n':
            cout << "Wpisz date (yyyy-mm-dd): ";
            transaction.setDate(Date::getUserDate());
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

void UserManager::addExpense()
{
    addTransaction(expenses, EXPENSES_FILENAME, "WYDATEK");
}

void UserManager::showBalanceFromSelectedPeriod(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond)
{
    system("cls");

    int startDate = 0;
    cout << "Podaj date rozpoczecia bilansu (yyyy-mm-dd): " << endl;
    startDate = Date::getUserDate();

    int endDate = 0;
    cout << "Podaj date konca bilansu (yyyy-mm-dd): " << endl;

    endDate = Date::getUserDate();

    if (endDate < startDate)
    {
        cout << "Data koncowa nie moze byc wczesniejsza niz poczatkowa." << endl;


        cout << "Podaj date rozpoczecia bilansu (yyyy-mm-dd): " << endl;
        startDate = Date::getUserDate();


        cout << "Podaj date konca bilansu (yyyy-mm-dd): " << endl;
        endDate = Date::getUserDate();
    }

    system("cls");

    cout << "BILANS PRZYCHODOW I WYDATKOW Z OKRESU: " << AuxiliaryMethods::intDateToStringDate(startDate) << " do " << AuxiliaryMethods::intDateToStringDate(endDate) << endl;
    double incomesSum = sortAndDisplayTransactions(transactions, keyword, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    double expensesSum = sortAndDisplayTransactions(transactionsSecond, keywordSecond, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << endl << "ROZNICA POMIEDZY PRZYCHODAMI I WYDATKAMI: " << incomesSum - expensesSum << endl;
    system("pause");
}

double UserManager::sortAndDisplayTransactions (vector <Transaction> transactions, string keyword, int startDate, int endDate)
{
    vector <Transaction> transactionsOfLoggedUser;

    for(int i = 0; i < transactions.size(); i++)
    {
        if(transactions[i].getUserId() == copyOfLoggedUser.getId())
        {
            transactionsOfLoggedUser.push_back(transactions[i]);
        }
    }

    sort(transactionsOfLoggedUser.begin(), transactionsOfLoggedUser.end(), dateComparison);

    double sum = 0;

    cout << endl << "ZESTAWIENIE " << keyword << endl;

    for(int i = 0; i < transactionsOfLoggedUser.size(); i++)
    {
       if(transactionsOfLoggedUser[i].getDate() >= startDate && transactionsOfLoggedUser[i].getDate() <= endDate)
       {
           cout << AuxiliaryMethods::intDateToStringDate(transactionsOfLoggedUser[i].getDate()) << " " << transactionsOfLoggedUser[i].getItem() << ": " << transactionsOfLoggedUser[i].getAmount() << endl;
           sum += transactionsOfLoggedUser[i].getAmount();
       }
    }
    cout << endl << "SUMA " << keyword << " : " << sum << endl;

    return sum;
}

void UserManager::showBalanceFromCurrentMonth(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond)
{
    system("cls");

    int endDate = Date::getCurrentDate();

    int startDate = Date::getFirstDayOfMonth(endDate);

    cout << "BILANS PRZYCHODOW I WYDATKOW Z OKRESU: " << AuxiliaryMethods::intDateToStringDate(startDate) << " do " << AuxiliaryMethods::intDateToStringDate(endDate) << endl;
    double incomesSum = sortAndDisplayTransactions(transactions, keyword, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    double expensesSum = sortAndDisplayTransactions(transactionsSecond, keywordSecond, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << endl << "ROZNICA POMIEDZY PRZYCHODAMI I WYDATKAMI: " << incomesSum - expensesSum << endl;
    system("pause");
}

void UserManager::showBalanceFromPreviousMonth(vector <Transaction> transactions, string keyword, vector <Transaction> transactionsSecond, string keywordSecond)
{
    system("cls");

    int startDate = Date::getFirstDayOFPreviousMonth(Date::getCurrentDate());

    int endDate = Date::getLastDayOFPreviousMonth(Date::getCurrentDate());

    cout << "BILANS PRZYCHODOW I WYDATKOW Z OKRESU: " << AuxiliaryMethods::intDateToStringDate(startDate) << " do " << AuxiliaryMethods::intDateToStringDate(endDate) << endl;
    double incomesSum = sortAndDisplayTransactions(transactions, keyword, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    double expensesSum = sortAndDisplayTransactions(transactionsSecond, keywordSecond, startDate, endDate);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << endl << "ROZNICA POMIEDZY PRZYCHODAMI I WYDATKAMI: " << incomesSum - expensesSum << endl;
    system("pause");
}

void UserManager::showSelectedPeriodBalance()
{
    showBalanceFromSelectedPeriod(incomes, "PRZYCHODOW", expenses, "WYDATKOW");
}

void UserManager::showCurrentMonthBalance()
{
    showBalanceFromCurrentMonth(incomes, "PRZYCHODOW", expenses, "WYDATKOW");
}

void UserManager::showPreviousMonthBalance()
{
    showBalanceFromPreviousMonth(incomes, "PRZYCHODOW", expenses, "WYDATKOW");
}
