#include <iostream>
using namespace std;

void writeDown(int num);
void writeUp(int num);

int main()
{
    cout << "calling writeUp(" << 10 << ")\n";
    writeUp(10);
    cout << endl;
    cout << "calling writeDown(" << 10 << ")\n";
    writeDown(10);
    cout << endl;

    return 0;
}

void writeDown(int num)
{
    if(num >= 1)
    {
        cout << num << " ";
        writeDown(num - 1);
    }
}

void writeUp(int num)
{
    if(num >= 1)
    {
        writeUp(num - 1);
        cout << num << " ";
    }
}