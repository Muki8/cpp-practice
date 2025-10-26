#include <iostream>
#include <string>

using namespace std;

class Operator {
    private:
        int a = 0;
        int b = 0;

    public:
        void goodOperation() {
            cout << "insert two numbers:";
            cin >> a >> b;
            if ((a > 5) && (b == 2)) {  // Cambiado || por &&
                cerr << "good operation" << endl;
            } else {
                cerr << "bad operation" << endl;
            }
        }
};

int main() {
    Operator op;
    op.goodOperation();
    system("pause");    
    return 0;
}
