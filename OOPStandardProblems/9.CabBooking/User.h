#ifndef USER_H
#define USER_H

#include <iostream>
#include<list>
#include "Cab.h"

class Ride;
class Cab;
using namespace std;

struct Address
{
  string streetAddress;
  string city;
  string state;
  string zipCode;
  string country;
};

class User
{
public:
    User()
    {
        // setting all values
    }
    // all getters and setters
private:
    string mUserName;
    string mAccountId;
    string mMobileNo;
    string mEmail;
    Address mAddress;


};

class Rider : public User
{
public:
    Rider() : User()
    {
    }


private:
    list<Ride> mRideHistory;

};

class Driver : public User
{
public:
    Driver() : User()
    {

    }

    // all getters and setters
private:
    Cab mCab;
    string mDrivingLicenseNumber;
    string mLicenseValidFrom;
    int mNoOfRidesCompletedSoFar; // for rating and showing to the user, uber feature.


};

#endif // USER_H
