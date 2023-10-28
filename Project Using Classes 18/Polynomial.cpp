#include <iostream>
#include <cstdlib>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial() : degree(0)
{
    polynomial = new double[1];
    polynomial[0] = 0;
}

Polynomial::Polynomial(int newDegree) : degree(newDegree)
{
    polynomial = new double[newDegree + 1];
    for(int i=0; i<=newDegree; i++)
        polynomial[i] = 1;
}

Polynomial::Polynomial(const Polynomial& polyObject) : degree(polyObject.degree)
{
    polynomial = new double[degree + 1];
    for(int i=0; i<=degree; i++)
        polynomial[i] = polyObject.polynomial[i];
}

void Polynomial::setPolynomial()
{
    cout << "Enter degree of your polynomial: ";
    cin >> degree;
    
    delete[] polynomial;
    polynomial = new double[degree + 1];

    for(int i=0; i<=degree; i++)
    {
        cout << "Coefficient of " << i << ". term: ";
        cin >> polynomial[i];
    }
}

int Polynomial::getDegree()
{
    return degree;
}

Polynomial& Polynomial::operator=(const Polynomial& rightSide)
{
    if(degree != rightSide.degree)
    {
        delete[] polynomial;
        polynomial = new double[rightSide.degree];
    }

    degree = rightSide.degree;
    for(int i=0; i<=degree; i++)
    {
        polynomial[i] = rightSide.polynomial[i];
    }

    return *this;
}

double& Polynomial::operator[](int index)
{
    if(index > degree)
    {
        cout << "Invalid index!" << endl;
        exit(1);
    }

    return polynomial[index];
}

const Polynomial operator+(const Polynomial& object1, const Polynomial& object2)
{
    Polynomial sum, biggest, smallest;
    if(object1.degree > object2.degree)
    {
        biggest = object1;
        smallest = object2;
    }
    else
    {
        biggest = object2;
        smallest = object1;
    }

    sum.polynomial = new double[biggest.degree + 1];
    sum.degree = biggest.degree;
    for(int i=0; i <= smallest.degree; i++)
    {
        sum.polynomial[i] = biggest.polynomial[i] + smallest.polynomial[i];
    }
    for(int j=smallest.degree + 1; j<= biggest.degree; j++)
    {
        sum.polynomial[j] = biggest.polynomial[j];
    }

    return sum;
}

const Polynomial operator+(const Polynomial& object, const double& constant)
{
    Polynomial sum(object);
    sum[0] += constant; 

    return sum;
}

const Polynomial operator+(const double& constant, const Polynomial& object)
{
    Polynomial sum(object);
    sum[0] += constant; 

    return sum;
}

const Polynomial operator-(const Polynomial& object1, const Polynomial& object2)
{
    Polynomial subt, biggest, smallest;
    if(object1.degree > object2.degree)
    {
        biggest = object1;
        smallest = object2;
    }
    else
    {
        biggest = object2;
        smallest = object1;
    }

    subt.polynomial = new double[biggest.degree + 1];
    subt.degree = biggest.degree;
    for(int i=0; i <= smallest.degree; i++)
    {
        subt.polynomial[i] = object1.polynomial[i] - object2.polynomial[i];
    }
    for(int j=smallest.degree + 1; j<= biggest.degree; j++)
    {
        subt.polynomial[j] = biggest.polynomial[j];
    }

    return subt;
}

const Polynomial operator-(const Polynomial& object, const double& constant)
{
    Polynomial subt(object);
    subt[0] = subt[0] - constant; 

    return subt;
}

const Polynomial operator-(const double& constant, const Polynomial& object)
{
    Polynomial subt(object);
    subt[0] = constant - subt[0]; 

    return subt;
}

const Polynomial operator*(const Polynomial& object1, const Polynomial& object2)
{
    Polynomial mult;
    mult.polynomial = new double[object1.degree + object2.degree + 1];
    mult.degree = object1.degree + object2.degree;
    for(int i=0; i<=object1.degree; i++)
    {
        for(int j=0; j<=object2.degree; j++)
        {
            mult[i + j] = object1.polynomial[i] * object2.polynomial[j];
        }
    }

    return mult;
}

const Polynomial operator*(const Polynomial& object, const double& constant)
{
    Polynomial mult(object);
    for(int i=0; i<=object.degree; i++)
    {
        mult.polynomial[i] = mult.polynomial[i] * constant;
    }

    return mult;
}

const Polynomial operator*(const double& constant, const Polynomial& object)
{
    Polynomial mult(object);
    for(int i=0; i<=object.degree; i++)
    {
        mult.polynomial[i] = mult.polynomial[i] * constant;
    }

    return mult;
}

ostream& operator<<(ostream& outputStream, const Polynomial& object)
{
    for(int i=object.degree; i>=0; i--)
    {
        if(object.polynomial[i] != 0)
        {
            if(object.polynomial[i] > 0)
            {
                outputStream << "+";
            }
            outputStream << object.polynomial[i];
            for(int j=0; j<i; j++)
            {
                outputStream << "*x";
            } 
        }
    }

    return outputStream;
}

Polynomial::~Polynomial()
{
    delete[] polynomial;
}