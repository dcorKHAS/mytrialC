// This is a single-line comment

/* This is a
   multi-line comment */

#include<iostream> // Preprocessor directive to include header files
//define notStd namespace

#define XX 20 // Macro definition
#define SPEED_OF_LIGHT 299792458 // Macro definition

namespace notStd1 {
	int a;
}
namespace notStd2 {
    int a;
}
using namespace std; // Using the standard namespace


// The main function - Entry point of the program
int main() {
    // Variable declaration and initialization
    int age = XX;
    
    // Variable assignment

    age += 5; // age = age + 5;

    int minor= age > 18 ? 0 : 1; // Ternary operator

    // Output statement
    cout << "Hello, C++!" << endl;
    cout << "I am " << age << " years old." << endl;

    return 0; // Exit status of the program
}
