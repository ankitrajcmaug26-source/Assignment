#include<iostream>
#include<cmath>
using namespace std;
double computeRms(double* signal, int n){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=(*(signal+i))*(*(signal+i));
    }
    return sqrt(sum/n);
}
void normalise(double* signal, int n){
    double max=0;
    for(int i=0;i<n;i++){
        if(*(signal+i)>max){
            max=abs(*(signal+i));
        }
    }

    if(max!=0){
        for(int i=0;i<n;i++){
            *(signal+i)=*(signal+i)/max;
        }
    }
}

int countZeroCrossing(double* signal, int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        if(*(signal+i)>0 && *(signal+i+1)<0 || *(signal+i)<0 && *(signal+i+1)>0){
            count++;
        }
    }
    return count;
}
void applygain(double* signal,int n,double gainFactor){
    for(int i=0;i<n;i++){
        *(signal+1)=*(signal+1)*gainFactor;
    }
}
void print(double* signal,int n){
    for(int i=0;i<n;i++){
        cout<<*(signal+i)<<" ";
    }
    cout<<" "<<endl;
}
int main(){
    double signal[]={0.5, -1.2, 0.8,-0.3,1.0, -0.9, 0.1};
    int n=sizeof(signal)/sizeof(signal[0]);
    cout<<"Before Processing : "<<endl;
    print(signal,n);

    double rms=computeRms(signal,n);
    int crossing=countZeroCrossing(signal,n);
    cout<<"RMS: "<<rms<<endl;
    cout<<"Count Zero Crossing: "<<crossing<<endl;

    normalise(signal,n);
    cout<<"Ater Normalize: "<<endl;
    print(signal,n);

    double gainFac=2.0;
    cout<<"After applying gain ( "<<gainFac<<" ): "<<endl;
    applygain(signal,n,gainFac);
    print(signal,n);
    return 0;
}