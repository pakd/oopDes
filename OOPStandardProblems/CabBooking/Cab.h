#ifndef CAB_H
#define CAB_H

#include <iostream>
#include "Ride.h"
using namespace std;

class Cab
{
public:
    Cab() {}
    // all getters and setters

    void setLocation(Location location)
    {
        mCurrentLocation = location;
    }
    Location getLocation()
    {
        return mCurrentLocation;
    }

    void sendCurrentLocation()
    {

        // every 10 secs , send data to server
    }
private:
    int mVehicleId;
    string mLicensePlate;
    int mPassengerCapacity;
    string mModel;
    int mManufacturingYear;
    Location mCurrentLocation;

};

#endif // CAB_H
