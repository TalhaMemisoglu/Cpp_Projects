#include <iostream>
#include <ios>
#include <iomanip>

int *insert(int *numbers, int arraySize, int newNumber)
{
    int *newNumbers = new int[arraySize + 1];
    int i;
    for(i=0; i<arraySize; i++)
    {
        newNumbers[i] = numbers[i];
    }
    newNumbers[i] = newNumber;
    
    delete[] numbers;
    return newNumbers;
}

int *sorting(int *numbers, int arraySize)
{
    int temp;

    for(int i=0; i<arraySize-1; i++)
    {
        for(int j=0; j<arraySize-1-i; j++)
        {
            if(numbers[j] > numbers[j+1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    
    return numbers;
}

int searchInsert(int *numbers, int arraySize, int target)
{
    int index{0};
    if(target < numbers[0]) return 0;
    for(int i=0; i<arraySize; i++)
    {
        if(target == numbers[i]){
            break;
        }
        else if(target> numbers[i] && target<numbers[i+1]){
            index++;
            break;
        }
        index++;
    }

    return index;
}

int main()
{
    int *numbers = new int;
    int newNumber,count{0};
    std::cout << "Enter your numbers(Type '-1' to stop): " << std::endl;
    while(1)
    {
        std::cout << ">";
        std::cin >> newNumber;
        if(newNumber == -1){
            break;
        }
        else{
            numbers = insert(numbers,count,newNumber);
            count++;
        }
    }
    numbers = sorting(numbers, count);

    std::cout << "---------";
    for(int i=0; i<count; i++) std::cout << "---";
    std::cout << std::endl;
    std::cout << "Index:   ";
    std::cout << std::right;
    for(int i=0; i<count; i++) std::cout << std::setw(3) << i;
    std::cout << std::endl;
    std::cout << "Numbers: ";
    for(int i=0; i<count; i++) std::cout << std::setw(3) <<numbers[i];
    std::cout << std::endl;
    std::cout << "---------";
    for(int i=0; i<count; i++) std::cout << "---";
    std::cout << std::endl;
    
    int target;
    std::cout << "Enter your target: " << std::endl;
    std::cout << ">";
    std::cin >> target;
    std::cout << "Target: " << target << std::endl;
    std::cout << "---------";
    for(int i=0; i<count; i++) std::cout << "---";
    std::cout << std::endl;
    std::cout << "Output: " << searchInsert(numbers, count, target) << std::endl; 
    
    return 0;
}