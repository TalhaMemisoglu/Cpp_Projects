#include <iostream>
using namespace std;

void writeVertical(int n);

int main()
{
    cout << "writeVertical(3):" << endl;
    writeVertical(3);

    cout << "writeVertical(12):" << endl;
    writeVertical(12);

    cout << "writeVertical(123):" << endl;
    writeVertical(123);

    return 0;
}

void writeVertical(int n)
{
    if(n < 10)
        cout << n << endl;
    else{
        writeVertical(n / 10);
        cout << (n % 10) << endl;
    }
}