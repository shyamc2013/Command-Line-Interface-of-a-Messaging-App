#include <bits/stdc++.h>
#include "app.h"

using namespace std;

int main(){
    App whatsapp;
    cout<<"Made by SHYAM"<<endl;
    cout<<"Sent messages will appear in capital"<<endl;
    cout<<"Received messages will appear in small"<<endl;
    cout<<"Enter your first name as user_id (without any spaces)"<<endl<<endl;
    while(true){
        cout<<"Press 1 for signup."<<endl;
        cout<<"Press 2 for login."<<endl;
        cout<<"Press 0 to end the session. All the data will be deleted."<<endl;
        cout<<"--------------------------"<<endl;
        int option;
        cin>>option;

        if(option == 1){
            string user_id , password , name;
            int age;
            cout<<"Enter your name. Case of the letters does not matter."<<endl;
            cin.clear();
            cin.sync();
            if (!getline(cin, name))  exit;
            cout<<"Enter user_id. Case of the letters does not matter."<<endl;
            cin>>user_id;
            cout<<"Enter password. It is case sensitive."<<endl;
            cin>>password;
            cout<<"Enter your age."<<endl;
            cin>>age;
            if(age < 18 ){
                cout<<"You are underage to use this app . Your age should be 18 or above."<<endl<<endl;
                continue;
            }
            transform(user_id.begin(), user_id.end(), user_id.begin() , ::toupper);
            transform(name.begin() , name.end() , name.begin() , ::toupper);
            user* temp = whatsapp.signup(name , user_id , password , age);
            cout<<"Your account has been created."<<endl;
            cout<<"Your name is "<<temp->Name<<endl;
            cout<<"Your user_id is "<<temp->User_id<<endl;
            cout<<"Your age is "<<temp->Age<<endl;
            cout<<endl;
        }

        else if(option == 2){
            user* temp = NULL;
            string user_id;
            cout<<"Enter user_id. Case of the letters does not matter."<<endl;
            cin>>user_id;
            transform(user_id.begin(), user_id.end(), user_id.begin() , ::toupper);
            string password;
            cout<<"Enter password. It is case sensitive."<<endl;
            cin>>password;
            temp = whatsapp.login(user_id, password);
            if(!temp){
                continue;
            }
            cout<<"You are logged into your account."<<endl;
            cout<<endl;
            while(true){
                cout<<"Press 1 to view message."<<endl;
                cout<<"Press 2 to send message."<<endl;
                cout<<"Press 3 to send friend request."<<endl;
                cout<<"Press 4 to view received friend requests."<<endl;
                cout<<"Press 0 to logout."<<endl;
                cout<<"----------------------------"<<endl;
                int choice;
                cin>>choice;
                if(choice == 1){
                    string buddy;
                    cout<<"Enter the user_id of your buddy. Case of the letters does not matter."<<endl;
                    cin>>buddy;
                    transform(buddy.begin(), buddy.end(), buddy.begin() , ::toupper);
                    whatsapp.view_message(user_id , buddy);
                }
                else if(choice == 2){
                    string receiver;
                    cout<<"Enter the user_id of receiver. Case of the letters does not matter."<<endl;
                    cin>>receiver;
                    transform(receiver.begin(), receiver.end(), receiver.begin() , ::toupper);
                    cout<<"Enter your message. Case of the letters does not matter."<<endl;
                    string message;
                    cin.clear();
                    cin.sync();
                    if (!getline(cin, message))  exit;
                    message += "\n\n";
                    whatsapp.send_message(user_id , receiver , message);
                }
                else if(choice== 3){
                    string buddy;
                    cout<<"Enter the user_id of the user you want to send friend request to. Case of the letters does not matter."<<endl;
                    cin>>buddy;
                    transform(buddy.begin(), buddy.end(), buddy.begin(), ::toupper);
                    whatsapp.send_request(user_id, buddy);
                }
                else if(choice== 4){
                    whatsapp.view_requests(user_id);
                }
                else{
                    cout<<"You have been successfully logged out of your account."<<endl<<endl;
                    break;   //logout
                }
            }

        }
        else{
            whatsapp.end_session();
            break;
        }
    }
}
