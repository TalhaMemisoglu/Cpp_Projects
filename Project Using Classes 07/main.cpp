#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    cout << "Enter a list of positive numbers.\n"
         << "Place a negative number at the end.\n";

    int next;
    cout << ">";
    cin >> next;
    while(next > 0)
    {
        v.push_back(next);
        cout << next << " added." << endl;
        cout << ">";
        cin >> next;
    }

    cout << "You entered:\n";
    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.resize(2); //if you want to set iniatialy, use v.reserve()
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    vector<int> x;
    x = v;
    cout << x.size() << endl;

    return 0;
}