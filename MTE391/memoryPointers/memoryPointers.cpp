#include<iostream>
using namespace std;

int main() {
    // Stack memory allocation
    int stackVar = 10;

    // Heap (dynamic) memory allocation
    int* heapVar = new int;
    *heapVar = 20;

    cout << "Stack Variable: " << stackVar << endl;
    cout << "Heap Variable: " << *heapVar << endl;

    // Releasing the heap memory
    delete heapVar;

    return 0;
}


void modifyValue(int& ref, int* ptr) {
    ref = ref + 5;
    *ptr = *ptr + 5;
}

int main2() {
    int normalVar = 10;
    int& referenceVar = normalVar; // Reference to the variable
    int* pointerVar = &normalVar; // Pointer to the variable

    modifyValue(referenceVar, pointerVar);

    cout << "Normal Variable: " << normalVar << endl;
    cout << "Reference Variable: " << referenceVar << endl;
    cout << "Pointer Variable Value: " << *pointerVar << endl;

    return 0;
}
