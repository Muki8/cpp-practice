#include <iostream>

using namespace std;

class Person {
    public:
    void demonstrateLoops() {
    for (int i = 0; i < 10; i++) {
        cout << "Iteration: " << i << endl;
    }   

    // avoid an infinite loop for demonstration
    int count = 0;
    while (count < 1) {
        cout << " this will run once" << endl;
        ++count;
    }

    do {
        cout << " this will run at least once" << endl;
    } while (false);
}
};

int main() {
    Person person;
    person.demonstrateLoops();
    system("pause");
    return 0;   
}