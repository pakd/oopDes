#include <iostream>
#include <list>
#include <queue>
using namespace std;

enum Direction
{
    UP,
    DOWN
};

enum State
{
    MOVING,
    STOPPED
};

enum Door
{
    OPEN,
    CLOSE
};

class Request
{
public:
    Request(int floor, Direction direction)
    {
        mTime = 1540; // system timestamp
        mFloor = floor;
        mDirection = direction;
    }


    int getTime()
    {
        return mTime;
    }

    int getFloor()
    {
        return mFloor;
    }

    Direction getDirection()
    {
        return mDirection;
    }

private:

    long mTime;
    int mFloor;
    Direction mDirection;
};

class FloorRequest : public Request
{
public:
    FloorRequest(int srcFloor, Direction direction) : Request(srcFloor, direction) // random timestamp
    {

    }
private:

};

class ElevatorRequest : public Request
{
public:
    ElevatorRequest(int targetFloor, Direction direction) : Request(targetFloor, direction) // random timestamp
    {

    }
private:

};

// class for priority queue
class ComparisonClass
{
public:
    bool operator() (FloorRequest a, FloorRequest b)
    {
        //comparison code here: return max in case of min heap
        return a.getTime() > b.getTime();
    }
};

class Elevator
{
public:
    Elevator(int NoOfFloor)
    {
        mFloorArr = new bool[NoOfFloor];
        mTargetFloorArr = new bool[NoOfFloor];

    }

    void setDirection(Direction direction)
    {
        mDirection = direction;
    }
    void setLocation(int floor)
    {
        mCurrentFloorLocation = floor;
    }
    void setDoor(Door door)
    {
        mDoor = door;
    }
    void setState(State state)
    {
        mState = state;
    }
    // other setters and getters

    Direction getDirection()
    {
        return mDirection;
    }

    void gotoFloor(int floor)
    {
        // direction can be decided by mCurrentFloorLocation and floor passed here
        setState(State::MOVING);

        // maybe progress bar
        // thread to print delay

        setLocation(floor);
        setDoor(Door::OPEN);
        setState(State::STOPPED);
        setDoor(Door::CLOSE);
    }

    void process()
    {
        // pick the earliest time stamp request from queues and handle them;
        // FloorRequestObj
        // goToFloor(FloorRequestObj.getFloor());
        // handleElevatorRequest(targetFloor, direction)
        // change queue after sometime or after completing trips
        // after going to target floor make it false
    }

    void handleElevatorRequest(int targetFloor, Direction direction)
    {
        ElevatorRequest ElevatorRequestObj(targetFloor, direction);
        mTargetFloorArr[targetFloor] = true;
    }

    void handleFloorRequest(int srcFloor, Direction direction)
    {

        FloorRequest FloorRequestObj(srcFloor, direction);

        // case 1: if direction is up and lift is also going up
        if(getDirection() == Direction::UP)
        {
            if(srcFloor >= mCurrentFloorLocation)
            {
                currentQueue.push(FloorRequestObj);
            }
            else
            {
                upQueue.push(FloorRequestObj);
            }
        }

        else // (direction == Direction::DOWN)
        {
            if(srcFloor <= mCurrentFloorLocation)
            {
                currentQueue.push(FloorRequestObj);
            }
            else
            {
                downQueue.push(FloorRequestObj);
            }
        }
    }

private:
    Direction mDirection;
    State mState;
    Door mDoor;

    int mElevatorId;
    double mMaxSpeed;
    int mCurrentFloorLocation;
    bool *mFloorArr; // supported floors;
    bool *mTargetFloorArr; // target floors
    int capacity; // to check overloaded or not

    priority_queue<FloorRequest, vector<FloorRequest>, ComparisonClass > currentQueue;
    priority_queue<FloorRequest, vector<FloorRequest>, ComparisonClass > upQueue;
    priority_queue<FloorRequest, vector<FloorRequest>, ComparisonClass > downQueue;

};

class ElevatorSystem
{
    // one ElevatorSystem can have multiple elevators
    // job of elevator system is to optimize the elevator's logic
    // and issue requests to different elevators
public:
    ElevatorSystem()
    {

    }
    void addElevator(Elevator elevator)
    {
        mElevatorList.push_back(elevator);
    }
private:
    list<Elevator> mElevatorList;
};


int main()
{
    ElevatorSystem ElevatorSystemObj;
    return 0;
}
