#include <iostream>

using namespace std;

class GymMember
{
public:
    void checkMembership()
    {
        char response;
        do
        {
            cout << "do you have a memebership? (y/n): ";
            cin >> response;
        } while (response != 'y' && response != 'n');
        if (response == 'y')
        {
            cout << "welcome back, member!" << endl;
        }
        else
        {
            cout << "please sign up for a membership." << endl;
        }
    }
};


class SingUp {
    public:
    void registerUser() {
        string username;
        do {
            cout << " enter a username (at least 5 characters): ";
            cin >> username;
        } while (username.length() < 5);
        cout << "username " << username << " registered successfully!" << endl;
    }
};

int main() {
    GymMember member;
    member.checkMembership();
    

    SingUp signup;
    signup.registerUser();  

    system("pause");

}