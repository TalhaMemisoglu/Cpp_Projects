#include <iostream>

bool isValid(char *s);

int main()
{
    char s[] {"(]"};
    std::cout << "Output: " << std::boolalpha << isValid(s) << std::endl;

    return 0;
}

bool isValid(char *s)
{
    int k;
    for(k=0; s[k] != '\0'; k++){
    }
    int size = k;

    int count = 0;
    for(int i=0; s[i] != '\0'; i++)
    {
        for(int j=i+1; s[j] != '\0'; j++)
        {
            if(s[i] == '{'){
                if(s[j] == '}'){
                    count++;
                    break;
                }
            }
            else if(s[i] == '('){
                if(s[j] == ')'){
                    count++;
                    break;
                }
            }
            else if(s[i] == '['){
                if(s[j] == ']'){
                    count++;
                    break;
                }
            }
            else break;
        }
    }

    bool status;
    if(size % 2 == 1) status = false; else if(size/2 == count) status = true;

    return status;
}