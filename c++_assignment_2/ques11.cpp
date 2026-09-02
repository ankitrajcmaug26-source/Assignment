#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Product{
    private:
        int productId;
        string name;
        double price;
        int quantity;

    public:
        void acceptDetails(){
            cout<<"Enter the details as follow product id, name, price,quantity: "<<endl;
            cin>>productId>>name>>price>>quantity;
        }

        void displayDetails() const{
            cout<<left
                <<setw(12)<<productId
                <<setw(20)<<name
                <<setw(12)<<fixed<<setprecision(2)<<price
                <<setw(10)<<quantity
                <<setw(15)<<totalValue()<<endl;
        }
        double totalValue() const{
            return price * quantity;
        }
        bool isLowStock(int threshold) const{
            return quantity < threshold;
        }
        string getName(){
            return name;
        }
};

int main(){
    Product products[5];
    cout<<" =========== Enter product details ============ "<<endl;
    for(int i=0;i<5;i++){
        products[i].acceptDetails();
        cout<<endl;
    }
    cout<<" ===== INVENTORY DETAILS ========"<<endl;

    cout << left
         << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Price"
         << setw(10) << "Qty"
         << setw(15) << "Total Value"
         << "Status" << endl;

    cout << string(80, '-') << endl;

    for (int i = 0; i < 5; i++) {
        products[i].displayDetails();
    }

    // 4. Find product with highest total value
    int highestIndex = 0;

    for (int i = 1; i < 5; i++) {
        if (products[i].totalValue() >
            products[highestIndex].totalValue()) {
            highestIndex = i;
        }
    }
    cout << "\nHighest Value Product : "
         << products[highestIndex].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << products[highestIndex].totalValue()
         << ")" << endl;

    // 5. Enter threshold
    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "\nLow Stock (threshold: "
         << threshold << ") : ";

    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (products[i].isLowStock(threshold)) {

            if (found)
                cout << ", ";

            cout << products[i].getName();
            found = true;
        }
    }
    if (!found)
        cout << "None";

    cout << endl;

    return 0;
}