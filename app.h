#ifndef APP1_H_INCLUDED
#define APP1_H_INCLUDED
#include <bits/stdc++.h>
#include "User.h"

using namespace std;

class App{
    unordered_map<string,user*> members;

    public:
    user* signup(string name , string user_id , string password , int age){
        user* temp = new user(name , user_id , password , age);
        members[user_id] = temp;
        return members[user_id];
    }

    user* login(string user_id , string password){
        if(members.count(user_id)<= 0){
            cout<<"There is no such user with the user_id "<<user_id;
            cout<<". Please signup to go ahead."<<endl<<endl;
            return NULL;
        }
        if(members[user_id]->Password != password){
            cout<<"Invalid password. Enter correct user_id and password."<<endl<<endl;
            return NULL;
        }
        return members[user_id];
    }

    void send_message(string sender , string receiver , string message){
        if(members.count(receiver)<= 0){
            cout<<"There is no such user with the name "<<receiver<<endl<<endl;
            return;
        }
        if(members[sender]->chats.count(receiver) <= 0){
            cout<<"You can only send messages to a friend. First try sending a friend request to "<<receiver<<endl<<endl;
            return;
        }
        transform(message.begin(), message.end(), message.begin() , ::toupper);
        members[sender]->chats[receiver] += message;

        transform(message.begin(), message.end(), message.begin() , ::tolower);
        members[receiver]->chats[sender] += message;

        cout<<"Your message has been delivered to "<<receiver<<endl<<endl;
    }

    void view_message(string self , string buddy){
        if(members[self]->chats.count(buddy) <= 0){
            cout<<"There is no conversation between you and "<<buddy<<endl<<endl;
            return;
        }
        cout<<endl;
        cout<<buddy<<endl;
        cout<<members[self]->chats[buddy];
    }

    void send_request(string self, string buddy){
        if(members.count(buddy)<= 0){
            cout<<"Unable to send your request. There is no such user with the name "<<buddy<<endl<<endl;
            return;
        }
        if(members[self]->chats.count(buddy)> 0){
            cout<<"You are already a friends of "<<buddy<<endl<<endl;
            return;
        }
        members[buddy]->friend_requests.push(self);
        cout<<"Request has been sent to "<<buddy<<endl<<endl;
    }
    void view_requests(string self){
        if(members[self]->friend_requests.empty()){
            cout<<"There are no friend requests at present."<<endl<<endl;
            return;
        }
        while(members[self]->friend_requests.size()){
            string buddy= members[self]->friend_requests.front();
            cout<<buddy<<" sent you a friend request."<<endl<<endl;
            int choice;
            cout<<"Press 1 to accept request."<<endl;
            cout<<"Press 2 to reject request."<<endl;
            cout<<"Press 3 to keep it for later acceptance."<<endl;
            cout<<"Press 4 to see the requests later."<<endl;
            cin>>choice;
            if(choice== 1){
                members[self]->friend_requests.pop();
                members[self]->chats[buddy]= "";
                members[buddy]->chats[self]= "";
            }
            else if(choice== 2){
                members[self]->friend_requests.pop();
            }
            else if(choice== 3){
                members[self]->friend_requests.pop();
                members[self]->friend_requests.push(buddy);
            }
            else{
                break;
            }
        }
    }

    void end_session(){
        unordered_map<string,user*>::iterator it = members.begin();
        while(it != members.end()){
            delete it->second;
            it++;
        }
        cout<<"The session has ended. All the accounts and their data has been deleted."<<endl;
    }
};


#endif // APP1_H_INCLUDED
