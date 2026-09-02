#include<iostream>
#include<string>
using namespace std;

class Entity{
    private:
        string name;
        int health;
        int level;
        string type;
    
    public:
        //setter
        Entity& setName(const string& name){
            this->name=name;
            return *this;
        }
        Entity& setHealth(int health){
            this->health=health;
            return *this;
        }
        Entity& setLevel(int level){
            this->level=level;
            return *this;
        }
        Entity& setType(const string& type){
            this->type=type;
            return *this;
        }
        //getter
        string getName() const{
            return name;
        }
        int getHealth() const{
            return health;
        }
        int getLevel() const{
            return level;
        }
        string getType() const{
            return type;
        }

        void displayInfo() const{
            cout<<"Name : "<<name<<endl;
            cout<<"Health : "<<health<<endl;
            cout<<"Level : "<<level<<endl;
            cout<<"Type : "<<type<<endl;
            cout<<"-----------------------"<<endl;
        }
};

int main(){

    Entity player,enemy,item;
    player.setName("Aragon").setHealth(100).setLevel(10).setType("Player");
    player.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    player.setName("HealthPotion").setHealth(0).setLevel(1).setType("item");

    cout<<"======== Game Entity ============="<<endl;
    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();
    return 0;
}