#include <iostream>
using namespace std;

enum TransactionType
{
    BALANCE_INQUIRY,
    DEPOSIT_CASH,
    DEPOSIT_CHECK,
    WITHDRAW,
    TRANSFER
};

class CardReader
{

public:
    bool scanCard() {}
private:


};

class Screen
{

public:
    bool showMessage(string message) {}
    TransactionType getInput() {} // if touchscreen
private:
};

class CashDispenser
{
public:
    bool dispenseCash(int amount) {}
    bool canDispenseCash(int amount) {}
private:
    int mNoOf2000Notes;
    int mNoOf500Notes;
    int mNoOf200Notes;
    int mNoOf100Notes;
    int mNoOf50Notes;
};

class KeyPad
{
public:
    string getInput() {}
private:
};

class DespositSlot
{
public:
    bool depositCheque() {}
private:

};

class ChequeDepositSlot : public DepositSlot
{
public:
    getTotalAmount() {}
private:
    int mTotalAmount;

};
class CashDepositSlot : public DepositSlot
{
public:
    int receiveCash() {} // return amount received in slot
private:

};

class ReceiptFormat
{
public:
private:

};
class ReceiptSlot
{
public:
    printReceipt(ReceiptFormat receipt) {}
private:
};
