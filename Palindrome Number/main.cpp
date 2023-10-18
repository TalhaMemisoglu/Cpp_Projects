#include <iostream>
#include <cmath>

bool isPalindrome(int x);
int numberDigit(int x);

int main()
{
    int x;
    std::cout << "Please Enter the number: ";
    std::cin >> x;
    std::cout << std::boolalpha << "Output: " << isPalindrome(x) << std::endl;

    return 0;
}

bool isPalindrome(int x)
{
    if(x < 0) return false;
    
    int digit = numberDigit(x);
    int num = x;
    int revNum = 0;

    while(digit>0)
    {
        revNum += (x%10)*pow(10,digit-1);
        x = floor(x/10);
        digit--;
    }

    if(num == revNum) return true; else return false;
}

int numberDigit(int x)
{
    return floor(std::log10(x)) + 1;
}