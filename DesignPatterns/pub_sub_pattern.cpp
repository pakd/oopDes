#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
Message class which stores the message payload and messageId
*/
enum MessageType
{
    TEXT,
    IMAGE,
    GIF,
    AUDIO,
    VIDEO,
};

class Message
{
public:

    Message(string messagePayload, string messageTopic, MessageType messageType)
    {
        mMessagePayload = messagePayload;
        mMessageTopic = messageTopic;
        mMessageType = messageType;
    }

    string getMessageTopic()
    {
        return mMessageTopic;
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
    string mMessageTopic;
    MessageType mMessageType;

};


/*
Receiver applications that choose which topics to receive message from
*/
class Subscriber
{
public:

    Subscriber()
    {

    }

    void addTopic(string newTopic)
    {
        mTopics.push_back(newTopic);
    }

    void printMessages()
    {
        cout << __func__ << endl;
        while(!mMyMessages.empty())
        {
            Message *tempMessage = mMyMessages.front();
            mMyMessages.pop();

            cout << tempMessage->getMessageTopic() << " "
                 << tempMessage->getMessageType() << " "
                 << tempMessage->getMessagePayload() << endl;
        }
    }

    void pushMessage(Message *message)
    {
        mMyMessages.push(message);
    }

    vector<string> getTopics()
    {
        return mTopics;
    }

private:
    vector<string> mTopics;

    queue<Message*> mMyMessages;



};

/*
The director of all messages and defines a uniform message structure
or
Middleman
*/
class PubSubServer
{
public:

    PubSubServer()
    {

    }

    void forward()
    {
        while(!mBuffer.empty())
        {
            Message *tempMessage = mBuffer.front();
            mBuffer.pop();
            for(auto subs : mSubscribers)
            {
                for(auto tops : subs->getTopics())
                {
                    if( tops.compare(tempMessage->getMessageTopic()) == 0)
                    {
                        subs->pushMessage(tempMessage);
                    }
                }
            }

        }
    }

    void pushMessageToServer(Message *message)
    {
        mBuffer.push(message);
    }

    void addSubscriber(Subscriber *subcriber)
    {
        mSubscribers.push_back(subcriber);
    }

private:

    queue<Message*> mBuffer;
    vector<Subscriber*> mSubscribers;

};




/*
Sender application that tags each message with the name of a topic
*/
class Publisher
{
public:

    Publisher()
    {

    }
    void sendMessage(Message *newMessage, PubSubServer *myServer)
    {
        myServer->pushMessageToServer(newMessage);
    }
};


int main()
{
    // sample code
    Message message("Hi, dog lovers", "dog", MessageType::TEXT);

    Subscriber DogSubscriber;
    DogSubscriber.addTopic("dog");

    PubSubServer myServer;
    myServer.addSubscriber(&DogSubscriber);

    Publisher DogPublishers;
    DogPublishers.sendMessage(&message, &myServer);

    myServer.forward();

    DogSubscriber.printMessages();


    return 0;
}
