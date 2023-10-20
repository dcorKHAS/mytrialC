#include<iostream>
using namespace std;

int main1() {
    // Variable declarations
    int integerVar = 10;
    double doubleVar = 20.5;
    char charVar = 'A';

    // Basic operations
    int sum = integerVar + 5;
    double product = doubleVar * 2;
    bool isGreater = integerVar > 5;

    // Printing the results
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    cout << "Is integerVar > 5? " << isGreater << endl;

    return 0;
}


int main() {
    int number = 15;

    // If-else control structure
    if (number < 10) {
        cout << "The number is less than 10." << endl;
    }
    else if (number == 10) {
        cout << "The number is equal to 10." << endl;
    }
    else {
        cout << "The number is greater than or equal to 10." << endl;
    }

    // For loop
    int i;
    for (i = 0; i < 5; i++) {
        cout << "Loop iteration: " << i << endl;
    }

    cout << "Value of i after the loop: " << i << endl;

    // While loop
    int counter = 5;
    int outerCounter = 3;
    
        while (counter > 0) {
           
            counter--;

            if (counter == 2) {
                break; //  
            }
            
            cout << "Counter value: " << counter << endl;
            

            

        }
    	
    return 0;

    //do-while loop

    counter = 3;
    do {
		cout << "Counter value: " << counter << endl;
		counter--;
	} while (counter > 0);
}
