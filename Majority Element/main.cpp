#include <iostream>

int majorityElement(int *nums, int size)
{
    int count, majorElement = 0, numsOfMajorElement = 0;
    for(int i=0; i<size; i++)
    {
        count = 0;
        for(int j=0; j<size; j++)
        {
            if(nums[i] == nums[j]){
                count++;
            }
        }
        if( count > numsOfMajorElement){
            numsOfMajorElement = count;
            majorElement = nums[i];
        }
    }

    return majorElement;
}

int main()
{
    int nums[] {3,1,3,3,2,2,3,2,1};
    std::cout << "Output: " << majorityElement(nums,9) << std::endl;
    
    return 0;
}