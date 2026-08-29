#include <iostream>
#include <cmath>
using namespace std;
// Calculate distance between two points
inline double distanceBetween(double x1, double y1,double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
// Convert degrees to radians
inline double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}
// Restrict value to [minVal, maxVal]
inline double clamp(double value, double minVal, double maxVal) {
    if (value < minVal) {
        return minVal;
    }
    if (value > maxVal) {
        return maxVal;
    }
    return value;
}
// Check whether point is inside circle
inline bool isInSafeZone(double x, double y,double cx, double cy,double radius) {
    double distance = distanceBetween(x, y, cx, cy);
    return distance <= radius;
}
int main() {
    // Home position
    double homeX = 0.0;
    double homeY = 0.0;
    // Safe zone radius
    double radius = 50.0;
    // Three waypoints
    double x1 = 10.0;
    double y1 = 20.0;
    double x2 = 30.0;
    double y2 = 40.0;
    double x3 = 60.0;
    double y3 = 10.0;
    // Waypoint 1
    double d1 = distanceBetween(homeX, homeY, x1, y1);
    cout << "Waypoint 1: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Distance from home: " << d1 << endl;
    if (isInSafeZone(x1, y1, homeX, homeY, radius)) {
        cout << "Inside safe zone: Yes" << endl;
    }
    else {
        cout << "Inside safe zone: No" << endl;
    }
    cout << endl;
    // Waypoint 2
    double d2 = distanceBetween(homeX, homeY, x2, y2);
    cout << "Waypoint 2: (" << x2 << ", " << y2 << ")" << endl;
    cout << "Distance from home: " << d2 << endl;
    if (isInSafeZone(x2, y2, homeX, homeY, radius)) {
        cout << "Inside safe zone: Yes" << endl;
    }
    else {
        cout << "Inside safe zone: No" << endl;
    }
    cout << endl;
    // Waypoint 3
    double d3 = distanceBetween(homeX, homeY, x3, y3);
    cout << "Waypoint 3: (" << x3 << ", " << y3 << ")" << endl;
    cout << "Distance from home: " << d3 << endl;
    if (isInSafeZone(x3, y3, homeX, homeY, radius)) {
        cout << "Inside safe zone: Yes" << endl;
    }
    else {
        cout << "Inside safe zone: No" << endl;
    }
    return 0;
}