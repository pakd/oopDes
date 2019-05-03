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

struct Request
{
    long time;
    int floor;
    Direction direction;
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

    void putRequest(int floor, Direction direction)
    {

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

    queue<Request> currentQueue;
    queue<Request> upQueue;
    queue<Request> downQueue;

};

class ElevatorSystem
{
    // one elevator can have multiple elevators
    // job of elevator system is to optimize the elevator's logic
    // and issue requests to different elevators
public:
private:
    list<Elevator> mElevatorList;
};



int main()
{

}
