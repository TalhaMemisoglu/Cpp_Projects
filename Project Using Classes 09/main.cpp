#include <iostream>
#include <cstdlib>
using namespace std;

class Counter
{
public:
    Counter();
    Counter(int counterNum);
    void input();
    void setCounter(int Dollars, int Cents);
    void reset();
    void incr1();
    void incr10();
    void incr100();
    void incr1000();
    bool overflow();
    double getAmount();
private:
    int accountCents;
    int accountDollars;
    int maxAccuntCents;
    int maxAccountDollars;
};

Counter::Counter()
{
    accountCents = 0, accountDollars = 0;
    maxAccountDollars = 0, maxAccuntCents = 0;
}

Counter::Counter(int counterNum)
{   
    accountCents = 0, accountDollars = 0;

    maxAccuntCents = counterNum % 100;
    maxAccountDollars= static_cast<int>(counterNum/100) - static_cast<int>(0);
}

void Counter::reset()
{    
    accountCents = 0, accountDollars = 0;
}

void Counter::incr1()
{
    accountCents += 1;
}

void Counter::incr10()
{
    accountCents += 10;
}

void Counter::incr100()
{
    accountDollars += 1;
}

void Counter::incr1000()
{
    accountDollars += 10;
}

bool Counter::overflow()
{
    bool status;
    int currentValue = accountDollars*100 + accountCents;
    int maxValue = maxAccountDollars*100 + maxAccuntCents;

    if(currentValue <= maxValue)
        status = false;
    else
        status = true;

return status;
}

double Counter::getAmount()
{
    return accountDollars + accountCents*0.01;
}

void Counter::input()
{
    int dollars,cents;
    char point; 
    cout <<  "Type number to set counter's number(ex:$8.12):\n>$";
    cin >> dollars >> point >> cents;
    setCounter(dollars, cents);
}

void Counter::setCounter(int Dollars, int Cents)
{ 
    maxAccountDollars = Dollars, maxAccuntCents = Cents;
}

int main()
{
    Counter counter1;
    counter1.input();

    char command;
    while(true)
    {
        cout << "Enter a command:\n>";
        cin >> command;
        switch(command)
        {
            case 'a':
                counter1.incr1();
                break;
            case 's':
                counter1.incr10();
                break;
            case 'd':
                counter1.incr100();
                break;
            case 'f':
                counter1.incr1000();
                break;
            case 'q':
                break;
            default:
                cout << "Mistyping!" << endl;
        }

        if(command == 'q' || counter1.overflow()) break;
    }

    if(command == 'q') 
        cout << "Program terminated your total amount is "
             << counter1.getAmount();
    else if(counter1.overflow())
        cout << "Overflow! Your total amount is " << counter1.getAmount();

return 0;
}