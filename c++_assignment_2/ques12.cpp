#include<iostream>
#include<iomanip>
using namespace std;

double reorderCost(int qty,double price){
    return qty*price;
}

double reorderCost(double qty,double unitPrice){
    return qty*unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate){
    double cost=qty*unitPrice;
    double tax=cost * taxRate/100;
    return cost+tax;
}
double applyDiscount(double price, double discountPercent=10.0){
    return price - (price * discountPercent /100);
}

int main(){
    cout << fixed << setprecision(2);

    // 1. Integer quantity
    int qty1 = 20;
    double price1 = 150.00;

    double cost1 = reorderCost(qty1, price1);

    cout << "Integer Quantity Cost : Rs. "
         << cost1 << endl;


    // 2. Fractional quantity
    double qty2 = 12.5;
    double price2 = 80.00;

    double cost2 = reorderCost(qty2, price2);

    cout << "Fractional Quantity Cost : Rs. "
         << cost2 << endl;


    // 3. Integer quantity with tax
    int qty3 = 10;
    double price3 = 200.00;
    double taxRate = 18.0;

    double cost3 = reorderCost(qty3, price3, taxRate);

    cout << "Cost With Tax : Rs. "
         << cost3 << endl;


    // 4. Discount with default value
    double price4 = 1000.00;

    double discountedPrice1 = applyDiscount(price4);

    cout << "After Default 10% Discount : Rs. "
         << discountedPrice1 << endl;


    // 5. Discount with user-provided value
    double discountedPrice2 = applyDiscount(price4, 20.0);

    cout << "After 20% Discount : Rs. "
         << discountedPrice2 << endl;

    return 0;
}