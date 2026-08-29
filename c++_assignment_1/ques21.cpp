#include<iostream>
using namespace std;
void resetSensorPairV1(int r1,int r2){
    int temp=r1;
    r1=r2;
    r2=temp;
}
void resetSensorPairV2(int& r1,int& r2){
    int temp=r1;
    r1=r2;
    r2=temp;
}
void resetSensorPairV3(int* r1,int* r2){
    int temp=*r1;
    *r1=*r2;
    *r2=temp;
}
int main(){
    int a,b;
    cout<<"Enter two number: "<<endl;
    cin>>a>>b;
    cout<<"-------------- Call by Value ----------- "<<endl;
    cout<<"Before Swap : A= "<<a<<"  B= "<<b<<endl;
    resetSensorPairV1(a,b);
    cout<<"After Swap  : A= "<<a<<"  B= "<<b<<endl;

    cout<<"-------------- Call by Referance ----------- "<<endl;
    cout<<"Before Swap : A= "<<a<<"  B= "<<b<<endl;
    resetSensorPairV2(a,b);
    cout<<"After Swap  : A= "<<a<<"  B= "<<b<<endl;

    cout<<"-------------- Call by pointer ----------- "<<endl;
    cout<<"Before Swap : A= "<<a<<"  B= "<<b<<endl;
    resetSensorPairV3(&a,&b);
    cout<<"After Swap  : A= "<<a<<"  B= "<<b<<endl;
    

    return 0;
}