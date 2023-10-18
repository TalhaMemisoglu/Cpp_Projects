#include <iostream>
#define NUMROWS 5

int *generate(int *nums, int size, int numrows)
{
    int *newnums = new int[size+1];
    newnums[0] = 1;
    for(int i=0; i<size-1; i++)
    {
        newnums[i+1] = nums[i] + nums[i+1];
    }
    newnums[size] = 1;

    if(size == numrows-1) return newnums;
    else return generate(newnums,size+1,numrows);
}

int main()
{
    int *nums = new int[2];
    nums[0] = 1, nums[1] = 1;

    int *newnums = generate(nums,2,NUMROWS);
    for(int i = 0; i<NUMROWS; i++)
    {
        std::cout << newnums[i] << std::endl;  
    }
    return 0;
}