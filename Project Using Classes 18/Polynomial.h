#ifndef POLYNOMİAL_H
#define POLYNOMİAL_H

#include <iostream>
#include <cstdlib>
#include <iostream>
using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int newDegree);
    Polynomial(const Polynomial& polyObject);
    void setPolynomial();
    int getDegree();
    Polynomial& operator=(const Polynomial& rightSide);
    double& operator[](int index);
    friend const Polynomial operator+(const Polynomial& object1, const Polynomial& object2);
    friend const Polynomial operator+(const Polynomial& object, const double& constant);
    friend const Polynomial operator+(const double& constant, const Polynomial& object);
    friend const Polynomial operator-(const Polynomial& object1, const Polynomial& object2);
    friend const Polynomial operator-(const Polynomial& object, const double& constant);
    friend const Polynomial operator-(const double& constant, const Polynomial& object);
    friend const Polynomial operator*(const Polynomial& object1, const Polynomial& object2);
    friend const Polynomial operator*(const Polynomial& object, const double& constant);
    friend const Polynomial operator*(const double& constant, const Polynomial& object);
    friend ostream& operator<<(ostream& outputStream, const Polynomial& object);
    ~Polynomial();
private:
    double *polynomial;
    int degree;
};

#endif