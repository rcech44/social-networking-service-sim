#include "Post.h"
#include "Time.h"
#include "Generators.h"
#include <sstream>

Post::Post(User& user, string name)
{
	this->name = name;
	this->date = Date().ReturnAsString();
	this->time = Time().ReturnAsString();
	this->author = user;
	this->authorID = user.GetID();
	this->postID = NumberGenerator(0, INT32_MAX);
	std::vector<int> comments;
	this->comments = comments;
}

void Post::AddComment(Comment comment)
{
	this->comments.push_back(comment.GetID());
}

string Post::ReturnAsString()
{
	std::stringstream text;
	text << "Post name is '" << this->name << "', owner's ID is " << this->authorID << " and was created on " << this->date << " at " << this->time;
	return text.str();
}

int Post::GetAuthorID()
{
	return this->authorID;
}
