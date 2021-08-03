#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

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
            cout<<"Unable to send your message. There is no such user with the name "<<receiver<<endl<<endl;
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

    void end_session(){
        unordered_map<string,user*>::iterator it = members.begin();
        while(it != members.end()){
            delete it->second;
            it++;
        }
        cout<<"The session has ended. All the accounts and their data has been deleted."<<endl;
    }
};


#endif // APP_H_INCLUDED
