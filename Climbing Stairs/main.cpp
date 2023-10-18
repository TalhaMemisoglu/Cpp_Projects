#include <iostream>

int climbStairs(int n)
{
    if(n<=1){
        return 1;
    }
    return climbStairs(n-1)+climbStairs(n-2);
}

int main()
{
    int n = 6;
    std::cout << "Output: " << climbStairs(n);
    return 0;
}