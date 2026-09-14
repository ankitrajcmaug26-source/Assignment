#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <utility>
using namespace std;
class LedgerEntry {
private:
    string name;
    int days;
    double* amounts;
public:
    // Static member
    static int totalEntries;
    // Constructor
    LedgerEntry(string n, int d) {
        name = n;
        days = d;
        amounts = new double[days];
        for (int i = 0; i < days; i++) {
            amounts[i] = 0.0;
        }
        totalEntries++;
        cout << "[LedgerEntry Created] "<< name << " (" << days << " days)" << endl;
    }
    // Copy Constructor - Deep Copy
    LedgerEntry(const LedgerEntry& other) {
        name = other.name;
        days = other.days;
        if (other.amounts != nullptr) {
            amounts = new double[days];
            for (int i = 0; i < days; i++) {
                amounts[i] = other.amounts[i];
            }
        } else {
            amounts = nullptr;
        }
        totalEntries++;
        cout << "[Copy Constructor] "<< other.name << endl;
    }
    // Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept {
        name = other.name;
        days = other.days;
        amounts = other.amounts;
        // Transfer ownership
        other.amounts = nullptr;
        other.days = 0;
        totalEntries++;
        cout << "[Move Constructor] Ownership transferred from: "<< name << endl;
    }
    // Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other) {
        if (this == &other) {
            return *this;
        }
        delete[] amounts;
        name = other.name;
        days = other.days;
        if (other.amounts != nullptr) {
            amounts = new double[days];
            for (int i = 0; i < days; i++) {
                amounts[i] = other.amounts[i];
            }
        } else {
            amounts = nullptr;
        }
        cout << "[Copy Assignment] "<< other.name << endl;
        return *this;
    }
    // Move Assignment Operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept {
        if (this != &other) {
            // Delete existing memory
            delete[] amounts;
            // Transfer ownership
            name = other.name;
            days = other.days;
            amounts = other.amounts;
            // Make source empty
            other.amounts = nullptr;
            other.days = 0;
            cout << "[Move Assignment] Ownership transferred from: "<< name << endl;
        }
        return *this;
    }
    // Subscript operator
    double& operator[](int index) {
        if (index < 0 || index >= days) {
            throw out_of_range("Index out of range");
        }
        return amounts[index];
    }
    // Const subscript operator
    const double& operator[](int index) const {
        if (index < 0 || index >= days) {
            throw out_of_range("Index out of range");
        }
        return amounts[index];
    }
    // Get name
    string getName() const {
        return name;
    }
    // Get days
    int getDays() const {
        return days;
    }
    // Destructor
    ~LedgerEntry() {
        delete[] amounts;
        totalEntries--;
        cout << "[Destructor] "<< name << " destroyed" << endl;
    }
    // Friend << operator
    friend ostream& operator<<(ostream& out, const LedgerEntry& entry);
    // Friend comparison operators
    friend bool operator==(const LedgerEntry& a, const LedgerEntry& b);
    friend bool operator>(const LedgerEntry& a, const LedgerEntry& b);
};
// Initialize static member
int LedgerEntry::totalEntries = 0;
// << operator
ostream& operator<<(ostream& out, const LedgerEntry& entry) {
    out << entry.name << " : [";
    double total = 0.0;
    for (int i = 0; i < entry.days; i++) {
        out << fixed << setprecision(2)<< entry.amounts[i];
        total += entry.amounts[i];
        if (i < entry.days - 1) {
            out << ", ";
        }
    }
    out << "] Total: "<< fixed << setprecision(2)<< total;
    return out;
}
// == operator
bool operator==(const LedgerEntry& a, const LedgerEntry& b) {
    if (a.days != b.days) {
        return false;
    }
    for (int i = 0; i < a.days; i++) {
        if (a.amounts[i] != b.amounts[i]) {
            return false;
        }
    }
    return true;
}
// > operator
bool operator>(const LedgerEntry& a, const LedgerEntry& b) {
    double totalA = 0.0;
    double totalB = 0.0;
    for (int i = 0; i < a.days; i++) {
        totalA += a.amounts[i];
    }
    for (int i = 0; i < b.days; i++) {
        totalB += b.amounts[i];
    }
    return totalA > totalB;
}
int main() {
    // Objective 1
    LedgerEntry jan("January Sales", 5);
    LedgerEntry feb("February Sales", 5);
    jan[0] = 1200.50;
    jan[1] = 3400.00;
    jan[2] = 800.75;
    jan[3] = 2100.00;
    jan[4] = 650.25;
    feb[0] = 900.00;
    feb[1] = 2200.50;
    feb[2] = 1750.00;
    feb[3] = 3000.00;
    feb[4] = 475.50;
    // Print entries
    cout << endl;
    cout << jan << endl;
    cout << feb << endl;
    // Comparisons
    cout << endl;
    cout << "Jan == Feb : "<< (jan == feb ? "Yes" : "No") << endl;
    cout << "Jan > Feb : "<< (jan > feb ? "Yes" : "No") << endl;
    // Objective 2 - Move Constructor
    LedgerEntry moved = move(jan);
    cout << "After move, jan.amounts is null: "<< (jan.amounts == nullptr ? "YES" : "NO") << endl;
    cout << "Moved entry : "<< moved << endl;
    // Objective 5 - Move Assignment
    LedgerEntry q1("Q1 Total", 5);
    q1 = move(feb);
    cout << "Q1 (moved from feb) : "<< q1 << endl;
    // Objective 6 - Static member
    cout << endl;
    cout << "Live LedgerEntry objects: "<< LedgerEntry::totalEntries << endl;
    return 0;
}