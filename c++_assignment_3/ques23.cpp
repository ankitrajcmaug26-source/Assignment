#include<iostream>
#include<memory>
using namespace std;
class Audio{
    private:
        string name;
        int duration;
    public:
        Audio():name("Unknown"),duration(0){};
        Audio(string n,int d):name(n),duration(d){
            cout<<"Construct "<<endl;
        }

        ~Audio(){
            cout<<"Destructor"<<endl;
        }
        string getName() const{
            return name;
        }
};
int main(){
    // Required structure in main():
    auto audio = make_shared<Audio>("explosion", 3.5);
    weak_ptr<Audio> observer = audio;

    if (auto clip = observer.lock())
    cout << "Clip alive: " << clip->getName() << endl;

    audio.reset(); // unload

    if (observer.expired())
    cout << "Clip already unloaded." << endl;
    return 0;
}