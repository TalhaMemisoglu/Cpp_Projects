#include <iostream>
using namespace std;

void reverseOrder(string& a, int bound1, int bound2);
void reverseString(string& str);

int main()
{
    string a("ABCDE");
    /*
    for(char c: a) cout << c;
    cout << endl;
    reverseOrder(a, 1, 4);
    for(char c: a) cout << c;
    cout << endl;
    */
    reverseString(a);
    for(char c: a) cout << c;

    return 0;
}

void reverseOrder(string& a, int bound1, int bound2)
{
    if(bound1 < bound2)
    {
        char temp;
        temp = a[bound1];
        a[bound1] = a[bound2];
        a[bound2] = temp;
        reverseOrder(a, bound1 + 1, bound2 - 1);
    }
}

void reverseString(string& str)
{
    reverseOrder(str, 0, str.size()-1);
}