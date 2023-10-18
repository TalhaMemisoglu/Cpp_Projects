#include <iostream>

int maxProfit(int *array, int size)
{
    int maxProfit = 0;
    
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if((array[j]-array[i]) > maxProfit){
                maxProfit = array[j]-array[i];
            }
        }
    }

    return maxProfit;
}

int main()
{
    int array[5] {1,2,5,7,2};
    std::cout << maxProfit(array,5) << std::endl;

    return 0;
}