#include "SNS.h"
#include "Generators.h"
#include "Colours.h"
#include "Article.h"
#include "Comment.h"
#include "User.h"
#include <iostream>
#include <windows.h>

using std::string;
using std::cout;
using std::endl;
SNS::SNS()			// random generated
{
	this->name = "Fakebook";
	this->website = "www.fakebook.com";
	this->date_of_creation = Date();
}

SNS::SNS(string name, string web, Date date)
{
	this->name = name;
	this->website = web;
	this->date_of_creation = date;
}

SNS::~SNS()
{
	this->users.~vector();
	this->groups.~vector();
	this->articles.~vector();
	this->comments.~vector();
	this->messages.~vector();
}

void SNS::AddUser()
{
	User newUser = User();
	this->users.push_back(newUser);
}

void SNS::AddArticle()
{
	Article newArticle = Article(this->GetUser_Random(), TextGenerator("articles.txt"), TextGenerator("contents.txt"));
	this->articles.push_back(newArticle);
}

void SNS::AddArticle(User& user)
{
	Article newArticle = Article(user, TextGenerator("articles.txt"), TextGenerator("contents.txt"));
	this->articles.push_back(newArticle);
}

void SNS::AddComment(User& user)
{
	if (this->GetNumberOfArticles() == 0) return;
	Comment newComment = Comment(user, TextGenerator("contents.txt"));
	this->comments.push_back(newComment);
	user.GetComments().push_back(newComment.GetID());
	//this->GetArticle_Random().AddComment(newComment);
}

void SNS::AddComment(User& user, string content)
{
	if (this->GetNumberOfArticles() == 0) return;
	Comment newComment = Comment(user, content);
	this->comments.push_back(newComment);
	user.GetComments().push_back(newComment.GetID());
	this->GetArticle_Random().AddComment(newComment);
}

void SNS::AddGroup(User& user)
{
	Group newGroup = Group(user, TextGenerator("groupnames.txt"), TextGenerator("contents.txt"));
	this->groups.push_back(newGroup);
	user.GetGroups().push_back(newGroup.GetID());
}

void SNS::AddGroup(User& user, string name, string caption)
{
	Group newGroup = Group(user, name, caption);
	this->groups.push_back(newGroup);
	user.GetGroups().push_back(newGroup.GetID());
}

bool SNS::AddUserToGroup(User& user, Group& group)
{
	for (unsigned int i = 0; i < group.GetUsers().size(); i++)
	{
		if (group.GetUsers().at(i) == user.GetID()) return false;
	}
	group.AddUser(user);
	user.GetGroups().push_back(group.GetID());
	return true;
}

void SNS::AddMessage(User& from, User& to, string content)
{
	PrivateMessage newMessage = PrivateMessage(from, to, content);
	this->messages.push_back(newMessage);
	from.SendMessageW(to, newMessage.GetMessageID());
}

string SNS::GetDateOfCreation()
{
	return this->date_of_creation.ReturnAsString();
}

string SNS::GetName()
{
	return this->name;
}

string SNS::GetWebsite()
{
	return this->website;
}

User& SNS::GetUser_Index(int index)
{
	if (this->users.size() < (unsigned int)index)
	{
		printf("There was an error with searching user by index - not found\n");
		printf("Size: %d, index: %d\n", this->users.size(), index);
		exit(-1);
	}
	//std::cout << "Returning " << this->users.at(index).GetName() << std::endl;
	return this->users.at(index);
}

User& SNS::GetUser_ID(int ID)
{
	for (unsigned int i = 0; i < this->users.size(); i++)
	{
		if (this->users.at(i).GetID() == ID) return this->users.at(i);
	}
	
	//for (User user : this->users)
	//{
	//	if (user.GetID() == ID) return user;
	//}
	printf("There was an error with searching user by ID - not found\n");
	printf("Size: %d, ID: %d\n", this->users.size(), ID);
	exit(-1);
	User returnNothing = User();
	return returnNothing;
}

User& SNS::GetUser_Random()
{
	return this->GetUser_Index(NumberGenerator(0, this->GetNumberOfUsers() - 1));
}

Comment& SNS::GetComment_Index(int index)
{
	if (this->GetNumberOfComments() < index)
	{
		printf("There was an error with searching comment by index - not found\n");
		printf("Size: %d, index: %d\n", this->users.size(), index);
		exit(-1);
	}

	return this->comments.at(index);
}

Comment& SNS::GetComment_Random()
{
	return this->GetComment_Index(NumberGenerator(0, this->GetNumberOfComments() - 1));
}

Article& SNS::GetArticle_Index(int index)
{
	if (this->GetNumberOfArticles() < index)
	{
		printf("There was an error with searching article by index - not found\n");
		printf("Size: %d, index: %d\n", this->articles.size(), index);
		exit(-1);
	}

	return this->articles.at(index);
}

Article& SNS::GetArticle_Random()
{
	return this->GetArticle_Index(NumberGenerator(0, this->GetNumberOfArticles() - 1));
}

int SNS::GetNumberOfUsers()
{
	return this->users.size();
}

int SNS::GetNumberOfArticles()
{
	return this->articles.size();
}

int SNS::GetNumberOfComments()
{
	return this->comments.size();
}

int SNS::GetNumberOfGroups()
{
	return this->groups.size();
}

int SNS::GetNumberOfMessages()
{
	return this->messages.size();
}

Group& SNS::GetGroup_Index(int index)
{
	if (this->GetNumberOfGroups() < index)
	{
		printf("There was an error with searching group by index - not found\n");
		printf("Size: %d, index: %d\n", this->GetNumberOfGroups(), index);
		exit(-1);
	}
	//std::cout << "Returning " << this->users.at(index).GetName() << std::endl;
	return this->groups.at(index);
}

Group& SNS::GetGroup_ID(int ID)
{
	for (int i = 0; i < this->GetNumberOfGroups(); i++)
	{
		if (this->groups.at(i).GetID() == ID) return this->groups.at(i);
	}

	//for (User user : this->users)
	//{
	//	if (user.GetID() == ID) return user;
	//}
	printf("There was an error with searching group by ID - not found\n");
	printf("Size: %d, ID: %d\n", this->GetNumberOfGroups(), ID);
	exit(-1);
	Group returnNothing = Group();
	return returnNothing;
}

Group& SNS::GetGroup_Random()
{
	return this->GetGroup_Index(NumberGenerator(0, this->GetNumberOfComments() - 1));
}

Group& SNS::GetGroup_Last()
{
	return this->groups.at(this->GetNumberOfGroups() - 1);
}

PrivateMessage& SNS::GetMessage_ID(int ID)
{
	for (int i = 0; i < this->GetNumberOfMessages(); i++)
	{
		if (this->messages.at(i).GetMessageID() == ID) return this->messages.at(i);
	}

	//for (User user : this->users)
	//{
	//	if (user.GetID() == ID) return user;
	//}
	printf("There was an error with searching message by ID - not found\n");
	printf("Size: %d, ID: %d\n", this->GetNumberOfMessages(), ID);
	exit(-1);
	PrivateMessage returnNothing = PrivateMessage();
	return returnNothing;
}

PrivateMessage& SNS::GetMessage_Index(int index)
{
	if (this->GetNumberOfMessages() < index)
	{
		printf("There was an error with searching message by index - not found\n");
		printf("Size: %d, index: %d\n", this->GetNumberOfMessages(), index);
		exit(-1);
	}
	//std::cout << "Returning " << this->users.at(index).GetName() << std::endl;
	return this->messages.at(index);
}

PrivateMessage& SNS::GetLastMessage()
{
	return this->messages.at(this->GetNumberOfMessages() - 1);
}

std::vector<User>& SNS::GetUsers()
{
	return this->users;
}

std::vector<Group>& SNS::GetGroups()
{
	return this->groups;
}

std::vector<Article>& SNS::GetArticles()
{
	return this->articles;
}

std::vector<Comment>& SNS::GetComments()
{
	return this->comments;
}

std::vector<PrivateMessage>& SNS::GetMessages()
{
	return this->messages;
}

Article& SNS::GetLastArticle()
{
	return this->articles.at(this->GetNumberOfArticles() - 1);
}

Comment& SNS::GetLastComment()
{
	return this->comments.at(this->GetNumberOfComments() - 1);
}

void SNS::Simulation(bool time_travel)
{
	int sleepSeconds;
	int option;
	int numberOfOperations = 0;
	int numberOfOptions = 9;
	std::vector<int> stats;
	for (int i = 0; i < numberOfOptions; i++)
	{
		stats.push_back(0);
	}

	while (numberOfOperations < 200)
	{
		
		// 1. add new user
		// 2. rename random user
		// 3. random adding friends
		// 4. random following users
		// 5. random article creation
		// 6. random commenting on articles
		// 7. random group creation
		// 8. random user joins random group
		// 9. random sending private messages from one user to another

		sleepSeconds = NumberGenerator(1, 3);
		option = NumberGenerator(1, numberOfOptions);
		if (time_travel == false) Sleep(sleepSeconds * 1000);

		// temporary variables to use in 'switch'
		string newName;
		int newUserIndex;
		int newUserIndex2;
		int newGroupIndex;
		int addFriendIndex;
		int addFriendIndex2;
		int randomPostIndex;
		// end of temporary variables

		switch (option)
		{
			case 1:		// add new user
				this->AddUser();
				cout << BRIGHT_BLUE << "New user joined:" << CRESET << endl;
				cout << "\t- name: " << BRIGHT_BLACK << this->GetUser_Index(this->GetNumberOfUsers() - 1).GetName() << CRESET << endl;
				cout << "\t- ID: " << this->GetUser_Index(this->GetNumberOfUsers() - 1).GetID() << endl;
				stats.at(0)++;
				break;
			case 2:		// rename random user
				newName = TextGenerator("names.txt");
				newUserIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				cout << BRIGHT_BLUE << "User renamed:" << CRESET << endl;
				cout << "\t- old name: " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex).GetName() << CRESET << endl;
				this->GetUser_Index(newUserIndex).ChangeName(newName);
				cout << "\t- new name: " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex).GetName() << CRESET << endl;
				stats.at(1)++;
				break;
			case 3:		// random adding friends
				addFriendIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				addFriendIndex2 = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				while (addFriendIndex == addFriendIndex2)
				{
					addFriendIndex2 = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				}
				if (this->GetUser_Index(addFriendIndex).AddFriend(this->GetUser_Index(addFriendIndex2)))
				{
					cout << BRIGHT_BLUE << "New friend query: " << CRESET << endl;
					cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex).GetName() << CRESET << " added " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex2).GetName() << CRESET << " as friend" << endl;
				}
				else
				{
					cout << BRIGHT_BLUE << "New friend query: " << CRESET << endl;
					cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex).GetName() << CRESET << " tried to add " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex2).GetName() << CRESET << " as friend, but unsuccessfully (already are friends)" << endl;
				}
				stats.at(2)++;
				break;
			case 4:		// random following users
				addFriendIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				addFriendIndex2 = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				while (addFriendIndex == addFriendIndex2)
				{
					addFriendIndex2 = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				}
				if (this->GetUser_Index(addFriendIndex).FollowUser(this->GetUser_Index(addFriendIndex2)))
				{
					cout << BRIGHT_BLUE << "New follow query: " << CRESET << endl;
					cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex).GetName() << CRESET << " started following " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex2).GetName() << CRESET << endl;
				}
				else
				{
					cout << BRIGHT_BLUE << "New follow query: " << CRESET << endl;
					cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex).GetName() << CRESET << " tried to follow " << BRIGHT_BLACK << this->GetUser_Index(addFriendIndex2).GetName() << CRESET << ", but unsuccessfully (already is following)" << endl;
				}
				stats.at(3)++;
				break;
			case 5:		// random article creation
				newUserIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				this->AddArticle(this->GetUser_Index(newUserIndex));
				cout << BRIGHT_BLUE << "New article shared: " << CRESET << endl;
				cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex).GetName() << CRESET << " shared new article with name '" << BRIGHT_MAGENTA << this->GetLastArticle().GetName() << CRESET << "'" << endl;
				stats.at(4)++;
				break;
			case 6:		// random commenting on articles
				newUserIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				randomPostIndex = NumberGenerator(0, this->GetNumberOfArticles() - 1);
				this->AddComment(this->GetUser_Index(newUserIndex));
				this->GetArticle_Index(randomPostIndex).AddComment(this->GetLastComment());
				cout << BRIGHT_BLUE << "New comment shared: " << CRESET << endl;
				cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex).GetName() << CRESET << " shared new comment" << endl;
				cout << "\t- Comment was put on post by " << BRIGHT_BLACK << this->GetUser_ID(this->GetArticle_Index(randomPostIndex).GetAuthorID()).GetName() << CRESET << " called '" << BRIGHT_MAGENTA << this->GetArticle_Index(randomPostIndex).GetName() << CRESET << "'" << endl;
				cout << "\t- Currently this post has " << this->GetArticle_Index(randomPostIndex).GetNumberOfComments() << " comments" << endl;
				stats.at(5)++;
				break;
			case 7:		// random group creation
				newUserIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				this->AddGroup(this->GetUser_Index(newUserIndex));
				cout << BRIGHT_BLUE << "New group was created: " << CRESET << endl;
				cout << "\t- " << BRIGHT_BLACK << this->GetUser_ID(this->GetGroup_Last().GetAuthorID()).GetName() << CRESET << " created the group called '" << BRIGHT_MAGENTA << this->GetGroup_Last().GetName() << CRESET << "'" << endl;
				stats.at(6)++;
				break;
			case 8:		// random user joins random group
				newUserIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				if (this->GetNumberOfGroups() == 0) break;
				newGroupIndex = NumberGenerator(0, this->GetNumberOfGroups() - 1);
				cout << BRIGHT_BLUE << "User group join query: " << CRESET << endl;
				if (this->AddUserToGroup(this->GetUser_Index(newUserIndex), this->GetGroup_Index(newGroupIndex)))
				{
					cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex).GetName() << CRESET << " joined the group '" << BRIGHT_MAGENTA << this->GetGroup_Index(newGroupIndex).GetName() << CRESET << "'" << endl;
					stats.at(7)++;
				}
				else
				{
					cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex).GetName() << CRESET << " tried to join the group '" << BRIGHT_MAGENTA << this->GetGroup_Index(newGroupIndex).GetName() << CRESET << "', but unsuccessfully (already is member)" << endl;
				}
				break;
			case 9:		// random sending private messages from one user to another
				newUserIndex = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				newUserIndex2 = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				while (newUserIndex == newUserIndex2)
				{
					newUserIndex2 = NumberGenerator(0, this->GetNumberOfUsers() - 1);
				}
				this->AddMessage(this->GetUser_Index(newUserIndex), this->GetUser_Index(newUserIndex2), TextGenerator("messages.txt"));
				cout << BRIGHT_BLUE << "Private message sent (inter-user): " << CRESET << endl;
				cout << "\t- " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex).GetName() << CRESET << " sent message to " << BRIGHT_BLACK << this->GetUser_Index(newUserIndex2).GetName() << CRESET << endl;
				cout << "\t- contents of message: \"" << BRIGHT_GREEN << this->GetLastMessage().ReturnContent() << CRESET << "\"" << endl;
				cout << "\t- message sent at: " << this->GetLastMessage().ReturnDateTime() << endl;
				stats.at(8)++;
				break;
		}
		numberOfOperations++;
	}

	cout << endl << BRIGHT_BLUE << "=============================" << endl << endl;
	cout << BRIGHT_BLUE << "Simulation ended, statistics: " << CRESET << endl;
	cout << "\t- Number of new users: "		<< BRIGHT_BLACK << stats.at(0) << CRESET << endl;
	cout << "\t- Number of renamed users: " << BRIGHT_BLACK << stats.at(1) << CRESET << endl;
	cout << "\t- New friend connections: "	<< BRIGHT_BLACK << stats.at(2) << CRESET << endl;
	cout << "\t- New follow queries: "		<< BRIGHT_BLACK << stats.at(3) << CRESET << endl;
	cout << "\t- New articles created: "	<< BRIGHT_BLACK << stats.at(4) << CRESET << endl;
	cout << "\t- New comments shared: "		<< BRIGHT_BLACK << stats.at(5) << CRESET << endl;
	cout << "\t- New groups created: "		<< BRIGHT_BLACK << stats.at(6) << CRESET << endl;
	cout << "\t- Number of users joined in groups: " << BRIGHT_BLACK << stats.at(7) << CRESET << endl;
	cout << "\t- Sent messages: "			<< BRIGHT_BLACK << stats.at(8) << CRESET << endl;
	cout << endl << BRIGHT_BLUE << "=============================" << endl << CRESET << endl;

}