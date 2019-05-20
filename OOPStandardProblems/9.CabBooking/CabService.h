#ifndef CAB_SERVICE_H
#define CAB_SERVICE_H

#include <iostream>
using namespace std;

class RideInfo
{
public:

private:
    Location source;
    Location Destination;
    int mPassenger;
};


class CabService
{
public:
    Ride BookCab(RideInfo rideInfo, Rider  rider)
    {
        /*
        1. get list of active and free cabs.
        2. find cab with minimum arrival time.
        3. sent the ride request to driver.
        4. if accepted by any driver
            5. find ETA  and Cost of trip
        6. Return Ride object to the application

        Note - we can think of all location as list of one d points on a line,
        we can find the the abs distance with rider's position and cab position
        cost of trip can be found as |Destination - Source| * cost_per_km for
        particular cab type.
        */
    }

private:

    list<Cab> CurrentCabs;

};

#endif // CAB_SERVICE_H
