#include "FileWithTransactions.h"

void FileWithTransactions::addTransactionToFile (Transaction transaction, string fileName) {
    CMarkup xml;
    bool fileExists = xml.Load(fileName);
    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("TRANSACTIONS");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("TRANSACTION");
    xml.IntoElem();
    {
        xml.AddElem("ID", transaction.getId());
        xml.AddElem("USERID", transaction.getUserId());
        xml.AddElem("DATE", AuxiliaryMethods::intDateToStringDate(transaction.getDate()));
        xml.AddElem("ITEM", transaction.getItem());
        xml.AddElem("AMOUNT", transaction.getStringAmount());
    }
    xml.OutOfElem();
    xml.Save(fileName);
}

vector <Transaction> FileWithTransactions::loadTransactionsFromFile(string fileName, int idOfLoggedUser) {
    vector <Transaction> transactions;
    CMarkup xml;
    xml.Load(fileName);
    xml.FindElem("TRANSACTIONS");
    xml.IntoElem();
    while (xml.FindElem("TRANSACTION")) {
        Transaction transaction;
        xml.IntoElem();
        xml.FindElem("ID");
        transaction.setId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("USERID");
        transaction.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("DATE");
        transaction.setDate(AuxiliaryMethods::stringDateTointDate(xml.GetData()));
        xml.FindElem("ITEM");
        transaction.setItem(xml.GetData());
        xml.FindElem("AMOUNT");
        transaction.setAmount(AuxiliaryMethods::stringToDouble(xml.GetData()));
        transactions.push_back(transaction);
        xml.OutOfElem();
    }
    return transactions;
}
