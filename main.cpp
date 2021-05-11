//
// Prosim pred pouzitim si prectete soubor "readme.txt"
//

#include <iostream>
#include "SNS.h"
#include "Colours.h"
#include "Date.h"
#include "User.h"
#include "Time.h"
#include "Post.h"
#include "Article.h"
#include "Comment.h"
#include "PrivateMessage.h"

using std::cout;
using std::endl;

int main()
{
    cout << "Pred pouzitim si prosim prectete kratkou dokumentaci v souboru \"" << GREEN << "readme.txt" << CRESET << "\"." << endl << endl;
    
    SNS* network = new SNS();

    // start of main simulation
    network->AddUser();
    network->AddUser();
    network->AddUser();
    network->AddArticle();

    bool time_travel = true;        // if true, simulation will be speeded up
    network->Simulation(time_travel);
    // end of main simulation

    // CUSTOM INFORMATION PRINT after simulation
   
    // print first user info about friends and followers
    cout << endl << endl << "Printing custom information after simulation: " << endl << endl << network->GetUser_Index(0).GetName() << " (" << network->GetUser_Index(0).GetID() << ") follows " << network->GetUser_Index(0).GetNumberOfFollowingUsers() << " users and has " << network->GetUser_Index(0).GetNumberOfFriends() << " friends" << endl;
    for (int per : network->GetUser_Index(0).GetFollowUsers())
    {
        cout << "\t- follows " << network->GetUser_ID(per).GetName() << endl;
    }
    for (int per : network->GetUser_Index(0).GetFriends())
    {
        cout << "\t- is friend with " << network->GetUser_ID(per).GetName() << endl;
    }
    cout << endl;

    // print all published articles
    std::vector<Article> articles = network->GetArticles();
    for (Article art : articles)
    {
        cout << art.ReturnAsString() << endl;
    }

    // print random date and time
    Date date1 = Date();
    cout << endl << "Random date: " << date1.ReturnAsString() << endl;
    Time time1 = Time();
    cout << "Random time: " << time1.ReturnAsString() << endl;

    // create message and print messages from certain user and then all messages
    network->AddMessage(network->GetUser_Index(0), network->GetUser_Index(1), "content");
    cout << "FIRST MESSAGE: " << network->GetMessage_Index(0).ReturnAsString() << endl;

    cout << endl << "MESSAGES SENT FROM USER INDEX 0 -> " << network->GetUser_Index(0).GetName() << endl;
    for (std::pair<int,int> pair : network->GetUser_Index(0).GetSentMessages())
    {
        cout << "\t- sent message to " << network->GetUser_ID(network->GetMessage_ID(pair.second).GetAuthorToID()).GetName() << " with content: '"<< network->GetMessage_ID(pair.second).ReturnContent() << "' at " << network->GetMessage_ID(pair.second).ReturnDateTime() << endl;
    }

    cout << endl << "MESSAGES RECIEVED BY USER INDEX 1 -> " << network->GetUser_Index(1).GetName() << endl;
    for (std::pair<int, int> pair : network->GetUser_Index(1).GetRecievedMessages())
    {
        cout << "\t- recieved message from " << network->GetUser_ID(network->GetMessage_ID(pair.second).GetAuthorFromID()).GetName() << " with content: '" << network->GetMessage_ID(pair.second).ReturnContent() << "' at " << network->GetMessage_ID(pair.second).ReturnDateTime() << endl;
    }

    cout << endl;
    std::vector<PrivateMessage> messages = network->GetMessages();
    for (PrivateMessage mess : messages)
    {
        cout << mess.ReturnAsString() << endl;
    }

    // destructors
    articles.~vector();
    messages.~vector();
    delete network;

    return 0;
}
