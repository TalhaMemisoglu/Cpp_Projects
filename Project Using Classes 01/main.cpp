#include <iostream>
using namespace std;

class DayOfYear{
    public:
        void input();
        void output();
        int month;
        int day;
};

void DayOfYear::input()
{
    cout << "Enter month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
}

void DayOfYear::output()
{
    switch (month)
    {
        case 1:
            cout << "January "; break;
        case 2:
            cout << "February "; break;
        case 3:
            cout << "March "; break;
        case 4:
            cout << "April "; break;
        case 5:
            cout << "May "; break;
        case 6:
            cout << "June "; break;
        case 7:
            cout << "July "; break;
        case 8:
            cout << "August "; break;
        case 9:
            cout << "September "; break;
        case 10:
            cout << "October "; break;
        case 11:
            cout << "November "; break;
        case 12:
            cout << "December "; break;
        default:
            cout << "Error in DayOfYear::output.";
    }

    cout << day;
}


int main()
{
    DayOfYear today, birthday;
    cout << "****Today's date****\n";
    today.input();
    cout << "****Birthday****\n";
    birthday.input();
    cout << "Your birthday is: ";
    birthday.output();
    cout << endl;

    if(today.month == birthday.month && today.day == birthday.day)
        cout << "Happy Birthday!\n";
    else
        cout << "Happy Unbirthday!\n";

return 0;
}