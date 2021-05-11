#pragma once
#include <string>
#include "User.h"
#include "UniversalObjectOutput.h"

using std::string;

//
//	This class holds information about comments and can return simple information about them.
//
class Comment : public UniversalObjectOutput
{
protected:
	string date;									// contains date of creation
	string time;									// contains time of creation
	int authorID;									// contains ID of author (user)
	int commentID;									// contains ID of current comment
	string content;									// content itself is stored here
public:
	Comment(User& user);							// constructs comment with random content
	Comment(User& user, string content);			// constructs comment with given details
	string ReturnAsString();						// returns basic info of object as string
	int GetID();									// returns ID of current comment
	int GetAuthorID();								// returns ID of author
};