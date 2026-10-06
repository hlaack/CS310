#include <iostream>
using namespace std;

int addNumbers(int x, int y);

int main()
{
    int num1 = 5;
    int num2 = 10;

    int result = addNumbers(num1, num2);

    cout << "The sum is: " << result << endl;

    return 0;
}

int addNumbers(int x, int y)
{
    cout << "Adding the numbers..." << endl;

    return x + y;
}
