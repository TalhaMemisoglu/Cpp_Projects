#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Rational{
public:
    Rational();
    Rational(int wholeNumber);
    Rational(int numeratorValue, int denominatorValue);
    friend bool operator==(const Rational& value1, const Rational& value2);
    friend bool operator<(const Rational& value1, const Rational& value2);
    friend bool operator<=(const Rational& value1, const Rational& value2);
    friend bool operator>(const Rational& value1, const Rational& value2);
    friend bool operator>=(const Rational& value1, const Rational& value2);
    friend const Rational operator+(const Rational& value1, const Rational& value2);
    friend const Rational operator-(const Rational& value1, const Rational& value2);
    friend const Rational operator*(const Rational& value1, const Rational& value2);
    friend const Rational operator/(const Rational& value1, const Rational& value2);
    friend ostream& operator<<(ostream& outputStream, const Rational& value);
    friend istream& operator>>(istream& outputStream, Rational& value);
private:
    int numerator;
    int denominator;
    void normalizeValues();
};

int main()
{
    Rational value1, value2;
    cout << "Enter your first rational number:\n>";
    cin >> value1;
    cout << "Enter your second rational number:\n>";
    cin >> value2;
    cout << value1 << " + " << value2 << " = " << value1 + value2 << endl;
    cout << value1 << " - " << value2 << " = " << value1 - value2 << endl;
    cout << value1 << " / " << value2 << " = " << value1 / value2 << endl;
    cout << value1 << " * " << value2 << " = " << value1 * value2 << endl;
    if(value1 == value2)
        cout << value1 << " is equal to " << value2 << endl;
    else if(value1 < value2) 
        cout << value1 << " is smaller than " << value2 << endl;
    else if(value1 > value2){
        cout << value1 << " is bigger than " << value2 << endl;
    }

    return 0;
}

bool operator==(const Rational& value1, const Rational& value2)
{
    bool status;
    if((value1.numerator * value2.denominator) == (value1.denominator * value2.numerator))    
    {
        status = 1;
    }
    else{
        status = 0;
    }

    return status;
}

bool operator<(const Rational& value1, const Rational& value2)
{
    if((value1.numerator * value2.denominator) < (value2.numerator * value1.denominator))
        return 1;
    else
        return 0;
}

bool operator<=(const Rational& value1, const Rational& value2)
{
    if((value1.numerator * value2.denominator) <= (value2.numerator * value1.denominator))
        return 1;
    else
        return 0;
}

bool operator>(const Rational& value1, const Rational& value2)
{
    if((value1.numerator * value2.denominator) > (value2.numerator * value1.denominator))
        return 1;
    else
        return 0;
}

bool operator>=(const Rational& value1, const Rational& value2)
{
    if((value1.numerator * value2.denominator) >= (value2.numerator * value1.denominator))
        return 1;
    else
        return 0;
}

const Rational operator+(const Rational& value1, const Rational& value2)
{
    int finalNumerator, finalDenominator;
    finalNumerator = (value1.numerator*value2.denominator) + (value2.numerator*value1.denominator);
    finalDenominator = (value1.denominator * value2.denominator);

    return Rational(finalNumerator,finalDenominator);
}

const Rational operator-(const Rational& value1, const Rational& value2)
{
    int finalNumerator, finalDenominator;
    finalNumerator = (value1.numerator*value2.denominator) - (value2.numerator*value1.denominator);
    finalDenominator = (value1.denominator * value2.denominator);

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator*(const Rational& value1, const Rational& value2)
{
    int finalNumerator, finalDenominator;
    finalNumerator = (value1.numerator*value2.numerator);
    finalDenominator = (value2.denominator*value2.denominator);

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator/(const Rational& value1, const Rational& value2)
{
    int finalNumerator, finalDenominator;
    finalNumerator = (value1.numerator*value2.denominator);
    finalDenominator = (value2.denominator*value2.numerator);

    return Rational(finalNumerator, finalDenominator);
}

ostream& operator<<(ostream& outputStream, const Rational& value)
{
    outputStream << value.numerator << '/' << value.denominator;
    return outputStream;
}

istream& operator>>(istream& inputStream, Rational& value)
{
    char fractionSign;
    int numeratorValue, denominatorValue;
    inputStream >> numeratorValue;
    inputStream >> fractionSign;
    if(fractionSign != '/'){
        cout << "No fraction sign in your input";
        exit(1);
    }
    inputStream >> denominatorValue;
    value = Rational(numeratorValue, denominatorValue);

    return inputStream;
}

void Rational::normalizeValues()
{
    int absNumerator = abs(numerator);
    int absDenominator = abs(denominator);

    for(int i=2; (i<=absNumerator && i<=absDenominator); i++)
    {
        if((absNumerator%i) == 0 && (absDenominator%i) == 0)
        {
            absNumerator /= 2;
            absDenominator /= 2;
            numerator /= 2;
            denominator /= 2;
        }
    }

    if(numerator < 0 && denominator < 0){
        numerator = absNumerator;
        denominator = absDenominator;
    }
    else if(numerator > 0 && denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }
}

Rational::Rational() : numerator(0), denominator(1)
{/*Intentionally left blank*/}

Rational::Rational(int wholeNumber)
{
    if(wholeNumber != 0)
    {
        numerator = wholeNumber;
        denominator = 1;
    }
    else
    {
        cout << "Non legite number!";
        exit(1);
    }
}

Rational::Rational(int numeratorValue, int denominatorValue)
{
    if(denominatorValue != 0){
        numerator = numeratorValue;
        denominator = denominatorValue;
        normalizeValues();
    }
    else{
        cout << "Non legite number!";
        exit(1);
    }
}