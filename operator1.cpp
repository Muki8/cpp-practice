#include <iostream>

using namespace std;

int main() {
    int a, b; // declaring vars
    int result1, result2;
    cout << "insert the two numbers" << endl;
    cin >> a >> b;

    if ((a > 5) && (b == 2)) { // using logical AND operator depending on condition and values
        result1 = a + b;
        cout << "The sum is: " << result1 << endl;
    } else {
        result2 = a - b;
        cout << "The difference is: " << result2 << endl;
    }

    return 0;
    
}