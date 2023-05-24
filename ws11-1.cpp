#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Vector of int.
// Used to store the records.
typedef vector<int> Records;

class RecordsManager {
private:
    fstream _file;
    string _filename;

public:
    RecordsManager(string filename) : _filename(filename) {}

    void read(Records& records) {
        _file.open(_filename, ios::in);
        if (_file.is_open()) {
            string line;
            while (getline(_file, line)) {
                try {
                    records.push_back(stoi(line));
                } catch (const exception& e) {
                    cout << "Wrong argument when reading the file: " << _filename << endl;
                    _file.close();
                    return;
                }
            }
            _file.close();
        } else {
            cout << "Out of range when reading the file: " << _filename << endl;
        }
    }
};

int main() {
    // Test cases: Uncomment one at a time to test.

    // RecordsManager recordM("test_clean.txt");
    // RecordsManager recordM("test_corrupt1.txt");
    RecordsManager recordM("test_corrupt2.txt");

    Records myRecords;
    recordM.read(myRecords);

    if (!myRecords.empty()) {
        int sum = 0;
        for (int i = 0; i < myRecords.size(); i++) {
            sum += myRecords[i];
        }
        cout << "Sum: " << sum << endl;
    }

    return 0;
}