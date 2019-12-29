#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H

#include <iostream>
#include <vector>
#include "Transaction.h"
#include "Markup.h"

using namespace std;

class FileWithTransactions
{
public:
    void addTransactionToFile (Transaction transaction, string fileName);
    vector <Transaction> loadTransactionsFromFile(string fileName, int idOfLoggedUser);

};

#endif
