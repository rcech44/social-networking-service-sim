#include "PrivateMessage.h"
#include "Time.h"
#include "Generators.h"
#include <sstream>

PrivateMessage::PrivateMessage()
{
}

PrivateMessage::PrivateMessage(User& user, User& user2, string content)
{
	this->content = content;
	this->date = Date().ReturnAsString();
	this->time = Time().ReturnAsString();
	this->authorFromID = user.GetID();
	this->authorToID = user2.GetID();
	this->authorFrom = user;
	this->authorTo = user2;
	this->messageID = NumberGenerator(0, INT32_MAX);
}

string PrivateMessage::ReturnAsString()
{
	std::stringstream text;
	text << "Message sent from '" << this->authorFrom.GetName() << "' to '" << this->authorTo.GetName() << "' with content: '" << this->content << "' sent at " << this->ReturnDateTime();
	return text.str();
}

string PrivateMessage::ReturnContent()
{
	return this->content;
}

string PrivateMessage::ReturnDateTime()
{
	std::stringstream text;
	text << this->date << " at " << this->time;
	return text.str();
}

int PrivateMessage::GetAuthorFromID()
{
	return this->authorFromID;
}

int PrivateMessage::GetAuthorToID()
{
	return this->authorToID;
}

int PrivateMessage::GetMessageID()
{
	return this->messageID;
}
