#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
    Polynomial polynomial1, polynomial2, sum, subt;
    polynomial1.setPolynomial();
    polynomial2.setPolynomial();
    
    cout << "Summation: " << polynomial1 + polynomial2 << endl;
    cout << "Subtraction: " << polynomial1 - polynomial2  << endl;
    cout << "Multiplication: " << polynomial1 * polynomial2 << endl;
    
    return 0;
}