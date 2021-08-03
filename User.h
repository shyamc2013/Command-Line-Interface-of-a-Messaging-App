#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class user{
    public:
    string User_id , Name;
    int Age;

    private:
    string Password;
    unordered_map<string , string> chats;

    user(string name , string user_id , string password , int age){
        this->Name = name;
        this->User_id = user_id;
        this->Password = password;
        this->Age = age;
    }
    friend class App;
};


#endif // USER_H_INCLUDED
