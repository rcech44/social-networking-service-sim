#include "Group.h"
#include "Generators.h"

Group::Group()
{
}

Group::Group(User& user, string name, string caption)
{
	this->name = name;
	this->caption = caption;
	std::vector<int> users;
	this->users = users;
	this->users.push_back(user.GetID());
	this->groupID = NumberGenerator(0, INT32_MAX);
	this->authorID = user.GetID();
}

Group::Group(User& user)
{
	this->name = TextGenerator("groupnames.txt");
	this->caption = "debug caption";
	std::vector<int> users;
	this->users = users;
	this->users.push_back(user.GetID());
	this->groupID = NumberGenerator(0, INT32_MAX);
	this->authorID = user.GetID();
}

string Group::GetName()
{
	return this->name;
}

std::vector<int> Group::GetUsers()
{
	return this->users;
}

string Group::GetCaption()
{
	return this->caption;
}

int Group::GetID()
{
	return this->groupID;
}

int Group::GetAuthorID()
{
	return this->authorID;
}

void Group::AddUser(User& user)
{
	this->users.push_back(user.GetID());
}
