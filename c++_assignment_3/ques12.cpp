#include<iostream>
#include<vector>
using namespace std;

using Header =pair<string,string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IpAddress =string;

typedef unsigned long long RequestId;
void printHeaders(const HeaderList& headers){
    cout<<"Headers: "<<endl;
    for(const Header& header: headers){
        cout<<header.first<<"  "<<header.second<<endl;
    }
}
int main(){
    RequestId ri=1078476839;
    Port port=8080;

    HeaderList header={
        {"Content-Type","application/json"},
        {"Authorization","Bearer eyjhbGci..."},
        {"Accept-Language","en-us"},
    };
    cout<<ri<<endl;
    cout<<port<<endl<<endl<<endl;
    printHeaders(header);
    return 0;
}