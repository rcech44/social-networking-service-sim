#include "Post.h"
#include "Time.h"
#include "Article.h"
#include "Colours.h"
#include <sstream>

Article::Article(User& user, string name, string content) : Post(user, name)
{
	this->content = content;
}

string Article::ReturnAsString()
{
	std::stringstream text;
	text << "Article info:";
	text << "\n\tName is '" << BRIGHT_MAGENTA << this->name << CRESET << "'";
	text << "\n\tOwner is " << this->author.GetName();
	text << "\n\tCreated on " << this->date << " at " << this->time;
	text << "\n\tContent is: " << this->content;
	text << "\n\tPost ID is: " << this->postID;
	text << "\n\tNumber of comments: " << this->GetNumberOfComments();
	return text.str();
}

string Article::GetName()
{
	return this->name;
}

int Article::GetNumberOfComments()
{
	return this->comments.size();
}
