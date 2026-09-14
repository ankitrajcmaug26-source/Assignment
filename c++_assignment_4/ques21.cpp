#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==================== Vehicle Base Class ====================

class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(const string& reg, const string& owner,
            int year, double km)
        : registrationNo(reg),
          ownerName(owner),
          yearOfManufacture(year),
          kmDriven(km) {
        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    // Pure virtual function
    virtual double fuelCost(double kmToTravel) const = 0;

    // Virtual function
    virtual void describe() const {
        cout << "Registration: " << registrationNo << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Year: " << yearOfManufacture << endl;
        cout << "KM Driven: " << kmDriven << endl;
    }

    // Pure virtual function
    virtual string vehicleType() const = 0;

    // Virtual destructor
    virtual ~Vehicle() {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
    }

    double getKmDriven() const {
        return kmDriven;
    }

    string getRegNo() const {
        return registrationNo;
    }

    string getOwnerName() const {
        return ownerName;
    }
};


// ==================== Car ====================

class Car : public Vehicle {
private:
    string fuelType;
    double mileageKmpl;

public:
    Car(const string& reg, const string& owner,
        int year, double km,
        const string& fuel, double mileage)
        : Vehicle(reg, owner, year, km),
          fuelType(fuel),
          mileageKmpl(mileage) {

        cout << "[Car Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        double fuelPrice;

        if (fuelType == "Petrol") {
            fuelPrice = 106.00;
        }
        else {
            fuelPrice = 93.00;
        }

        double fuelRequired = kmToTravel / mileageKmpl;

        return fuelRequired * fuelPrice;
    }

    string vehicleType() const override {
        return "Car";
    }

    void describe() const override {

        Vehicle::describe();

        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileageKmpl
             << " km/l" << endl;
    }

    ~Car() override {
        cout << "[Car Destructor] "
             << registrationNo << endl;
    }
};


// ==================== Truck ====================

class Truck : public Vehicle {
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(const string& reg, const string& owner,
          int year, double km,
          double payload, double efficiency)
        : Vehicle(reg, owner, year, km),
          payloadCapacityTons(payload),
          fuelEfficiencyKmpl(efficiency) {

        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        // Efficiency drops by 5% per ton
        double effectiveEfficiency =
            fuelEfficiencyKmpl *
            (1.0 - 0.05 * payloadCapacityTons);

        double fuelRequired =
            kmToTravel / effectiveEfficiency;

        // Diesel price
        return fuelRequired * 93.00;
    }

    string vehicleType() const override {
        return "Truck";
    }

    void describe() const override {

        Vehicle::describe();

        cout << "Payload: "
             << payloadCapacityTons
             << " tons" << endl;

        cout << "Fuel Efficiency: "
             << fuelEfficiencyKmpl
             << " km/l" << endl;
    }

    ~Truck() override {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};


// ==================== ElectricTruck ====================

class ElectricTruck : public Truck {
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:
    ElectricTruck(const string& reg, const string& owner,
                  int year, double km,
                  double payload, double efficiency,
                  double battery, double range)
        : Truck(reg, owner, year, km,
                payload, efficiency),
          batteryCapacityKWh(battery),
          rangePerChargeKm(range) {

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        double energyUsed =
            (kmToTravel / rangePerChargeKm)
            * batteryCapacityKWh;

        return energyUsed * 9.50;
    }

    string vehicleType() const override {
        return "Electric Truck";
    }

    void describe() const override {

        Truck::describe();

        cout << "Battery Capacity: "
             << batteryCapacityKWh
             << " kWh" << endl;

        cout << "Range Per Charge: "
             << rangePerChargeKm
             << " km" << endl;
    }

    double getBatteryCapacity() const {
        return batteryCapacityKWh;
    }

    double getRange() const {
        return rangePerChargeKm;
    }

    ~ElectricTruck() override {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};


// ==================== Van ====================

class Van : public Vehicle {
private:
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(const string& reg, const string& owner,
        int year, double km,
        int seats, double mileage)
        : Vehicle(reg, owner, year, km),
          seatingCapacity(seats),
          mileageKmpl(mileage) {

        cout << "[Van Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        double fuelRequired =
            kmToTravel / mileageKmpl;

        // Petrol price
        return fuelRequired * 106.00;
    }

    string vehicleType() const override {
        return "Van";
    }

    void describe() const override {

        Vehicle::describe();

        cout << "Seating Capacity: "
             << seatingCapacity << endl;

        cout << "Mileage: "
             << mileageKmpl
             << " km/l" << endl;
    }

    ~Van() override {
        cout << "[Van Destructor] "
             << registrationNo << endl;
    }
};


// ==================== Fleet Report ====================

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm) {

    cout << endl;
    cout << "===== FLEET REPORT - Trip Distance: "
         << tripKm << " km =====" << endl;

    cout << left
         << setw(15) << "Registration"
         << setw(20) << "Type"
         << setw(25) << "Owner"
         << setw(15) << "KM Driven"
         << endl;

    cout << "---------------------------------------------------------------------"
         << endl;

    for (Vehicle* vehicle : fleet) {

        cout << left
             << setw(15) << vehicle->getRegNo()
             << setw(20) << vehicle->vehicleType()
             << setw(25) << vehicle->getOwnerName()
             << setw(15) << vehicle->getKmDriven()
             << endl;
    }

    // ==================== Fuel Cost ====================

    cout << endl;
    cout << "===== FUEL / CHARGE COST ESTIMATE =====" << endl;

    double minimumCost = 1e18;
    Vehicle* mostEfficient = nullptr;

    for (Vehicle* vehicle : fleet) {

        double cost = vehicle->fuelCost(tripKm);

        cout << vehicle->getRegNo()
             << " (" << vehicle->vehicleType() << ") : Rs. "
             << fixed << setprecision(2)
             << cost << endl;

        // Find minimum cost
        if (cost < minimumCost) {
            minimumCost = cost;
            mostEfficient = vehicle;
        }

        // Identify ElectricTruck
        ElectricTruck* electricTruck =
            dynamic_cast<ElectricTruck*>(vehicle);

        if (electricTruck != nullptr) {
            cout << "    [Battery: 85% charged]" << endl;
        }
    }

    // ==================== Most Efficient ====================
    cout << endl;
    if (mostEfficient != nullptr) {
        cout << "Most Efficient Vehicle: "<< mostEfficient->getRegNo()<< " (" << mostEfficient->vehicleType() << ")"<< " - Rs. "<< fixed << setprecision(2)<< minimumCost<< " for "<< tripKm<< " km"<< endl;
    }
}
int main() {
    // Part B
    cout << "===== CONSTRUCTOR / DESTRUCTOR TEST ====="<< endl;
    {
        ElectricTruck test("V-ET001","Green Logistics",2024,89020,5.0,4.0,85.0,350.0);
        cout << endl;
        cout << "ElectricTruck object is inside scope."<< endl;
    }
    cout << endl;
    // Part C
    cout << "===== CREATING FLEET =====" << endl;
    vector<Vehicle*> fleet;
    fleet.push_back(new Car("KA01AB001","Ramesh Kumar",2020,45260,"Petrol",15.0));
    fleet.push_back(new Truck("MH04BD002","Shyam Logistics",2019,123500,4.0,8.0));
    fleet.push_back(new ElectricTruck("GJ07CC003","Green Fleet Co",2024,89020,5.0,4.0,85.0,350.0));
    fleet.push_back(new Van("DL05EF004","City Transport",2021,67200,8,12.0));
    fleet.push_back(new Car("RJ14GH005","Fast Logistics",2022,38100,"Diesel",18.0));
    // Print fleet report
    printFleetReport(fleet, 200);
    // Cleanup
    cout << endl;
    cout << "===== CLEANUP =====" << endl;
    for (Vehicle* vehicle : fleet) {
        delete vehicle;
    }
    fleet.clear();
    return 0;
}