#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "UniversalObjectOutput.h"
#include "Comment.h"

using std::string;

//
//	This class holds information about posts. Is mainly used as parent class from which other classes inherit.
//
class Post : public UniversalObjectOutput
{
protected:
	string name;										// name of the post	
	string date;										// date of creation of the post
	string time;										// time of creation of the post
	User author;										// contains information about author (legacy, not widely used)
	int authorID;										// contains author ID
	int postID;											// unique ID of the post
	std::vector<int> comments;							// holds IDs of comments of the post
public:
	Post(User& user, string name);						// constructs Post with given details
	void AddComment(Comment comment);					// adds comment to the post, saves it to the vector that holds IDs of comments
	string ReturnAsString();							// returns basic info of the object
	int GetAuthorID();									// returns ID of the author
};