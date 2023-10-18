#include <iostream>

void longestCommonPrefix(char str[][10], char common[]);

int main()
{
    char str[][10] = {"flower","flow","flight"};
    char common[10];
    longestCommonPrefix(str,common);
    return 0;
}

void longestCommonPrefix(char str[][10], char common[])
{
    for(int i=0; str[i] != NULL; i++)
    {
        std::cout << str[i];
    }

}