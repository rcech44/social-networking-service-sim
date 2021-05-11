#pragma once
#include "Person.h"

//
//	This class holds infromation about user and can perform multiple actions related to user.
//
class User : public Person
{
private:
	int numberOfPosts;
	std::vector<int> following_users;							// vector that holds ID's of users that he/she follows
	std::vector<int> friends;									// vector that holds ID's of frineds
	std::vector<int> articles;									// vector that holds ID's of user's articles
	std::vector<int> comments;									// vector that holds ID's of user's comments on posts
	std::vector<int> groups;									// vector that holds ID's of user's groups he/she joined
	std::vector<std::pair<int, int>> sentMessages;				// vector that holds pair of user's ID and message ID
	std::vector<std::pair<int, int>> recievedMessages;			// vector that holds pair of user's ID and message ID
	
public:
	User();														// basic constructor that automatically constructs object of default values
	User(string name, string address, Date date);				// constructs object with given details
	bool FollowUser(User user);									// make user follow other user, saves reference into vector 'following_users'
	bool AddFriend(User& user);									// be friend with other user, saves reference into vector 'friends'
	void SendMessageW(User& user, int message_id);				// bug in IDE, method has to be named 'SendMessageW' instead of 'SendMessage', sends message to other user
	void RecieveMessage(std::pair<int, int> pair);				// when user sends message, other user calls this method to save the message into vector 'recievedMessages'
	std::vector<int>& GetFollowUsers();							// returns vector of IDs of following users
	std::vector<int>& GetFriends();								// returns vector of IDs of user's friends
	std::vector<int>& GetComments();							// returns vector of IDs of comments this user made
	std::vector<int>& GetGroups();								// returns vector of IDs of all groups this user has joined
	std::vector<std::pair<int, int>>& GetRecievedMessages();	// returns vector of IDS of recieved messages (user and message IDs)
	std::vector<std::pair<int, int>>& GetSentMessages();		// returns vector of IDS of sent messages (user and message IDs)
	int GetNumberOfFollowingUsers();							// returns number of following users
	int GetNumberOfFriends();									// returns number of friends
	void ChangeName(string name);								// method to change name of user
};