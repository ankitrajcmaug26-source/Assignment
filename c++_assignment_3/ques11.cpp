#include<iostream>
using namespace std;
enum class HttpStatus{
    Ok=200, Created=201, BadRequest=400,Unauthorized=401,NotFound=404,ServerError=500
};
void handleResponse(HttpStatus status, const string& endpoint){
    cout<<" [ " <<endpoint<<" ]   : ";
    int code=static_cast<int>(status);
    switch(code){
        case 200:
                cout<<" -> 200 Ok      : Request successful"<<endl;
                break;
        case 201:
                cout<<" -> 201  Created   : "<<endl;
                break;
        case 400:
                cout<<" -> 400 BadRequest"<<endl;
                break;
        case 401:
                cout<<" -> 401 Unauthorized"<<endl;
                break;
        case 404:
                cout<<" -> 404 Not Found"<<endl;
                break;
        case 500:
                cout<<" -> 500 ServerError"<<endl;
                break;
    }
}

int main(){
    handleResponse(HttpStatus::Ok,"/api/users");
    handleResponse(HttpStatus::Unauthorized,"/api/login");
    handleResponse(HttpStatus::NotFound,"/api/products/99");
    handleResponse(HttpStatus::ServerError,"/api/order");
    return 0;
}