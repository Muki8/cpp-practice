#include <iostream>

using namespace std;

class Perro {
    public:
    virtual void ladrar() {
        cout << "wooff" << endl;

    }
};

class Pitbull : public Perro {
    public:
    void ladrar() override {
        cout << "WOOF WOOF" << endl;
    }
};

int main() {
Perro myPerro;
Pitbull myPitbull;
myPerro.ladrar();    // Outputs: wooff
myPitbull.ladrar();  // Outputs: WOOF WOOF


}