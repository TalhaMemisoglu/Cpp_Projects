#include <iostream>
#include <cstdlib>
using namespace std;

class PrimeNumber{
public:
    PrimeNumber();
    PrimeNumber(int value);
    void setPrimeNumber(int value);
    int getPrimeNumber() const;
    PrimeNumber operator++();
    PrimeNumber operator++(int);
    PrimeNumber operator--();
    PrimeNumber operator--(int);
private:
    int primeNumber;
    bool isPrimeNumber(int value) const;
};

int main()
{
    PrimeNumber a(19);
    cout << "Postfix a++: Start value of object a: ";
    cout << a.getPrimeNumber() << endl;
    PrimeNumber b = a++;
    cout << "Value returned: ";
    cout << b.getPrimeNumber() << endl;
    cout << "Changed object: ";
    cout << a.getPrimeNumber() << endl;

    a = PrimeNumber(19);
    cout << "Prefix ++a: Start value of object a: ";
    cout << a.getPrimeNumber() << endl;
    PrimeNumber c = ++a;
    cout << "Value returned: ";
    cout << c.getPrimeNumber() << endl;
    cout << "Changed object: ";
    cout << a.getPrimeNumber() << endl << endl;

    a = PrimeNumber(19);
    cout << "Postfix a--: Start value of object a: ";
    cout << a.getPrimeNumber() << endl;
    PrimeNumber d = a--;
    cout << "Value returned: ";
    cout << d.getPrimeNumber() << endl;
    cout << "Changed object: ";
    cout << a.getPrimeNumber() << endl;    

    a = PrimeNumber(19);
    cout << "Prefix --a: Start value of object a: ";
    cout << a.getPrimeNumber() << endl;
    PrimeNumber e = --a;
    cout << "Value returned: ";
    cout << e.getPrimeNumber() << endl;
    cout << "Changed object: ";
    cout << a.getPrimeNumber() << endl;  

    return 0;
}

PrimeNumber::PrimeNumber() : primeNumber(2)
{/*Intentionally left blank*/}

PrimeNumber::PrimeNumber(int value)
{
    if(!isPrimeNumber(value)){
        cout << "Number you entered is not prime number." << endl;
        exit(1);
    }

    primeNumber = value;
}

void PrimeNumber::setPrimeNumber(int value)
{
    if(!isPrimeNumber(value)){
        cout << "Number you entered is not prime number." << endl;
        exit(1);
    }
    
    primeNumber = value;
}

int PrimeNumber::getPrimeNumber() const
{
    return primeNumber;
}

bool PrimeNumber::isPrimeNumber(int value) const
{
    bool isPrime = true;
    for(int i = 2; i<value; i++)
    {
        if((value%i) == 0)
            isPrime = false;
    }

    return isPrime;
}

PrimeNumber PrimeNumber::operator++()
{
    while(true)
    {
        if(isPrimeNumber(++primeNumber)){
            return PrimeNumber(primeNumber);
        }
    }
}

PrimeNumber PrimeNumber::operator++(int)
{
    int temp = primeNumber;
    while(true)
    {
        if(isPrimeNumber(++primeNumber)){
            return PrimeNumber(temp);
        }
    }
}

PrimeNumber PrimeNumber::operator--()
{
    while(true)
    {
        if(isPrimeNumber(--primeNumber)){
            return PrimeNumber(primeNumber);
        }
    } 
}

PrimeNumber PrimeNumber::operator--(int)
{
    int temp = primeNumber;
    while(true)
    {
        if(isPrimeNumber(--primeNumber)){
            return PrimeNumber(temp);
        }
    }
}