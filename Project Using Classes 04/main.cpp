#include <iostream>
using namespace std;

class Weight{
    public:
        void setWeightPounds(double pounds);
        void setWeightKilograms(double kilogram);
        void setWeightOunces(double ounces);
        double getWeightPounds();
    private:
        double weight;
};

void Weight::setWeightPounds(double pounds)
{
    weight = pounds;
}

void Weight::setWeightKilograms(double kilogram)
{
    weight = kilogram*(2.21);
}

void Weight::setWeightOunces(double ounces)
{
    weight = ounces / 16;
}

double Weight::getWeightPounds()
{
    return weight;
}

int main()
{
    int menu,weight;
    cout << "Choose the weight scale:\n";
    cout << "1-Pounds\n";
    cout << "2-Kilogram\n";
    cout << "3-Ounces\n>";
    cin >> menu;
    cout << "Enter the weight:";
    cin >> weight;

    Weight cWeight;
    switch(menu)
    {
        case 1:
            cout << "Enter the weight:";
            cin >> weight;    
            cWeight.setWeightPounds(weight);
            cout << cWeight.getWeightPounds() << " Pounds";
            break;
        case 2:
            cout << "Enter the weight:";
            cin >> weight;   
            cWeight.setWeightKilograms(weight);
            cout << cWeight.getWeightPounds() << " Pounds";
            break;
        case 3:
            cout << "Enter the weight:";
            cin >> weight;   
            cWeight.setWeightOunces(weight);
            cout << cWeight.getWeightPounds() << " Pounds";
        default:
            cout << "ERROR";
            break;
    }

    return 0;
}