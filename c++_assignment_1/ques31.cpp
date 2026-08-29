#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
private:

    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;

public:
    // Constructor
    Employee() {
        empId = 1000 + (++employeeCount);
        name = "";
        department = "";
        grade = 'D';
        basicSalary = 0;
        isActive = true;
    }
    // ================= SETTERS =================
    void setName(const string& n) {
        if (n.empty()) {
            cout << "ERROR: Name cannot be empty. Value rejected." << endl;
            return;
        }
        name = n;
    }
    void setDepartment(const string& dept) {
        if (dept == "Engineering" ||dept == "HR"||dept == "Finance" ||dept == "Operations") {
            department = dept;
        }
        else {
            cout << "ERROR: '" << dept << "' is not a registered department." << endl;
        }
    }
    void setGrade(char g) {
        if (g == 'A' || g == 'B' ||g == 'C' || g == 'D') {
            grade = g;
        }
        else {
            cout << "ERROR: Invalid grade '" << g<< "'. Accepted values: A, B, C, D."<< endl;
        }
    }
    void setBasicSalary(double salary) {
        if (salary > 10000 && salary < 500000) {
            basicSalary = salary;
        }
        else {
            cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected." << endl;
        }
    }
    void deactivate() {
        isActive = false;
    }
    // ================= GETTERS =================
    int getEmpId() const {
        return empId;
    }
    string getName() const {
        return name;
    }
    string getDepartment() const {
        return department;
    }
    char getGrade() const {
        return grade;
    }
    double getBasicSalary() const {
        return basicSalary;
    }
    bool getIsActive() const {
        return isActive;
    }
    // ================= BUSINESS LOGIC =================
    double computeAllowances() const {
        if (grade == 'A') {
            return basicSalary * 0.40;
        }
        else if (grade == 'B') {
            return basicSalary * 0.30;
        }
        else if (grade == 'C') {
            return basicSalary * 0.20;
        }
        else {
            return basicSalary * 0.10;
        }
    }
    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }
    double computeTax() const {
        double gross = computeGrossSalary();
        if (gross <= 50000) {
            return 0;
        }
        else if (gross <= 100000) {
            return (gross - 50000) * 0.10;
        }
        else {
            return 5000 + (gross - 100000) * 0.20;
        }
    }
    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }
    void printPayslip() const {
        cout << fixed << setprecision(2);
        cout << "\n========================================" << endl;
        cout << "       EMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "========================================" << endl;
        cout << "Emp ID       : " << empId << endl;
        cout << "Name         : " << name << endl;
        cout << "Department   : " << department << endl;
        cout << "Grade        : " << grade << endl;
        cout << "Status       : "<< (isActive ? "Active" : "Inactive") << endl;
        cout << "----------------------------------------" << endl;
        cout << "Basic Salary : Rs. "<< basicSalary << endl;
        cout << "Allowances (";
        if (grade == 'A')
            cout << "40%)";
        else if (grade == 'B')
            cout << "30%)";
        else if (grade == 'C')
            cout << "20%)";
        else
            cout << "10%)";
        cout << " : Rs. " << computeAllowances() << endl;
        cout << "Gross Salary : Rs. "<< computeGrossSalary() << endl;
        cout << "Tax Deduction: Rs. "<< computeTax() << endl;
        cout << "Net Salary   : Rs. "<< computeNetSalary() << endl;
        cout << "========================================" << endl;
    }
    // ================= STATIC FUNCTION =================
    static int getEmployeeCount() {
        return employeeCount;
    }
    // ================= INPUT =================
    void acceptDetails() {
        string n;
        string dept;
        char g;
        double salary;
        cout << "\nEnter name: ";
        getline(cin >> ws, n);
        setName(n);
        cout << "Enter department: ";
        getline(cin >> ws, dept);
        setDepartment(dept);
        cout << "Enter grade: ";
        cin >> g;
        setGrade(g);
        cout << "Enter basic salary: ";
        cin >> salary;
        setBasicSalary(salary);
    }
};
// Static data member must be defined outside the class
int Employee::employeeCount = 0;
// ================= MAIN =================
int main() {
    // One object on stack
    Employee e1;
    // Two objects on heap
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();
    // Try uncommenting these lines.
    // They produce compiler errors because empId
    // and basicSalary are private members.
    // e1.empId = 999;
    // e1.basicSalary = -1000;
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();
    // Simulate resignation
    e3->deactivate();
    if (!e3->getIsActive()) {
        cout << e3->getName()<< " is no longer active. Payroll skipped."<< endl;
    }
    cout << "Total Employees : "<< Employee::getEmployeeCount()<< endl;
    delete e2;
    delete e3;
    return 0;
}