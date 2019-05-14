#ifndef RIDE_H
#define RIDE_H

#include <iostream>
//#include "Cab.h"
#include "User.h"

using namespace std;

class Cab;
class Driver;

class Location
{
public:

private:
};


struct Date
{
    int date;
    int month;
    int year;
};

enum RideStatus
{
    RIDE_COMPLETED,
    RIDE_CANCELLED,
    RIDE_ON_GOING
};

class Ride
{
public:
    Ride() {}
    // all getters and setters

private:
    Location mSourceLocatoin;
    Location mDestinationLocation;
    Date mDate;
    int mStartTime; // 1204
    int mEndTime; // 1310
    RideStatus mRideStatus;
    Driver mDriver;
    int mCostOfTrip;
    Cab mCab;
    int mTotalDistance;

};

#endif // RIDE_H
