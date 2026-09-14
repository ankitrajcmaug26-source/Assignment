#include<iostream>
#include<memory>
using namespace std;
class Texture{
    private:
        string name;
        int width;
        int height;
    public:
        //default constructor
        Texture():name("Unknown"),width(0),height(0){};
        //parameterized constructor
        Texture(string n,int w,int h):name(n),width(w),height(h){};
        
        void display() const{
            cout<<"Texture: "<<name<<endl;
            cout<<"Dimension: "<<width<< " * "<<height<<endl;
        }
        
        //Destructor
        ~Texture(){
            cout<<"Destructor is called"<<endl;
        };
};

int main(){
    auto text1=make_unique<Texture>("Player",20,25);
    text1->display();

    unique_ptr<Texture> text2=move(text1);
    cout<<"text1 is null: "<<(text1==nullptr ? "YES":"NO")<<endl;
    return 0;
}