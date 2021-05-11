#include "Comment.h"
#include "Generators.h"
#include "Date.h"
#include "Time.h"

Comment::Comment(User& user)
{
	this->date = Date().ReturnAsString();
	this->time = Time().ReturnAsString();
	this->authorID = user.GetID();
	this->commentID = NumberGenerator(0, INT32_MAX);
	this->content = TextGenerator("contents.txt");
}

Comment::Comment(User& user, string content)
{
	this->date = Date().ReturnAsString();
	this->time = Time().ReturnAsString();
	User newUser = User();
	this->authorID = user.GetID();
	this->commentID = NumberGenerator(0, INT32_MAX);
	this->content = content;
}

string Comment::ReturnAsString()
{
	std::stringstream text;
	text << "Comment added by user with ID " << this->authorID << " and was created on " << this->date << " at " << this->time;
	return text.str();
}

int Comment::GetID()
{
	return this->commentID;
}

int Comment::GetAuthorID()
{
	return this->authorID;
}
