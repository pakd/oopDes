#include<iostream>
using namespace std;

struct Address {
    String streetAddress;
    String city;
    String state;
    String zipCode;
    String country;
};

class Account
{
public:
    Account() {}
    bool addCard(Card) {}
    bool addNetBankingMethod(NetBanking) {}
    bool resetPassword() {}
private:
    string mUsername;
    string mPassword; // hash
    string mName;
    Address mAddress;
    string mPhoneNo;
    string mEmailId;

    list<Card> mCards;
    list<NetBanking> mNetBankings;
    bool isPrimeMember;
    int mAmazonPayBalance;
    int mBalance

};
