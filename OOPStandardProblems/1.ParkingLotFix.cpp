/*
This design is improvement over the first parking lot design
as previous design was using many switch cases for vehicle type
the new design is free of switch cases in place vehicle and remove vehicle functions/
*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;


enum VehicleSize
{
    MOTORCYCLE,
    CAR,
    BUS
};

enum SpotSize
{
    SMALL,
    MEDIUM,
    LARGE
};

// color enum if you want

//------------------------------------------------------------------------------------------

class ParkingSpot; // for prototype
class ParkingLot; // for prototype
class Vehicle; // for prototype

//------------------------------------------------------------------------------------------

// We can make different classes for each type of spot derived from ParkingSpot,
// but it is just a overkill, so not required

class ParkingSpot
{
public:

    ParkingSpot(int spotId, SpotSize size)
    {
        mSpotId = spotId;
        mSize = size;
    }

    int getSpotId()
    {
        return mSpotId;
    }

    SpotSize getSpotSize()
    {
        return mSize;
    }


private:

    int mSpotId;
    SpotSize mSize;
    // add more variables to this class
    // if multiple levels and rows are in parking spot
};

//------------------------------------------------------------------------------------------
// We have to initialize all the spots once, so it is ok to have Singleton class
// or singleton pattern

class ParkingLot
{
public:
    static ParkingLot* getInstance()
    {
        if( !mInstance )
        {
            mInstance = new ParkingLot();
        }

        return mInstance;
    }

private:
    ParkingLot()
    {
        // lets have 25 spots for every vehicle type
        int spotLimit = 25;

        // push all free small slots in stack
        // so that we can retrieve the spot in O(1)
        // similarly for other spot types
        for(int i=1; i<=spotLimit; i++)
        {
            ParkingSpot temp(i, SpotSize::SMALL);
            mSmallSpotList.push(temp);
        }

        for(int i=spotLimit + 1; i<=2*spotLimit ; i++)
        {
            ParkingSpot temp(i, SpotSize::MEDIUM);
            mMediumSpotList.push(temp);
        }

        for(int i=2*spotLimit + 1; i<=3*spotLimit; i++)
        {
            ParkingSpot temp(i, SpotSize::LARGE);
            mLargeSpotList.push(temp);
        }

    }
    static ParkingLot *mInstance;

public:
    /* create 3 lists or stacks for every spot type */
    stack<ParkingSpot> mSmallSpotList;
    stack<ParkingSpot> mMediumSpotList;
    stack<ParkingSpot> mLargeSpotList;

    // we can only take pointers to objects
    unordered_map<Vehicle*, ParkingSpot*> mParkedVehicle;


};
// define static member in global
ParkingLot* ParkingLot::mInstance = NULL;


class Vehicle
{
public:
    Vehicle(VehicleSize size, string licensePlate)
    {
        cout << "ctor of Vehicle class" << endl;
        mLicensePlate = licensePlate;
        mSize = size;
    }

    // pure virtual functions that sub-classes will implement
    virtual ParkingSpot* placeVehicle(Vehicle *vehicle) = 0;
    virtual ParkingSpot* removeVehicle(Vehicle *vehicle) = 0;


    // make all getter functions for private members
    string getLicensePlate()
    {
        return mLicensePlate;
    }

    VehicleSize getVehicleSize()
    {
        return mSize;
    }


private:
    string mLicensePlate;
    VehicleSize mSize;
};

//------------------------------------------------------------------------------------------
// all subclasses are derived from Vehicle class

class MotorCycle : public Vehicle
{
public:
    MotorCycle(string licensePlate) : Vehicle(VehicleSize::MOTORCYCLE, licensePlate)
    {
        cout << "ctor of MotorCycle class" << endl;
    }

    ParkingSpot* placeVehicle(Vehicle *vehicle)
    {
        ParkingSpot *ptrParkingSpot;
        ParkingLot *parkingLotObj = ParkingLot::getInstance();



        if(!parkingLotObj->mSmallSpotList.empty())
        {
            ptrParkingSpot = &parkingLotObj->mSmallSpotList.top();
            parkingLotObj->mSmallSpotList.pop();
            //mParkedVehicle[&vehicle] = ptrParkingSpot;
            parkingLotObj->mParkedVehicle.insert({vehicle, ptrParkingSpot});

            return ptrParkingSpot;
        }
        else
        {
            // check in next bigger slot or throw exception that no slot is found.
        }
    }

    ParkingSpot* removeVehicle(Vehicle *vehicle)
    {
        ParkingLot *parkingLotObj = ParkingLot::getInstance();
        if(parkingLotObj->mParkedVehicle.find(vehicle) != parkingLotObj->mParkedVehicle.end())
        {
            ParkingSpot *ptrParkingSpot = parkingLotObj->mParkedVehicle[vehicle];

            parkingLotObj->mSmallSpotList.push(*ptrParkingSpot);

            // remove from map
            auto it = parkingLotObj->mParkedVehicle.find(vehicle);
            parkingLotObj->mParkedVehicle.erase(it);

            return ptrParkingSpot;
        }
        else
        {
            cout << "Invalid Vehicle!, Throw exception" << endl;
        }
    }

};

class Car : public Vehicle
{
public:
    Car(string licensePlate) : Vehicle(VehicleSize::CAR, licensePlate)
    {
        cout << "ctor of Car class" << endl;
    }

    ParkingSpot* placeVehicle(Vehicle *vehicle)
    {
        ParkingSpot *ptrParkingSpot;
        ParkingLot *parkingLotObj = ParkingLot::getInstance();

        if(!parkingLotObj->mMediumSpotList.empty())
        {
            ptrParkingSpot = &parkingLotObj->mMediumSpotList.top();
            parkingLotObj->mMediumSpotList.pop();
            //mParkedVehicle[&vehicle] = ptrParkingSpot;
            parkingLotObj->mParkedVehicle.insert({vehicle, ptrParkingSpot});

            return ptrParkingSpot;
        }
        else
        {
            // check in next bigger slot or throw exception that no slot is found.
        }
    }

    ParkingSpot* removeVehicle(Vehicle *vehicle)
    {
        ParkingLot *parkingLotObj = ParkingLot::getInstance();
        if(parkingLotObj->mParkedVehicle.find(vehicle) != parkingLotObj->mParkedVehicle.end())
        {
            ParkingSpot *ptrParkingSpot = parkingLotObj->mParkedVehicle[vehicle];

            parkingLotObj->mMediumSpotList.push(*ptrParkingSpot);

            // remove from map
            auto it = parkingLotObj->mParkedVehicle.find(vehicle);
            parkingLotObj->mParkedVehicle.erase(it);

            return ptrParkingSpot;
        }
        else
        {
            cout << "Invalid Vehicle!, Throw exception" << endl;
        }
    }
};

class Bus : public Vehicle
{
public:
    Bus(string licensePlate) : Vehicle(VehicleSize::BUS, licensePlate)
    {
        cout << "ctor of Bus class" << endl;
    }

    ParkingSpot* placeVehicle(Vehicle *vehicle)
    {
        ParkingSpot *ptrParkingSpot;
        ParkingLot *parkingLotObj = ParkingLot::getInstance();

        if(!parkingLotObj->mLargeSpotList.empty())
        {
            ptrParkingSpot = &parkingLotObj->mLargeSpotList.top();
            parkingLotObj->mLargeSpotList.pop();
            //mParkedVehicle[&vehicle] = ptrParkingSpot;
            parkingLotObj->mParkedVehicle.insert({vehicle, ptrParkingSpot});

            return ptrParkingSpot;
        }
        else
        {
            // check in next bigger slot or throw exception that no slot is found.
        }
    }

    ParkingSpot* removeVehicle(Vehicle *vehicle)
    {
        ParkingLot *parkingLotObj = ParkingLot::getInstance();
        if(parkingLotObj->mParkedVehicle.find(vehicle) != parkingLotObj->mParkedVehicle.end())
        {
            ParkingSpot *ptrParkingSpot = parkingLotObj->mParkedVehicle[vehicle];

            parkingLotObj->mLargeSpotList.push(*ptrParkingSpot);

            // remove from map
            auto it = parkingLotObj->mParkedVehicle.find(vehicle);
            parkingLotObj->mParkedVehicle.erase(it);

            return ptrParkingSpot;
        }
        else
        {
            cout << "Invalid Vehicle!, Throw exception" << endl;
        }
    }
};


//------------------------------------------------------------------------------------------
int main()
{
    MotorCycle MotorCycleObject("KA05JX0297");

    // Park motorcycle
    ParkingSpot *spot1 = MotorCycleObject.placeVehicle(&MotorCycleObject);
    cout << "spotId : " << spot1->getSpotId() << endl;
    cout << "spotSize : " << spot1->getSpotSize() << endl << endl;


    Car CarObject("DL03B7822");

    // Park car1
    ParkingSpot *spot2 = CarObject.placeVehicle(&CarObject);
    cout << "spotId : " << spot2->getSpotId() << endl;
    cout << "spotSize : " << spot2->getSpotSize() << endl << endl;

    Car CarObject2("UP04J0007");

    // Par car2
    ParkingSpot *spot3 = CarObject2.placeVehicle(&CarObject2);
    cout << "spotId : " << spot3->getSpotId() << endl;
    cout << "spotSize : " << spot3->getSpotSize() << endl << endl;

    // remove car1
    ParkingSpot *spot4 = CarObject2.removeVehicle(&CarObject);
    cout << "spot freed: " << endl;
    cout << "spotId : " << spot4->getSpotId() << endl;
    cout << "spotSize : " << spot4->getSpotSize() << endl;

    return 0;
}
