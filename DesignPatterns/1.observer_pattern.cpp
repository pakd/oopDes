#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer;
class Car;

// position = -1 0 1
class Car // subject class
{
public:
    int getPosition()
    {
        return mPosition;
    }
    void setPosition(int position)
    {
        mPosition = position;
        notify();
    }
    void attach(Observer* observer)
    {
        mObserverList.push_back(observer);
    }
    void detach(Observer* observer)
    {
        // position of observer in list
        auto position = find(mObserverList.begin(), mObserverList.end(), observer);
        if(position != mObserverList.end())
        {
            mObserverList.erase(position);
        }
    }
private:

    int mPosition; // observable resource
    vector<class Observer*> mObserverList;

    void notify()
    {
        for(auto observer : mObserverList)
        {
            observer->update();
        }
    }
};

class Observer
{
public:
    Observer(Car* car)
    {
        mCar = car;
        mCar->attach(this); // attaching the object to the subject
    }

    virtual void update() = 0;
private:
    Car* mCar;

protected:
    Car* getCar()
    {
        return mCar;
    }

};

class LeftObserver : public Observer
{
public:
    LeftObserver(Car* car) : Observer(car) { }
    void update()
    {
        // do whatever you want to do here
        int pos = getCar()->getPosition();
        if(pos < 0)
        {
            cout << "left side" << endl;
        }
    }
private:

};

class RightObserver : public Observer
{
public:
    RightObserver(Car* car) : Observer(car) { }
    void update()
    {
        // do whatever you want to do here
        int pos = getCar()->getPosition();
        if(pos > 0)
        {
            cout << "right side" << endl;
        }
    }
private:

};

class MiddleObserver : public Observer
{
public:
    MiddleObserver(Car* car) : Observer(car) { }
    void update()
    {
        // do whatever you want to do here
        int pos = getCar()->getPosition();
        if(pos == 0)
        {
            cout << "In middle" << endl;
        }
    }
private:

};

int main()
{
    Car* car = new Car();

    LeftObserver leftObserver(car);
    RightObserver rightObserver(car);
    MiddleObserver middleObserver(car);

    bool isStop = false;

    char pressButton;
    while(!isStop)
    {
        cin >> pressButton;
        switch(pressButton)
        {
            // 'l' : left
            case 108:
                car->setPosition(-1);
                break;
            // 'c' : centre
            case 99:
                car->setPosition(0);
                break;

            // 'r' : right
            case 114:
                car->setPosition(1);
                break;

            // 'b' : back
            case 98:
                isStop = true;
                break;

            default:
                cout << "Please try carefully" << endl;
                break;
        }
    }


    return 0;
}



