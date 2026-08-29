#include <iostream>
using namespace std;

int main() {
    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg   = 0b11001010;
// regPtr1 : Pointer to const int
    const int* regPtr1 = &statusReg;
    // Reading is allowed
    cout << "Status Register: " << *regPtr1 << endl;
    regPtr1 = &dataReg;
    cout << "regPtr1 after repointing: " << *regPtr1 << endl;
    // regPtr2 : Const pointer to int
    int* const regPtr2 = &controlReg;
    // Writing is allowed
    *regPtr2 = 25;
    cout << "Control Register: " << *regPtr2 << endl;
    // regPtr3 : Const pointer to const int
    const int* const regPtr3 = &statusReg;
    // Reading is allowed
    cout << "Status Register through regPtr3: "<< *regPtr3 << endl;
    return 0;
}