#include<iostream>
#include<limits>
using namespace std;
int main(){
    double temp[3][3];
    double max=-numeric_limits<double>::infinity();
    double avg=0;
    int floa,room,w=0,f;
    cout<<"Enter the temperatur for : "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>temp[i][j];
        }
    }
    
    for(int i=0;i<3;i++){
        double sum=0;
        cout<<"Floor "<<i+1<<" :  ";
        for(int j=0;j<3;j++){
            sum+=temp[i][j];
            cout<<temp[i][j]<<" ";
            if(temp[i][j]>max){
                max=temp[i][j];
                floa=i;
                room=j;
            }
            if(temp[i][j]>=30) w++;
        }
        if((sum/3)>avg){
            avg=sum/3;
            f=i;
        }
        cout<<""<<endl;
    }
    cout<<"Hottest Room : Floor "<< floa+1<<" Room : "<<room+1 << "-> "<<max <<" C"<<endl;
    cout<<"Hottest Floar: Floor "<<f+1<<" ( avg "<<avg<<" C)" <<endl;
    cout<<"Rooms at warning or Above "<<w<<endl;
    return 0;
}