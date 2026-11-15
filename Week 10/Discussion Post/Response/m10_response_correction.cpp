#include <iostream>
using namespace std;

int main()
{
    int number = 25;
    int second_number = 15;
    int* ptr = &number;

    cout << "Original number: " << number << endl;

    ptr = &second_number;

    // Error 2
    *ptr = 50;

    cout << "Updated number: " << second_number << endl;

    return 0;
}
