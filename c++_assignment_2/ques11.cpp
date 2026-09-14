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
            cout<<productId<<"    "<<name<<"    "<<price<<"   "<<quantity<<"   "<<totalValue()<<endl;
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
    int n;
    cout<<"Enter the no of product:"<<endl;
    cin>>n;
    Product products[n];
    cout<<" =========== Enter product details ============ "<<endl;
    for(int i=0;i<n;i++){
        products[i].acceptDetails();
        cout<<endl;
    }
    cout<<" ===== INVENTORY DETAILS ========"<<endl;

    cout<<"  "<< "ID"<<"   "<< "Name"<<"  "<< "Price"<<"    "<< "Qty"<<"    "<< "Total Value"
         << "Status" << endl;

    cout << string(80, '-') << endl;

    for (int i = 0; i < n; i++) {
        products[i].displayDetails();
    }

    // 4. Find product with highest total value
    int highestIndex = 0;

    for (int i = 1; i < n; i++) {
        if (products[i].totalValue() >products[highestIndex].totalValue()) {
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

    for (int i = 0; i < n; i++) {
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