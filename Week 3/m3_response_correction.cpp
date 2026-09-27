#include <iostream>
// Emily Capodarco
// Week 3 Discusion
// 9/24/26

// Harry's Discussion Corrections
using namespace std;

int main() {
    int value;

    cout << "Enter a number: ";
    cin >> value;

    // Selection control statement
    if (value > 10) 
        cout << "Value is greater than 10!" << endl;
    else 
        cout << "Value is 10 or less!" << endl;
  
    if (value < 5) {
        cout << "This will never run." << endl;
    }

    cout << "Another message" << endl;

    return 0;
}
