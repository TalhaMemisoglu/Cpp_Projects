#include <iostream>
using namespace std;

double power(int x, int n);

int main()
{
    for (int n = 0; n < 4; n++)
    {
        cout << "3 to the power " << n
            << " is " << power(3, n) << endl;
    }

    for (int n = -1; n > -5; n--)
    {
        cout << "3 to the power " << n
            << " is " << power(3, n) << endl;
    }

    return 0;
}

double power(int x, int n)
{
    if(n < 0 && x==0)
    {
        cout << "Illegal argument to power.\n";
        exit(1);
    }
    
    if (n < 0)
    {
        return (1 / power(x,-n));
    }
    if (n > 0){
        return ( power(x, n - 1) * x );
    }
    else{ // n == 0
        return (1);
    }
}