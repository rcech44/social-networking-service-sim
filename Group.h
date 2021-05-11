#pragma once
#include <string>
#include <vector>
#include "User.h"

using std::string;

//
//	This class holds information about groups and can return multiple info
//
class Group
{
protected:
	string name;												// contains name of the group
	std::vector<int> users;										// contains IDs of all joined users
	string caption;												// contains basic caption of the group
	int groupID;												// basic ID of current group
	int authorID;												// contains ID of author of the group
public:
	Group();													// basic constructor
	Group(User& user, string name, string caption);				// constructs user group with given details
	Group(User& user);											// constructs user group with random values and given user
	string GetName();											// returns name of the group
	std::vector<int> GetUsers();								// returns vector of IDs of all joined users
	string GetCaption();										// returns caption of the group
	int GetID();												// returns ID of the group
	int GetAuthorID();											// returns ID of the author
	void AddUser(User& user);									// adds user into the vector of the group
};