#include <iostream>
#include <cstdlib>
using namespace std;

int totalPinsInPyramid(int row);

int main()
{
    int row;
    cout << "Please input the number of rows you'd like to print: ";
    cin >> row;
    cout << totalPinsInPyramid(row);

    return 0;
}

int totalPinsInPyramid(int row)
{
    if(row < 0)
    {
        cout << "Wrong Input!" << endl;
        exit(-1);
    }
    else
    {
        if(row == 0)
        {
            return 0;
        }
        else
        {
            return totalPinsInPyramid(row-1) + row;
        }
    }
}