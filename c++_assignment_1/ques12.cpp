#include<iostream>
#include<limits>
using namespace std;
int main(){
    int sz=0,skip=0,idx=-1;
    double min=numeric_limits<double>::infinity(),max=-numeric_limits<double>::infinity(),sum=0,avg;
    cout<<"Enter the number of readings: "<<endl;
    cin >> sz;
    double arr[sz];
    cout<<"Enter the readings: ";
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
    cout<<"Readings Entered: "<<sz<<endl;
    cout<<"Valid Readings : ";
    for(int i=0;i<sz;i++){
        if(arr[i]<0){
            skip++;
            continue;
        }
        if(arr[i] > 45 && idx ==-1) idx=i;
        cout<<arr[i]<<" ";
        if(arr[i]>max) max=arr[i];
        if(min>arr[i]) min=arr[i];
        sum+=arr[i];
    }
    avg=sum/(sz-skip);
    cout<<""<<endl;
    cout<<"Skipped (errors): "<< skip <<endl;
    cout<<"First Critical : Index "<< idx <<" -> "<<arr[idx]<<" C "<<endl;
    cout<<" Min: "<<min;
    cout<<" Max: "<<max;
    cout<<" Avg: "<<avg<<endl;
    int n=0,w=0,c=0,s=0;
    for(int i=0;i<sz;i++){
        if(arr[i]>0 && arr[i]<30) n++;
        else if(arr[i]>=30 && arr[i]<44) w++;
        else if(arr[i]>=45 && arr[i]<=59) c++;
        else if(arr[i]>=60) s++;
    }
    cout<<"Normal: "<<n;
    cout<<"   Warning: "<<w;
    cout<<"   Critical: "<<c;
    cout<<"   Shutdown: "<<s;

    return 0;
}