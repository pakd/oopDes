#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Address
{
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};

struct UserInfo
{
    string userName;
    // Address address; // can be added later
    string email;
    string phoneNo;
};

enum MessageType
{
    TEXT,
    IMAGE,
    AUDIO,
    VIDEO,
    GIF
};

// Class for message structure
class Message
{
public:

    Message(string messagePayload,  MessageType messageType)
    {
        cout << endl << __func__ << endl;
        mMessagePayload = messagePayload;
        mMessageType = messageType;
    }

    string getMessagePayload()
    {
        return mMessagePayload;
    }

    MessageType getMessageType()
    {
        return mMessageType;
    }

    // can also take message id for history or future references

private:

    string mMessagePayload;
    MessageType mMessageType;

};


// all users of chat-app have to make object of User class by passing the UserInfo
class User
{
public:

    User(UserInfo userInfo)
    {
        cout << endl << __func__ << endl;
        mUserInfo = userInfo;
    }

    // getters for all fields

    string getMobile()
    {
        return mUserInfo.phoneNo;
    }

    string getUserName()
    {
        return mUserInfo.userName;
    }

    string getEmail()
    {
        return mUserInfo.email;
    }

    void receiveMessage(Message *message)
    {
        cout << endl << __func__ << endl;
        cout << message->getMessagePayload() << " " << message->getMessageType();
    }

    void addFollower(User *user)
    {
        cout << endl << __func__ << endl;

        mFollowers.push_back(user);
    }

    void removeFollower(User *user)
    {
        cout << endl << __func__ << endl;

        auto position = find(mFollowers.begin(), mFollowers.end(), user);
        if(position != mFollowers.end())
        {
            mFollowers.erase(position);
        }
    }

    void sendMessage(Message  *message)
    {
        for (auto followers: mFollowers)
        {
            followers->receiveMessage(message);
        }
    }

private:
    UserInfo mUserInfo;
    vector<User*> mFollowers;

};

// utility class can be used for generating random Ids
class Util
{
public:
    string IDGenerator()
    {
        // return random id string
    }
private:

};



// class which is responsible for sending message
class MessagingService
{
public:

    MessagingService() { cout << endl << __func__ << endl; }

    void sendMessage(User *fromUser, Message *message)
    {
        cout << endl << __func__ << endl;
        cout << "sending message from "  << fromUser->getUserName()
             << " to followers of "  << fromUser->getUserName() << " : "
             << message->getMessagePayload() << endl;

        fromUser->sendMessage(message);
    }
};



int main()
{
    // user 1
    UserInfo userInfo1;
    userInfo1.userName = "papa";
    userInfo1.email = "p";
    userInfo1.phoneNo = "9811524635";

    User userObj1(userInfo1);

    // user 2
    UserInfo userInfo2;
    userInfo2.userName = "Maa";
    userInfo2.email = "g";
    userInfo2.phoneNo = "9210045362";

    User userObj2(userInfo2);

    // user 3
    UserInfo userInfo3;
    userInfo3.userName = "bacha";
    userInfo3.email = "d";
    userInfo3.phoneNo = "8960684031";

    User userObj3(userInfo3);

    // adding followers 2 and 3 to 1
    userObj1.addFollower(&userObj2);
    userObj1.addFollower(&userObj3);

    // sample message
    Message message("Hi, followers",  MessageType::TEXT);


    // user 1 sending message to user 2
    MessagingService messagingServiceObj;
    messagingServiceObj.sendMessage(&userObj1, &message);

    userObj1.removeFollower(&userObj2);

    messagingServiceObj.sendMessage(&userObj1, &message);

    return 0;
}
