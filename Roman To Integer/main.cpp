#include <iostream>

int romanToInt(char *s);

int main()
{
    char s[] {"CCCXCII"};
    std::cout << "Output: " << romanToInt(s) << std::endl;

    return 0;
}

int romanToInt(char *s)
{
    int num = 0;
    for(int i=0; s[i] != '\0'; i++)
    {
        switch(s[i])
        {
            case 'I':
                if(s[i+1] == 'V'){
                    num += 4;
                    i++;
                }
                else if(s[i+1] == 'X')
                {
                    num += 9;
                    i++;
                }
                else num++;
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                if(s[i+1] == 'L'){
                    num += 40;
                    i++;
                }
                else if(s[i+1] == 'C'){
                    num += 90;
                    i++;
                }
                else num += 10;
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                if(s[i+1] == 'D'){
                    num += 400;
                    i++;
                }
                else if(s[i+1] == 'M'){
                    num += 900;
                    i++;
                }
                else num += 100;
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            default:
                std::cout << "Wrong Typing." << std::endl;
        }
    }

    return num;
}