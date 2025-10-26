#include <iostream>
#include <string>

using namespace std;

class Operator {
    private:
        int a = -1;
        int b = 2;

    public:
        void goodOperation() {
            if ((a > 5 ) || (b == 2)) {
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
