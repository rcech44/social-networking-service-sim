#include "User.h"
#include "Generators.h"
#include "PrivateMessage.h"
#include "Person.h"
#include "User.h"
#include <limits>
#include <vector>

User::User() : Person()
{
	this->numberOfPosts = 0;
	std::vector<int> friends;
	this->following_users = friends;
}

User::User(string name, string address, Date date) : Person(name, address, date)
{
	this->numberOfPosts = 0;
	std::vector<int> friends;
	this->following_users = friends;
}

bool User::FollowUser(User user)
{
	//printf("Adding friend id: %d\n", user.GetID());
	//int id = user.GetID();
	for (int val : this->following_users)
	{
		if (val == user.GetID()) return false;
	}

	this->following_users.push_back(user.GetID());
	return true;
}

bool User::AddFriend(User& user)
{
	for (int val : this->friends)
	{
		if (val == user.GetID()) return false;
	}
	
	this->friends.push_back(user.GetID());
	user.GetFriends().push_back(this->personID);
	return true;
}

void User::SendMessageW(User& user, int message_id)
{
	std::pair<int, int> pair = std::make_pair(user.GetID(), message_id);
	this->sentMessages.push_back(pair);
	user.RecieveMessage(pair);
}

void User::RecieveMessage(std::pair<int,int> pair)
{
	this->recievedMessages.push_back(pair);
}

std::vector<int>& User::GetFollowUsers()
{
	return this->following_users;
}

std::vector<int>& User::GetFriends()
{
	return this->friends;
}

std::vector<int>& User::GetComments()
{
	return this->comments;
}

std::vector<int>& User::GetGroups()
{
	return this->groups;
}

std::vector<std::pair<int, int>>& User::GetRecievedMessages()
{
	return this->recievedMessages;
}

std::vector<std::pair<int, int>>& User::GetSentMessages()
{
	return this->sentMessages;
}

int User::GetNumberOfFollowingUsers()
{
	return this->following_users.size();
}

int User::GetNumberOfFriends()
{
	return this->friends.size();
}

void User::ChangeName(string name)
{
	this->name = name;
}
