#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

namespace Physics{
    double clamp(double val, double min, double max ){
        if(val < min) return min;
        if(val > max) return max;
        return val;
    }
    double lerp(double a, double b,double t){
        return a+(b-a)*t;
    }
}

namespace GameMath{
    int clamp(int val,int min,int max){
        if(val<min) return min;
        if(val>max) return max;
        return val;
    }

    double lerp(double a,double b, double t){
        return a+(b-a)*t;
    }
}

int main(){
    cout << fixed << setprecision(2);
    // Calling Physics::clamp()
    double velocity = Physics::clamp(150.5, 0.0, 100.0);
    cout << "Physics Clamp : "<< velocity << endl;
    // Calling GameMath::clamp()
    int health = GameMath::clamp(120, 0, 100);
    cout << "GameMath Clamp : "<< health << endl;
    // Calling Physics::lerp()
    double physicsValue = Physics::lerp(10.0, 50.0, 0.5);
    cout << "Physics Lerp : "<< physicsValue << endl;
    // Calling GameMath::lerp()
    double uiValue = GameMath::lerp(0.0, 100.0, 0.25);
    cout << "GameMath Lerp : "<< uiValue << endl;
    // Limited scope for using namespace
    {
        using namespace GameMath;
        int level = clamp(15, 1, 10);
        cout << "Limited Scope GameMath Clamp : "<< level << endl;
    }
    // GameMath namespace is NOT active here So explicit namespace qualification is required.
    int anotherHealth = GameMath::clamp(150, 0, 100);
    cout << "Outside Scope Clamp : "<< anotherHealth << endl;
    return 0;
}