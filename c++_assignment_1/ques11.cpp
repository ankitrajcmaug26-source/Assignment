#include<iostream>
using namespace std;
void sensor(double temp){
    int code;
    if(temp<0) code=-1;
    else if(temp>0 && temp<30) code=0;
    else if(temp>=30 && temp<44) code=1;
    else if(temp>=45 && temp<=59) code=2;
    else if(temp>=60) code=4;
    double f=(temp*1.8)+32;
    cout<<"Temperature : "<<temp<<" C /  "<<f<<" F"<<endl;
    switch(code){
        case -1:
                cout<<"Status      : SENSOR_ERROR"<<endl;
                cout<<"Action      : Sensor Fault - check wiring"<<endl;
                break;
        case 0:
                cout<<"Status      : NORMAL"<<endl;
                cout<<"Action      : No action required"<<endl;
                break;
        case 1:
                cout<<"Status      : WARNING"<<endl;
                cout<<"Action      : Alert sent to Supervisor"<<endl;
                break;
        case 2:
                cout<<"Status      : CRITICAL"<<endl;
                cout<<"Action      : Cooling system triggered "<<endl;
                break;
        case 3:
                cout<<"Status      : SHUTDOWN"<<endl;
                cout<<"Action      : Emergency shutdown initiated"<<endl;
                break;
    }
    cout<<"Reading     :"<< (temp > 25?" Above Average ":" Below Average ")<<endl;
}
int main(){
    double temp=0.0;
    cout<<"Enter the temperature in celcius: "<<endl;
    cin>>temp;
    sensor(temp);
    return 0;
    
}