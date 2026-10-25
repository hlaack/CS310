#include <iostream>
using namespace std;

int main()
{
    int scores[2][3] = {
        {85, 90, 95},
        {78, 88, 92}
    };

    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << scores[row][col] << endl;
        }
    }

    cout << scores[1][2] << endl;

    return 0;
}
