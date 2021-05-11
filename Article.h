#pragma once
#include <string>
#include "Post.h"
#include "User.h"
#include "Comment.h"

using std::string;

//
//	This class holds information about articles.
//
class Article : public Post
{
protected:
	string content;											// contains content of article (text)
public:
	Article(User& user, string name, string content);		// constructs object with given details
	string ReturnAsString();								// returns basic info of object as string
	string GetName();										// returns name of the article
	int GetNumberOfComments();								// returns number of comments made on this article
};

