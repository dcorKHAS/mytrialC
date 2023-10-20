#include<iostream>
#include<fstream>  // Required for file I/O
#include <string>
using namespace std;

int main() {
    // Simple console input-output
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "! Welcome to C++ I/O operations." << endl;

    // Writing to a file
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "This is a line written to a file." << endl;
        outFile << "Hello, " << name << "! This is your entry in the file." << endl;
        outFile.close();
        cout << "Data written to output.txt" << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }

    // Reading from a file
    ifstream inFile("output.txt");
    string line;
    if (inFile.is_open()) {
        cout << "\nReading from output.txt:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }

    return 0;
}
