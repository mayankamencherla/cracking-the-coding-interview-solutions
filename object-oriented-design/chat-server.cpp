/**
 * Design a chat server
 */

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <ctime>

using namespace std;

class ChatServer;

class Message
{
    private:
        /**
         * The text of the message
         * @param string text
         */
        string text;

        /**
         * The user that is sending the message
         * @param string from
         */
        string from;

        /**
         * The channel or user that the message is intended for
         * @param string to
         */
        string to;

        /**
         * The time when the message was created
         * @param string createdAt
         */
        string createdAt;

        /**
         * The time when the message was received by the channel
         * @Param string receivedAt
         */
        string receivedAt;

    public:
        Message(string& text, string& from, string& to)
        {
            this->text = text;

            this->from = from;

            this->to = to;

            this->generateCreatedAt();

            this->receivedAt = -1;

            // this->print();
        }

        /**
         * Generates the current timestamp of the message
         * @return void
         */
        void generateCreatedAt()
        {
            this->createdAt = this->currentTimestamp();
        }

        /**
         * Generates the received at timestamp of the message
         * @return void
         */
        void generateReceivedAt()
        {
            this->receivedAt = this->currentTimestamp();
        }

        /**
         * Returns the current timestamp
         * @return string
         */
        string currentTimestamp()
        {
            auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

            return ctime(&timenow);
        }

        /**
         * Prints the properties of the message
         * @return void
         */
        void print()
        {
            printf("Message Properties: \n Created at: %s\n From: %s\n To: %s\n Text: %s\n",
                this->createdAt.c_str(), this->from.c_str(), this->to.c_str(), this->text.c_str());
        }
};

class User
{
    private:
        /**
         * Name of the user
         * @param string name
         */
        string name;

        /**
         * Pointer to an instance of the chat server
         * @param ChatServer* server
         */
        ChatServer* server;

        /**
         * The user can store a configurable number of messages in the history
         * @param list<Message*> history
         */
        list<Message*> history;

        /**
         * Number of messages that can be stored in the history
         * @param int cacheSize;
         */
        int cacheSize;

    public:
        User(string& n, ChatServer* s, int cSize);

        /**
         * User withdraws from channel
         * @param string& channel
         * @return void
         */
        void leaveChannel(string& channel);

        /**
         * User join the channel
         * @param string& channel
         * @return void
         */
        void joinChannel(string& channel);

        /**
         * User sends a message to the channel / user name
         * @param string& channel
         * @param string& text
         * @return void
         */
        void message(string& channel, string& text);

        /**
         * Returns whether the history is full
         * @return bool
         */
        bool isHistoryFull();

        /**
         * Notification when a user receives a message
         * @param Message* m
         * @return void
         */
        void receiveMessage(Message* m);

        /**
         * Returns the name of the user
         * @return string
         */
        string getName();

        /**
         * Prints the properties of the user
         * @return void
         */
        void print();
};

class ChatServer
{
    private:
        /**
         * A mapping from users to their channels
         * @param unordered_map<User*, unordered_set<string>> userChannels
         */
        unordered_map<User*, unordered_set<string>> userChannels;

        /**
         * A mapping from channels to their users
         * @param unordered_map<string, unordered_set<User*>> channelUsers
         */
        unordered_map<string, unordered_set<User*>> channelUsers;

    public:
        ChatServer(){}

        /**
         * Returns whether the user is already in the chat server
         * @param User* u
         * @return bool
         */
        bool userInChatServer(User* u);

        /**
         * Returns whether the channel is already in the chat server
         * @param string& c
         * @return bool
         */
        bool channelInChatServer(string& c);

        /**
         * Adds a user to list of users
         * @param User* u
         * @return void
         */
        void addUser(User* u);

        /**
         * Adds a channel to the list of channels
         * @param string& c
         * @return void
         */
        void addChannel(string& c);

        /**
         * Returns the channels the user is a part of
         * @param User* u
         * @return unordered_set<string>
         */
        unordered_set<string> getUserChannels(User* u);

        /**
         * Returns whether the user is in the channel
         * @param User* u
         * @param string& channel
         * @return bool
         */
        bool userInChannel(User* u, string& channel);

        /**
         * Adds a user to a channel
         * @param User* u
         * @param string& c
         * @return void
         */
        void addUserToChannel(User* u, string& c);

        /**
         * Removes a user from a channel
         * @param User* u
         * @param string& c
         * @return void
         */
        void removeUserFromChannel(User* u, string& c);

        /**
         * Sends the channel the text message
         * @param User* u
         * @param string& channel
         * @param string& text
         * @return void
         */
        void sendMessage(User* u, string& channel, string& text);

        /**
         * Prints all the users in the chat server
         * @return void
         */
        void printAllUsers()
        {
            unordered_map<User*, unordered_set<string>>::iterator it;

            printf("The ChatServer contains %lu users\n", userChannels.size());

            int index = 1;

            for (it = userChannels.begin(); it != userChannels.end(); it++)
            {
                printf("-----------------------------------------\n");

                printf("User %d\n", index);

                it->first->print();

                index++;
            }
        }
};

User::User(string& n, ChatServer* s, int cSize)
{
    this->name = n;

    this->server = s;

    this->cacheSize = cSize;

    this->server->addUser(this);
}

/**
 * User withdraws from channel
 * @param string& channel
 * @return void
 */
void User::leaveChannel(string& channel)
{
    if (this->server->userInChannel(this, channel))
    {
        this->server->removeUserFromChannel(this, channel);
    }
}

/**
 * User join the channel
 * @param string& channel
 * @return void
 */
void User::joinChannel(string& channel)
{
    if (!this->server->userInChannel(this, channel))
    {
        this->server->addUserToChannel(this, channel);
    }
}

/**
 * User sends a message to the channel / user name
 * @param string& channel
 * @param string& text
 * @return void
 */
void User::message(string& channel, string& text)
{
    this->joinChannel(channel);

    this->server->sendMessage(this, channel, text);
}

/**
 * Returns whether the history is full
 * @return bool
 */
bool User::isHistoryFull()
{
    return this->history.size() == this->cacheSize;
}

/**
 * Notification when a user receives a message
 * @param Message* m
 * @return void
 */
void User::receiveMessage(Message* m)
{
    printf("-----------------------------------------\n");

    printf("Message received by user %s\n", this->getName().c_str());

    m->print();

    if (this->isHistoryFull())
    {
        this->history.pop_back();
    }

    this->history.push_front(m);
}

/**
 * Returns the name of the user
 * @return string
 */
string User::getName()
{
    return this->name;
}

/**
 * Prints the properties of the user
 * @return void
 */
void User::print()
{
    printf("The user has name : %s\n", this->name.c_str());

    unordered_set<string> channels = this->server->getUserChannels(this);

    printf("The user is part of %lu channels\n\n", channels.size());

    int i=1;

    for (string channel : channels)
    {
        printf("%d. %s\n", i, channel.c_str());

        i++;
    }

    cout << endl;
}

/**
 * Returns whether the user is already in the chat server
 * @param User* u
 * @return bool
 */
bool ChatServer::userInChatServer(User* u)
{
    unordered_map<User*, unordered_set<string>>::iterator it = this->userChannels.find(u);

    return it != this->userChannels.end();
}

/**
 * Returns whether the channel is already in the chat server
 * @param string& c
 * @return bool
 */
bool ChatServer::channelInChatServer(string& c)
{
    unordered_map<string, unordered_set<User*>>::iterator it = this->channelUsers.find(c);

    return it != channelUsers.end();
}

/**
 * Adds a user to list of users
 * @param User* u
 * @return void
 */
void ChatServer::addUser(User* u)
{
    if (!this->userInChatServer(u))
    {
        this->userChannels[u] = {};
    }
}

/**
 * Adds a channel to the list of channels
 * @param string& c
 * @return void
 */
void ChatServer::addChannel(string& c)
{
    if (!this->channelInChatServer(c))
    {
        this->channelUsers[c] = {};
    }
}

/**
 * Returns the channels the user is a part of
 * @param User* u
 * @return unordered_set<string>
 */
unordered_set<string> ChatServer::getUserChannels(User* u)
{
    return this->userChannels[u];
}

/**
 * Returns whether the user is in the channel
 * @param User* u
 * @param string& channel
 * @return bool
 */
bool ChatServer::userInChannel(User* u, string& channel)
{
    if (!this->userInChatServer(u)) return false;

    unordered_set<string> channels = this->getUserChannels(u);

    return channels.find(channel) != channels.end();
}

/**
 * Adds a user to a channel
 * @param User* u
 * @param string& c
 * @return void
 */
void ChatServer::addUserToChannel(User* u, string& c)
{
    this->addUser(u);

    this->addChannel(c);

    this->userChannels[u].insert(c);

    this->channelUsers[c].insert(u);

    printf("-----------------------------------------\n");

    printf("User: %s has joined the channel: %s\n", u->getName().c_str(), c.c_str());
}

/**
 * Removes a user from a channel
 * @param User* u
 * @param string& c
 * @return void
 */
void ChatServer::removeUserFromChannel(User* u, string& c)
{
    this->userChannels[u].erase(c);

    this->channelUsers[c].erase(u);

    printf("-----------------------------------------\n");

    printf("User: %s has left the channel: %s\n", u->getName().c_str(), c.c_str());
}

/**
 * Sends the channel the text message
 * @param User* u
 * @param string& channel
 * @param string& text
 * @return void
 */
void ChatServer::sendMessage(User* u, string& channel, string& text)
{
    if (!this->userInChannel(u, channel)) return;

    string name = u->getName();

    Message* m = new Message(text, name, channel);

    unordered_set<User*> users = this->channelUsers[channel];

    printf("-----------------------------------------\n");

    printf("This message has been received by %lu in the channel\n", users.size());

    for (User* u : users)
    {
        u->receiveMessage(m);
    }
}

int main()
{
    ChatServer* cs = new ChatServer();

    string n1 = "mayank"; string n2 = "amencherla"; string room = "dota";

    User* u1 = new User(n1, cs, 10);

    User* u2 = new User(n2, cs, 10);

    u2->joinChannel(room);

    cs->printAllUsers();

    string message = "I'm super excited to be joining the dota chat room!!";

    u1->message(room, message);

    u1->leaveChannel(room);

    string message2 = "Testing to see who is out there....";

    u2->message(room, message2);
}
