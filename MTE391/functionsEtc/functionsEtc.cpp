#include<iostream>
using namespace std;

int main() {
    int num = 5;

    // if-else control structure
    if (num > 0) {
        cout << "Number is positive." << endl;
    }
    else {
        cout << "Number is non-positive." << endl;
    }

    // for loop
    cout << "For loop output: ";
    for (int i = 0; i < num; i++) {
        cout << i << " ";
    }
    cout << endl;

    // while loop
    int count = num;
    cout << "While loop output: ";
    while (count > 0) {
        cout << count << " ";
        count--;
    }
    cout << endl;

    return 0;
}

#include<iostream>
using namespace std;

// Simple function to add two integers
int add(int a, int b) {
    return a + b;

    // This line will never be executed
}

// Overloaded function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Overloaded function to add two doubles
double add(double a, double b) {
    return a + b;
}

int main2() {
    int x = 10, y = 20, z = 30;
    double m = 2.5, n = 3.5;

    cout << "Addition of two integers: " << add(x, y) << endl;
    cout << "Addition of three integers: " << add(x, y, z) << endl;
    cout << "Addition of two doubles: " << add(m, n) << endl;

    //switch example

    int choice = 2;

    switch (choice) {

    case 1:
        cout << "Choice is 1" << endl;
		break;

    case 2:
        cout << "Choice is 2" << endl;
        break;

    default:
		cout << "Choice is neither 1 nor 2" << endl;
		break;


    }


    return 0;
}
