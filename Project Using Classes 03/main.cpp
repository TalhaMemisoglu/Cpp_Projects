#include <iostream>
using namespace std;

class Point
{
    public:
        void set(int newX, int newY);
        void moveThePoint(int toX, int toY);
        void rotateBy90degrees();
        int getX();
        int getY();
    private:
        int x;
        int y;
};

void Point::set(int newX, int newY)
{
    x = newX;
    y = newY;
}

void Point::moveThePoint(int toX, int toY)
{
    x += toX;
    y += toY;
}

void Point::rotateBy90degrees()
{
    int temp;
    if(x != 0)
    {
        if(y != 0){
            if(x>0)
            {
                if(y>0){
                    temp = x;
                    x = y;
                    y = -temp;
                }
                else{
                    temp = x;
                    x = y;
                    y = -temp;
                }
            }
            else{
                if(y>0){
                    temp = x;
                    x = y;
                    y = -temp;
                }
                else{
                    temp = x;
                    x = y;
                    y = -temp;
                }
            }
        }
        else{
            if(x>0){
                y = -x;
                x = 0;
            }
            else{
                y = x;
                x = 0;
            }
        }
    }
    else{
        if(y != 0){
            if(y>0){
                x = y;
                y = 0;
            }
            else{
                x = y;
                y = 0;
            }
        }
    }
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

int main()
{
    Point location;
    int x,y,menu;
    cout << "Enter the location of plane (x y): ";
    cin >> x >> y;
    location.set(x,y);
    cout << "Type the number you would like to:\n";
    cout << "1-Move the point(x y)\n";
    cout << "2-Rotate the point by 90 degrees clockwise around the origin.\n";
    cout << ">";
    cin >> menu;

    switch (menu)
    {
    case 1:
        int toX, toY;
        cout << "Enter x:\n";
        cout <<">";
        cin >> toX;
        cout << "Enter y:\n";
        cout << ">";
        cin >> toY;
        location.moveThePoint(toX, toY);
        cout << location.getX() << endl;
        cout << location.getY() << endl;
        break;
    case 2:
        location.rotateBy90degrees();
        cout << location.getX() << endl;
        cout << location.getY() << endl;
        break;
    default:
        break;
    }

    return 0;
}