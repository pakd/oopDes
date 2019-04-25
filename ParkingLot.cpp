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

class Vehicle
{
public:
    Vehicle(VehicleSize size, string licensePlate)
    {
        cout << "ctor of Vehicle class" << endl;
        mLicensePlate = licensePlate;
        mSize = size;

        //cout << mSize << endl;
        //cout << mLicensePlate << endl;
    }

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
};

class Car : public Vehicle
{
public:
    Car(string licensePlate) : Vehicle(VehicleSize::CAR, licensePlate)
    {
        cout << "ctor of Car class" << endl;
    }
};

class Bus : public Vehicle
{
public:
    Bus(string licensePlate) : Vehicle(VehicleSize::BUS, licensePlate)
    {
        cout << "ctor of Bus class" << endl;
    }
};

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


    ParkingSpot* placeVehicle(Vehicle vehicle)
    {
        VehicleSize vehicleSize = vehicle.getVehicleSize();

        ParkingSpot *ptrParkingSpot;
        switch(vehicleSize)
        {

        case VehicleSize::MOTORCYCLE :
            if(!mSmallSpotList.empty())
            {
                ptrParkingSpot = &mSmallSpotList.top();
                mSmallSpotList.pop();
                //mParkedVehicle[&vehicle] = ptrParkingSpot;
                mParkedVehicle.insert({&vehicle, ptrParkingSpot});
            }
            break;


        case VehicleSize::CAR :
            if(!mMediumSpotList.empty())
            {
                ptrParkingSpot = &mMediumSpotList.top();
                mMediumSpotList.pop();
                mParkedVehicle.insert({&vehicle, ptrParkingSpot});
            }
            break;

        case VehicleSize::BUS :
                if(!mLargeSpotList.empty())
                {
                    ptrParkingSpot = &mLargeSpotList.top();
                    mLargeSpotList.pop();
                    mParkedVehicle.insert({&vehicle, ptrParkingSpot});
                }
                break;
        }



        return ptrParkingSpot;
    }

    ParkingSpot* removeVehicle(Vehicle vehicle)
    {
        if(mParkedVehicle.find(&vehicle) != mParkedVehicle.end())
        {
            ParkingSpot *ptrParkingSpot = mParkedVehicle[&vehicle];

            VehicleSize vehicleSize = vehicle.getVehicleSize();

            switch(vehicleSize)
            {

            case VehicleSize::MOTORCYCLE :
                mSmallSpotList.push(*ptrParkingSpot);
                break;

            case VehicleSize::CAR :
                mMediumSpotList.push(*ptrParkingSpot);
                break;


            case VehicleSize::BUS :
                mLargeSpotList.push(*ptrParkingSpot);
                break;

            }

            return ptrParkingSpot;
        }
        else
        {
            cout << "Invalid Vehicle!, Throw exception" << endl;
        }



    }


private:
    ParkingLot()
    {
        // lets have 25 spots for every vehicle type
        int spotLimit = 25;

        // push all free small slots in stack
        // so that we can retrieve the spot in O(1)
        for(int i=1; i<=spotLimit; i++)
        {
            ParkingSpot temp(i, SpotSize::SMALL);
            mSmallSpotList.push(temp);
        }

        // push all free small slots in stack
        // so that we can retrieve the spot in O(1)
        for(int i=spotLimit + 1; i<=2*spotLimit ; i++)
        {
            ParkingSpot temp(i, SpotSize::MEDIUM);
            mMediumSpotList.push(temp);
        }

        // push all free small slots in stack
        // so that we can retrieve the spot in O(1)
        for(int i=2*spotLimit + 1; i<=3*spotLimit; i++)
        {
            ParkingSpot temp(i, SpotSize::LARGE);
            mLargeSpotList.push(temp);
        }

    }


    /* create 3 list or stacks for every spot type */
    stack<ParkingSpot> mSmallSpotList;
    stack<ParkingSpot> mMediumSpotList;
    stack<ParkingSpot> mLargeSpotList;

    // we can only take pointers to objects
    unordered_map<Vehicle*, ParkingSpot*> mParkedVehicle;

    static ParkingLot *mInstance;
};
// define static member in global
ParkingLot* ParkingLot::mInstance = NULL;

//------------------------------------------------------------------------------------------
int main()
{
    MotorCycle MotorCycleObject("KA05JX0297");

    // Park motorcycle
    ParkingSpot *spot1 = ParkingLot::getInstance()->placeVehicle(MotorCycleObject);
    cout << spot1->getSpotId() << endl;
    cout << spot1->getSpotSize() << endl;


    Car CarObject("DL03B7822");

    // Park car1
    ParkingSpot *spot2 = ParkingLot::getInstance()->placeVehicle(CarObject);
    cout << spot2->getSpotId() << endl;
    cout << spot2->getSpotSize() << endl;

    Car CarObject2("UP04J0007");

    // Par car2
    ParkingSpot *spot3 = ParkingLot::getInstance()->placeVehicle(CarObject2);
    cout << spot3->getSpotId() << endl;
    cout << spot3->getSpotSize() << endl;

    // remove car1
    ParkingSpot *spot4 = ParkingLot::getInstance()->removeVehicle(CarObject);
    cout << spot4->getSpotId() << endl;
    cout << spot4->getSpotSize() << endl;
    return 0;
}
