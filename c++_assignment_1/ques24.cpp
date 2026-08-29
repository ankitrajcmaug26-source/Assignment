#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size,int** outMin, int** outMax) {
    // If size is invalid, don't modify output pointers
    if (size <= 0) {
        return false;
    }
    // Initially point to the first element
    *outMin = const_cast<int*>(rawData);
    *outMax = const_cast<int*>(rawData);
    // Find minimum and maximum
    for (int i = 1; i < size; i++) {
        if (*(rawData + i) < **outMin) {
            *outMin = const_cast<int*>(rawData + i);
        }
        if (*(rawData + i) > **outMax) {
            *outMax = const_cast<int*>(rawData + i);
        }
    }
    return true;
}

int main() {
    int packet[] = {45, 12, 67, 8, 55, 31};
    int* minPtr = nullptr;
    int* maxPtr = nullptr;
    if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }
    return 0;
}