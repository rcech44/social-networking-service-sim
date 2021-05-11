#pragma once
#include "Date.h"
#include "User.h"
#include "Article.h"
#include "Comment.h"
#include "Group.h"
#include "UniversalObjectOutput.h"
#include "PrivateMessage.h"

//
//	This class serves as main class of the program. Holds information about everything related to SNS.
//
class SNS			// aka Social networking service
{
private:
	string name;													// name of social networking service (not neccesarry, not widely used)
	string website;													// website of social networking service (not neccesarry, not widely used)
	Date date_of_creation;											// date of creation of SNS (not neccesarry, not widely used)
	std::vector<User> users;										// vector that holds all users
	std::vector<Group> groups;										// vector that holds all groups of users
	std::vector<Article> articles;									// vector that holds all articles with its contents
	std::vector<Comment> comments;									// vector that holds all shared comments
	std::vector<PrivateMessage> messages;							// vector that holds all messages sent among users
public:
	// constructors
	SNS();															// basic constructor with default info
	SNS(string name, string web, Date date);						// constructor that constructs SNS with given info
	// destructor
	~SNS();
	// adders
	void AddUser();													// adds user on SNS
	void AddArticle();												// adds article on SNS with random values
	void AddArticle(User& user);									// adds article on SNS with given owner
	void AddComment(User& user);									// adds comment on SNS with given owner
	void AddComment(User& user, string content);					// adds comment to random post on SNS with given owner and content
	void AddGroup(User& user);										// adds group on SNS with given owner and owner gets reference
	void AddGroup(User& user, string name, string caption);			// adds group on SNS with given details and owner gets reference
	bool AddUserToGroup(User& user, Group& group);					// adds user into group and user gets reference
	void AddMessage(User& from, User& to, string content);			// adds private message on SNS with given details and sender gets reference
	// getters
	string GetDateOfCreation();										// returns date of creation of SNS
	string GetName();												// returns name of SNS
	string GetWebsite();											// returns website of SNS
	User& GetUser_Index(int index);									// returns user of SNS by index in vector
	User& GetUser_ID(int ID);										// returns user of SNS by unique ID (if exists)
	User& GetUser_Random();											// returns random user of SNS
	Comment& GetComment_Index(int index);							// returns comment of SNS by index in vector
	Comment& GetComment_Random();									// returns random comment of SNS
	Comment& GetLastComment();										// returns last shared comment on SNS
	Article& GetArticle_Index(int index);							// returns article of SNS by index in vector
	Article& GetArticle_Random();									// returns random article of SNS
	Article& GetLastArticle();										// returns last article of SNS
	Group& GetGroup_Index(int index);								// returns user group of SNS by index in vector
	Group& GetGroup_ID(int ID);										// returns user group of SNS by unique ID
	Group& GetGroup_Random();										// returns random user group of SNS
	Group& GetGroup_Last();											// returns last created user group of SNS
	PrivateMessage& GetMessage_ID(int ID);							// returns private message sent on SNS with unique ID
	PrivateMessage& GetMessage_Index(int index);					// returns private message sent on SNS of index in vector
	PrivateMessage& GetLastMessage();								// returns last sent private message on SNS
	std::vector<User>& GetUsers();									// returns address of vector of all users
	std::vector<Group>& GetGroups();								// returns address of vector of all user groups
	std::vector<Article>& GetArticles();							// returns address of vector of all articles
	std::vector<Comment>& GetComments();							// returns address of vector of all comments
	std::vector<PrivateMessage>& GetMessages();						// returns address of vector of all private messages
	int GetNumberOfUsers();											// returns number of all users in SNS
	int GetNumberOfArticles();										// returns number of all articles in SNS
	int GetNumberOfComments();										// returns number of all comments in SNS
	int GetNumberOfGroups();										// returns number of all user groups in SNS
	int GetNumberOfMessages();										// returns number of all private messages in SNS
	// other methods
	void Simulation(bool time_travel);								// starts SNS simulation
};