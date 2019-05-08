#include<iostream>
using namespace std;


class Address
{
public:
private:
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};

class ATM
{
public:

    bool makeTransaction(Transaction transaction) {}
private:
    int mATMId;

    Address mAddress;

    CashDispenser mCashDispenser;
    Keypad mKeypad;
    Screen mScreen;
    ReceiptSlot mReceiptSlot;
    ChequeDepositSlot mChequeDepositSlot;
    CashDepositSlot mCheckDepositSlot;

};

class Date
{
public:
private:
    int date;
    int month;
    int year;
};

class Card
{
public:
private:
    string mCardNumber;
    string mCustomerName; // optional , check
    int mPin;
    Date mCardExpiry;
};
