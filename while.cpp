#include <iostream>

using namespace std;

class Calendary {
    public:
    void countMonths() {
        int month =1;
        while (month <= 12) {
            cout << "month: " << month << endl;
            month++;
        }
    }
};

class Age {
    public:
    void demostrateAge() {
        int age;
        do {
            cout << "please enter your age: ";
            cin >> age;
        } while (age < 0 || age > 120);
        cout << "your age is: " << age << endl;
    }
};


int main() {
    Calendary Calendary;
    Calendary.countMonths();
    

    Age age;
    age.demostrateAge();

    system("pause");
}