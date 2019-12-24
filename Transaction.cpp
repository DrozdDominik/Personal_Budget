#include "Transaction.h"

void Transaction::setId(int newId)
{
    id = newId;
}

void Transaction::setUserId(int newUserId)
{
    userId = newUserId;
}

void Transaction::setDate(int newDate)
{
    date = newDate;
    stringDate = AuxiliaryMethods::intToString(date);
    stringDate.insert(6,"-");
    stringDate.insert(4,"-");
}

void Transaction::setItem(string newItem)
{
    item = newItem;
}

void Transaction::setAmount(double newAmount)
{
    amount = newAmount;
    stringAmount = AuxiliaryMethods::doubleToString(amount);
}

int Transaction::getId()
{
    return id;
}

int Transaction::getUserId()
{
    return userId;
}

int Transaction::getDate()
{
    return date;
}

string Transaction::getItem()
{
    return item;
}

double Transaction::getAmount()
{
    return amount;
}

string Transaction::getStringDate()
{
    return stringDate;
}

string Transaction::getStringAmount()
{
    return stringAmount;
}
