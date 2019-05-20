#include<iostream>
using namespace std;

class Address {
public:
private:
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};

class Account
{
public:
    Account() {}
    bool addCard(Card) {}
    bool addNetBankingMethod(NetBanking) {}
    bool resetPassword() {}
    ShoppingCart* getShoppingCart() {}
private:
    string mUsername;
    string mPassword; // hash
    string mName;
    Address mAddress;
    string mPhoneNo;
    string mEmailId;

    list<Card> mCards;
    list<NetBanking> mNetBankings;

    ShoppingCart* mShoppingCart;

    bool isPrimeMember;
    int mAmazonPayBalance;
    int mBalance

};
