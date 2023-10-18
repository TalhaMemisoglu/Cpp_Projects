#include <iostream>

void twoSum(int nums[], int target);

int main()
{
    int nums[] {3,3};
    int target {6};
    twoSum(nums,target);
}

void twoSum(int array[], int target)
{
    int count = sizeof(array) / sizeof(array[0]);
    
    for(int i=0; i <= count; i++)
    {
        for(int j = i+1; j <= count; j++)
        {
            if((array[i] + array[j]) == target )
            {
                std::cout << "[" << i << ", " << j << "]" << std::endl;
            }
        }
    }
}