#include <iostream>
using namespace std;


enum TranscationStatus
{
    SUCCESS,
    FAILURE,
    BLOCKED,
    FULL,
    PARTIAL,
    NONE
};

class Transaction
{
public:
    virtual bool  makeTransaction() = 0;
private:
    TransactionStatus mTransactionStatus;
    Date mTransactionDate;
    int mTransactionId;

};

class BalanceInquiry : public Transaction
{
public:

    bool makeTransaction() {}
private:
    int mAccountId;
    int amount;
};

class Withdraw : public Transaction
{
public:

    bool makeTransaction() {}
private:
    int amount;
};

class CashDeposit : public Transaction
{
public:

    bool makeTransaction() {}
private:
    int cashDepositLimit;


};

class ChequeDeposit : public Transaction
{
public:

    bool makeTransaction() {}
private:
    int checkNumber;
    int bankCode;

};

class Transfer : public Transaction
{
public:

    bool makeTransaction() {}
private:
    int destinationAccountNumber;
    int amount;
};
