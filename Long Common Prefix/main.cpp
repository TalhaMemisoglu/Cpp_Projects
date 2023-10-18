#include <iostream>

void longCommonPrefix(char strings[][10],int size);

int main()
{
    char strings[][10] {"flow","flo","flower"};
    //char strings[][10] {"dog","racecar","car"};
    int size = sizeof(strings)/sizeof(strings[0]);
    longCommonPrefix(strings,size);

    return 0;
}

void longCommonPrefix(char strings[][10], int size)
{
    char common[10];
    common[0] = ' ';
    common[1] = '\0';
    int flag;

    for(int i=0; strings[0][i] != '\0'; i++)
    {
        flag = 1;
        for(int j=1; j<size; j++)
        {
            if(strings[0][i] != strings[j][i])
            {
                flag = 0;
            }
        }
        if(flag == 1){
            common[i] = strings[0][i];
        }
    }
    
    std::cout << "'" << common << "'" << std::endl;
}