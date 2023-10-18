#include <iostream>
#include <string>
using namespace std;

class RainbowColor
{
public:
    RainbowColor() = default;
    RainbowColor(char firstLetter);
    RainbowColor(int colorNum);
    void intInput();
    void charInput();
    void setColor(int colorNum);
    void setColor(char colorChar);
    void IntOutput();
    void NameOutput();
    void nextColor();
private:
    int color;
};

RainbowColor::RainbowColor(char firstLetter)
{
    switch (firstLetter)
    {
    case 'R':
    case 'r':
        color = 1;
        break;
    case 'O':
    case 'o':
        color = 2;
        break;
    case 'Y':
    case 'y':
        color = 3;
    case 'G':
    case 'g':
        color = 4;
    case 'B':
    case 'b':
        color = 5;
    case 'I':
    case 'i':
        color = 6;
    case 'V':
    case 'v':
        color = 7;
    default:
        cout << "Mistyping!";
        break;
    }
}

RainbowColor::RainbowColor(int colorNum)
{
    if(colorNum > 0 && colorNum < 8)
        color = colorNum;
    else
        cout << "Mistyping!";
}

void RainbowColor::intInput()
{
    int colorNum;
    cout << "Please type the number of color:\n"
         << ">";
    cin >> colorNum;
    setColor(colorNum);
}

void RainbowColor::charInput()
{
    char colorChar;
    cout << "Please type first letter of your color:\n"
         << ">";
    cin >> colorChar;
    setColor(colorChar);
}

void RainbowColor::setColor(int colorNum)
{
    if(colorNum > 0 && colorNum < 8)
        color = colorNum;
    else
        cout << "Mistyping!";
}

void RainbowColor::setColor(char colorChar)
{
    switch(colorChar)
    {
        case 'R':
            color = 1;
            break;
        case 'O':
            color = 2;
            break;
        case 'Y':
            color = 3;
            break;
        case 'G':
            color = 4;
            break;
        case 'B':
            color = 5;
            break;
        case 'I':
            color = 6;
            break;
        case 'V':
            color = 7;
            break;
        default:
            cout << "Mistyping!";
    }
}

void RainbowColor::IntOutput()
{
    cout << "Your color as a integer: " << color << endl; 
}

void RainbowColor::NameOutput()
{
    cout << "Name of your color: ";
    switch (color)
    {
        case 1:
            cout << "Red" << endl;
            break;
        case 2:
            cout << "Orange" << endl;
            break;
        case 3:
            cout << "Yellow" << endl;
            break;
        case 4:
            cout << "Green" << endl;
            break;
        case 5:
            cout << "Blue" << endl;
            break;
        case 6:
            cout << "Indigo" << endl;
            break;
        case 7:
            cout << "Violet" << endl;
            break;
        default:
            cout << "Error!" << endl;
            break;
    }
}

void RainbowColor::nextColor()
{
    int nextColor = color + 1;
    cout << "Next color is ";
    switch (color)
    {
        case 2:
            cout << "Orange";
            break;
        case 3:
            cout << "Yellow";
            break;
        case 4:
            cout << "Green";
            break;
        case 5:
            cout << "Blue";
            break;
        case 6:
            cout << "Indigo";
            break;
        case 7:
            cout << "Violet";
            break;
        default:
            cout << "Error!";
            break;
    }
}

int main()
{
    RainbowColor color1, color2, color3(7);
    color1.intInput();
    color1.NameOutput();
    color2.charInput();
    color2.IntOutput();
    color3.NameOutput();
    return 0;
}