#include<iostream>
#include<vector>
using namespace std;
struct Person {
    string name;
    int age;
    char gender;
};
int main() {
    // Array declaration and initialization
    int intArray[5] = { 1, 2, 3, 4, 5 };

    // Vector declaration and operations
    vector<int> intVector = { 6, 7, 8, 9, 10 };
    intVector.push_back(11); // Adding an element to the end of the vector

    cout << "Array Elements: ";
    for (int i = 0; i < 5; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    cout << "Vector Elements: ";
    for (int val : intVector) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Structure definition


// Class definition
class Student {
private:
    string studentID;
public:
    string name;
    int grade;

    // Constructor
    Student(string sID, string sName, int sGrade) {
        studentID = sID;
        name = sName;
        grade = sGrade;
    }

    // Member function to display student details
    void displayDetails() {
        cout << "ID: " << studentID << ", Name: " << name << ", Grade: " << grade << endl;
    }
};

int main2() {
    // Using the structure
    Person person1 = { "Alice", 25, 'F' };
    cout << person1.name << " is " << person1.age << " years old." << endl;

    // Using the class
    Student student1("S12345", "Bob", 90);
    student1.displayDetails();

    return 0;
}
