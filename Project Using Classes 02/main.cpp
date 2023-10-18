#include <iostream>
using namespace std;

class Temperature
{
    public:
        void set(double newDegrees, char newScale); 
        double degrees;
        char scale;
};

void Temperature::set(double newDegrees, char newScale)
{
    degrees = newDegrees;
    scale = newScale;
}

int main()
{
    Temperature newTemp;
    double newDegrees;
    char newScale;
    cout << "Enter new degrees: ";
    cin >> newDegrees;
    cout << "Enter new scale: ";
    cin >> newScale;
    newTemp.set(newDegrees, newScale);
    cout << newTemp.degrees;
    cout << newTemp.scale;
    return 0;
}