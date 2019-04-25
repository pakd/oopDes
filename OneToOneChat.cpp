#include <iostream>
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
    Address address;
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


class User
{
public:

    User(string userId, UserInfo userInfo)
    {
        mUserId = userId;
        mUserInfo = userInfo;
    }

    // getters for all fields

    string getMobile()
    {
        return mUserInfo.phoneNo;
    }

private:
    // mUserId can be the unique mobile no
    // it should be unique globally , so better check in DB for name userID conflicts
    string mUserId;
    UserInfo mUserInfo;

};

class Util
{
public:
    string IDGenerator()
    {
        // return random id string
    }
private:

};

class Message
{
public:
    Message(string messageBody, MessageType messageType)
    {
        mMessageBody = messageBody;
        mMessageType = messageType;

        Util *utilObj;
        mMessageId = utilObj->IDGenerator();
    }

    string getMessage()
    {
        return mMessageBody;
    }

private:
    MessageType mMessageType;
    string mMessageId;

    // MessageBody will contain the message if it texts
    // or url to audio, video, image, gif, etc.
    string mMessageBody;

};

// class which is responsible for sending message and receiving message
class MessagingService
{
    MessagingService() { }

    bool sendMessage(User fromUser, User toUser, Message message)
    {
        cout << "sending message from "  << fromUser.getMobile()
             << " to " << toUser.getMobile() << " : "
             << message.getMessage() << endl;

        // if successful
        return true;

        // return false; // if failed

    }

    // add logic for receiving message or maybe notify the user


};



int main()
{
    Address address1;
    address1.streetAddress = "a";
    address1.city = "b";
    address1.state = "c";
    address1.zipCode = "d";
    address1.country = "e";

    UserInfo userInfo1;
    userInfo1.userName = "f";
    userInfo1.address = address1;
    userInfo1.email = "g";
    userInfo1.phoneNo = "9876543210";

    User userObj("1234567890", userInfo1);

    cout << userObj.getMobile() << endl;


    return 0;
}
