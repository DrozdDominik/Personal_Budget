#include "FileWithTransactions.h"

void FileWithTransactions::addTransactionToFile (Transaction transaction, string fileName) {
    CMarkup xml;
    xml.Load(fileName);
    xml.AddElem("TRANSACTION");
    xml.IntoElem();
    {
        xml.AddElem("ID", transaction.getId());
        xml.AddElem("USERID", transaction.getUserId());
        xml.AddElem("DATE", transaction.getDate());
        xml.AddElem("ITEM", transaction.getItem());
        xml.AddElem("AMOUNT", transaction.getStringAmount());
    }
    xml.OutOfElem();
    xml.Save(fileName);
}
