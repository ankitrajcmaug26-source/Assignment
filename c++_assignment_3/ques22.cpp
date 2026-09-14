#include<iostream>
#include<memory>
using namespace std;
class Shader{
    private:
        string name;
        string type;
    public:
        //default constructor
        Shader():name("Unknown"),type("Unknown"){};
        //parameterized constructor
        Shader(string n,string t):name(n),type(t){
            cout<<"Shader Compiled"<<endl;
        };
        
        int getReferenceCount(const shared_ptr<Shader>& ptr){
            return ptr.use_count();
        }

        ~Shader(){
            cout<<"Shader Destroyed"<<endl;
        }
};

int main(){
    // Required structure in main():
    auto shader = make_shared<Shader>("main_vert", "vertex");
        cout << "Ref count: " << shader.use_count() << endl;
    {    auto rendererRef = shader;
        cout << "Ref count: " << shader. use_count() << endl; // 2
        auto editorRef = shader;
        cout << "Ref count: " << shader.use_count() << endl; // 3
    }
        cout << "Ref count: " << shader.use_count() << endl;
    
    return 0;
}