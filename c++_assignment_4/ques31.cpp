#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iomanip>

using namespace std;


// ============================================================
// PART A - ABSTRACT DATA PROCESSOR
// ============================================================

class DataProcessor {
public:

    // Pure virtual functions
    virtual void loadData(const string& source) = 0;
    virtual void processData() = 0;
    virtual void exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;

    // Non-pure virtual function
    virtual void printSummary() const {
        cout << "Processor: " << processorType() << endl;
        cout << "Records: " << recordCount() << endl;
    }

    // Virtual destructor
    virtual ~DataProcessor() = default;
};


// ============================================================
// CSV PROCESSOR
// ============================================================

class CSVProcessor : public DataProcessor {
private:
    vector<string> records;

public:

    void loadData(const string& source) override {

        cout << "[CSV] Loading data from: "
             << source << endl;

        // Hard-coded sample CSV rows
        records = {
            "name,age,city",
            "ankit,21,ranchi",
            "rahul,22,delhi",
            "priya,20,mumbai",
            "aman,23,patna"
        };
    }

    void processData() override {

        // Convert every record to uppercase
        for (string& record : records) {

            for (char& ch : record) {
                ch = static_cast<char>(
                    toupper(static_cast<unsigned char>(ch))
                );
            }
        }

        cout << "[CSV] Data processed" << endl;
    }

    void exportResult(const string& destination) override {

        cout << "[CSV EXPORT + "
             << destination
             << "]" << endl;

        for (const string& record : records) {
            cout << record << endl;
        }
    }

    string processorType() const override {
        return "CSV Processor";
    }

    int recordCount() const override {
        return records.size();
    }

    void printSummary() const override {

        cout << "Processor: "
             << processorType() << endl;

        cout << "Records: "
             << recordCount() << endl;
    }
};


// ============================================================
// SENSOR STREAM PROCESSOR
// ============================================================

class SensorStreamProcessor : public DataProcessor {
private:
    vector<double> readings;

    double mean = 0.0;
    double minimum = 0.0;
    double maximum = 0.0;

public:

    void loadData(const string& source) override {

        cout << "[Sensor] Loading data from: "
             << source << endl;

        // 8 sample sensor readings
        readings = {
            23.4,
            21.8,
            25.1,
            24.6,
            22.9,
            26.3,
            23.7,
            24.2
        };
    }

    void processData() override {

        if (readings.empty()) {
            mean = minimum = maximum = 0.0;
            return;
        }

        double sum = 0.0;

        minimum = readings[0];
        maximum = readings[0];

        for (double value : readings) {

            sum += value;

            if (value < minimum) {
                minimum = value;
            }

            if (value > maximum) {
                maximum = value;
            }
        }

        mean = sum / readings.size();

        cout << "[Sensor] Data processed" << endl;
    }

    void exportResult(const string& destination) override {

        cout << "[SENSOR EXPORT + "
             << destination
             << "]" << endl;

        cout << fixed << setprecision(2);

        cout << "Mean: " << mean << endl;
        cout << "Min: " << minimum << endl;
        cout << "Max: " << maximum << endl;
    }

    string processorType() const override {
        return "Sensor Stream Processor";
    }

    int recordCount() const override {
        return readings.size();
    }

    void printSummary() const override {

        cout << fixed << setprecision(2);

        cout << "Processor: "
             << processorType() << endl;

        cout << "Readings: "
             << recordCount() << endl;

        cout << "Mean: "
             << mean << endl;

        cout << "Min: "
             << minimum << endl;

        cout << "Max: "
             << maximum << endl;
    }
};


// ============================================================
// PART B - DATA BUFFER TEMPLATE
// ============================================================

template <typename T>
class DataBuffer {
private:

    T* data;        // Heap-allocated array
    int capacity;

    int head;       // Index of oldest element
    int tail;       // Index where next element is written
    int count;      // Current number of elements

public:

    // Constructor
    DataBuffer(int capacity)
        : capacity(capacity),
          head(0),
          tail(0),
          count(0) {

        data = new T[capacity];
    }

    // Destructor
    ~DataBuffer() {
        delete[] data;
    }


    // --------------------------------------------------------
    // Push
    // --------------------------------------------------------

    void push(const T& value) {

        data[tail] = value;

        // Move tail circularly
        tail = (tail + 1) % capacity;

        if (count < capacity) {

            count++;

        } else {

            // Buffer was full.
            // Oldest element is overwritten.

            head = (head + 1) % capacity;
        }
    }


    // --------------------------------------------------------
    // Pop
    // --------------------------------------------------------

    T pop() {

        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        T value = data[head];

        head = (head + 1) % capacity;

        count--;

        return value;
    }


    // --------------------------------------------------------
    // Peek
    // --------------------------------------------------------

    T peek() const {

        if (isEmpty()) {
            throw underflow_error("Buffer is empty");
        }

        return data[head];
    }


    // --------------------------------------------------------
    // isEmpty
    // --------------------------------------------------------

    bool isEmpty() const {
        return count == 0;
    }


    // --------------------------------------------------------
    // isFull
    // --------------------------------------------------------

    bool isFull() const {
        return count == capacity;
    }


    // --------------------------------------------------------
    // Size
    // --------------------------------------------------------

    int size() const {
        return count;
    }


    // --------------------------------------------------------
    // Friend << operator
    // --------------------------------------------------------

    template <typename U>
    friend ostream& operator<<(
        ostream& out,
        const DataBuffer<U>& buf
    );
};


// ============================================================
// FRIEND << OPERATOR
// ============================================================

template <typename U>
ostream& operator<<(
    ostream& out,
    const DataBuffer<U>& buf
) {

    out << "[";

    for (int i = 0; i < buf.count; i++) {

        int index =
            (buf.head + i) % buf.capacity;

        out << buf.data[index];

        if (i < buf.count - 1) {
            out << ", ";
        }
    }

    out << "]";

    return out;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    // ========================================================
    // PART A - ABSTRACT CLASS / POLYMORPHISM
    // ========================================================

    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());


    for (auto* p : pipeline) {

        cout << endl;

        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }


    // You CANNOT create an object of an abstract class.
    // DataProcessor dp;   // ERROR: DataProcessor is abstract


    // Cleanup dynamically allocated processors
    for (auto* p : pipeline) {
        delete p;
    }

    pipeline.clear();


    // ========================================================
    // PART B - DATA BUFFER<int>
    // ========================================================

    cout << endl;
    cout << "===== INTEGER BUFFER =====" << endl;

    DataBuffer<int> tickBuffer(5);

    for (int i = 1; i <= 7; i++) {
        tickBuffer.push(i * 10);
    }

    cout << "Tick Buffer: "
         << tickBuffer << endl;


    // ========================================================
    // DOUBLE BUFFER
    // ========================================================

    cout << endl;
    cout << "===== DOUBLE BUFFER =====" << endl;

    DataBuffer<double> tempBuffer(4);

    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);

    cout << fixed << setprecision(1);

    cout << "Before pop: "
         << tempBuffer << endl;

    cout << "Popped: "
         << tempBuffer.pop() << endl;

    cout << "After pop: "
         << tempBuffer << endl;


    // ========================================================
    // STRING BUFFER
    // ========================================================

    cout << endl;
    cout << "===== STRING BUFFER =====" << endl;

    DataBuffer<string> logBuffer(3);

    logBuffer.push("INFO: Server started");

    logBuffer.push("WARN: High memory usage");

    logBuffer.push("ERROR: DB connection timeout");

    logBuffer.push("INFO: Retry successful");

    cout << "Log Buffer: "
         << logBuffer << endl;


    return 0;
}


/*
IMPORTANT TEMPLATE NOTE:

The DataBuffer<T> template implementation is kept entirely
in this file.

Template definitions generally need to be visible at the
point where the compiler generates code for a particular type.

For example:

    DataBuffer<int>
    DataBuffer<double>
    DataBuffer<string>

If the template implementation is placed only inside a
separate .cpp file, the compiler may not see the definition
when it needs to instantiate the template.

Therefore template classes are normally implemented entirely
in a header file (.h/.hpp), or kept together in one source
file as done here.
*/