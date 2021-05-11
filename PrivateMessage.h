#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "UniversalObjectOutput.h"
#include "Comment.h"

using std::string;

//
//	This class holds information about private message and can return multiple info
//
class PrivateMessage : public UniversalObjectOutput
{
protected:
	string content;														// contains content of the message
	string date;														// date of creation
	string time;														// time of creation
	User authorFrom;													// holds user info of the sender
	User authorTo;														// holds user info of the reciever
	int authorFromID;													// contains ID of the sender
	int authorToID;														// contains ID of the reciever
	int messageID;														// contains unique ID of the message
public:
	PrivateMessage();													// basic empty constructor
	PrivateMessage(User& user, User& user2, string name);				// constructs message with given details
	string ReturnAsString();											// returns basic info of the class
	string ReturnContent();												// returns content of the message
	string ReturnDateTime();											// returns time and date when message was sent
	int GetAuthorFromID();												// returns ID of the sender
	int GetAuthorToID();												// returns ID of the reciever
	int GetMessageID();													// returns ID of the message
};