#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>

struct Address
{
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;
    std::string country;
};

struct UserInfo
{
    std::string userName;
    // Address address; // can be added later
    std::string email;
    std::string phoneNo;
};

// all users of chat-app have to make object of User class by passing the UserInfo
class User
{
public:

    User(UserInfo userInfo)
    {
        std::cout << std::endl << __func__ << std::endl;
        mUserInfo = userInfo;
    }

    // getters for all fields

    std::string getMobile()
    {
        return mUserInfo.phoneNo;
    }

    std::string getUserName()
    {
        return mUserInfo.userName;
    }

    std::string getEmail()
    {
        return mUserInfo.email;
    }

private:
    UserInfo mUserInfo;

};

class Player : public User
{
public:

    Player(UserInfo userInfo, bool isWhite) : User(userInfo)
    {
        mIsWhite = isWhite;
    }

private:

    bool mIsWhite;

};

#endif // PLAYER_H_INCLUDED
