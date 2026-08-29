#include<iostream>
using namespace std;
int main(int argc,char* argv[]){
    if(argc!=4){
        cout<<"Usage : ./sensor_monitor <Warm_threshold> <critical_threshold> <num_readings>"<<endl;
        cout<<"Error : Missing Arguments."<<endl;
        return 1;
    }
    int warn=atoi(argv[1]);
    int critical=atoi(argv[2]);
    int n=atoi(argv[3]);
    if(warn>=critical){
        cout<<"Error : warn_threshold must be less than critical_threshold"<<endl;
        return 1;
    }
    if(n<=1 ||n>500){
        cout<<"Error : num_readings must be greater than 1 and less than 500."<<endl;
        return 1;
    }
    int normal=0;
    int shut=0;
    int warning=0;
    int critical_c=0;
    for(int i=0;i<n;i++){
        int temp=rand()%70;
        if(temp<warn){
            normal++;
        }else if(temp<critical){
            warning++;
        }else if(temp<60){
            critical_c++;
        }else{
            shut++;
        }
    }
    cout<<"Config  : warn="<<warn<<" C  Critical="<<critical<<" C  Readings="<<n <<endl;
    cout<<"Results : Normal = "<<normal<<" Warning: "<<warning<<" Critical: "<<critical_c<<" Shoutdown: "<<shut<<endl;
    cout<<""<<endl;

}