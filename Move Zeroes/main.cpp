#include <iostream>

void moveZereos(int *array, int size)
{
    int temp;
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(array[j] == 0)
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

}


int main()
{
    int array[] {1,2,0,4,0,5,6,9,10,-5};
    int size = sizeof(array) / sizeof(array[0]);
    moveZereos(array,size);
    std::cout << "Output: [";
    for(int i=0; i<size-1; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << array[size-1] << "]";
    return 0;
}