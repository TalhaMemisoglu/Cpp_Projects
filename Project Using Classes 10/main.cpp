#include <iostream>
#include <string>
using namespace std;

class zipCode
{
public:
    zipCode(int& zipCode);
    zipCode(string& zipCode);
    int getZipCodeInt();
    string getZipCodeStr();
private:
    int zipCodeToInt(const string& zipCode);
    string zipCodeToStr(const int& zipCode);
    int ZipCode;
};

zipCode::zipCode(int& zipCode) : ZipCode(zipCode)
{/*Intentionally left blank*/}

zipCode::zipCode(string& zipCode)
{
    ZipCode = zipCodeToInt(zipCode);
}

int zipCode::getZipCodeInt()
{
    return ZipCode;
}

string zipCode::getZipCodeStr()
{
    return zipCodeToStr(ZipCode);
}

int zipCode::zipCodeToInt(const string& zipCode)
{
    int barCode, zipCodeInt = 0, value = 0;
    int count = 10000;
    for(int digit=1; digit<=25; digit++)
    {
        barCode = (digit % 5);
        switch(barCode)
        {
            case 1:
                value += (static_cast<int>(zipCode[digit]) - static_cast<int>('0'))*7;
                break;
            case 2:
                value += (static_cast<int>(zipCode[digit]) - static_cast<int>('0'))*4;
                break;
            case 3:
                value += (static_cast<int>(zipCode[digit]) - static_cast<int>('0'))*2;
                break;
            case 4:
                value += (static_cast<int>(zipCode[digit]) - static_cast<int>('0'))*1;
                break;
            case 0:
                value += (static_cast<int>(zipCode[digit]) - static_cast<int>('0'))*0;
                break;
            default:
                cout << "Error01" << endl;
        }
        if(barCode == 0){
            if(value == 11) value = 0;
            zipCodeInt += value*count;
            count /= 10;
            value = 0;
        }
    }
    
    return zipCodeInt;                
}

string zipCode::zipCodeToStr(const int& zipCode)
{
    string zipCodeStr = "1";
    int digitCounter = 10000;
    int value;

    for(int i=0; i < 5; i++)
    {
        value = static_cast<int>(zipCode/digitCounter);
        switch (value)
        {
        case 1:
            zipCodeStr += "00011";
            break;
        case 2:
            zipCodeStr += "00101";
            break;
        case 3:
            zipCodeStr += "00110";
            break;
        case 4:
            zipCodeStr += "01001";
            break;
        case 5:
            zipCodeStr += "01010";
            break;
        case 6:
            zipCodeStr += "01100";
            break;
        case 7:
            zipCodeStr += "10001";
            break;
        case 8:
            zipCodeStr += "10010";
            break;
        case 9:
            zipCodeStr += "10100";
            break;
        case 0:
            zipCodeStr += "11000";
            break;
        default:
            cout << "Error02" << endl;
            break;
        }
    }
    zipCodeStr += "1";

    return zipCodeStr;
}

int main()
{
    int menu;
    string zipCodeStr;
    int zipCodeInt;
    cout << "1.Bar code to zip code\n"
         << "2.Zip Code to bar code\n"
         << "Type menu you would like to:\n>";
    cin >> menu;
    
    if(menu == 1){
        cout << "Enter your bar code:\n>";
        cin >> zipCodeStr;
        zipCode code1(zipCodeStr);
        cout << "Your Zip Code: " << code1.getZipCodeInt();
    }
    else if(menu == 2){
        cout << "Enter your zip Code:";
        cin >> zipCodeInt;
        zipCode code2(zipCodeInt);
        cout << "Your bar code : " << code2.getZipCodeStr();
    }
    else{
        cout << "Mistyping!";
    }
    
    return 0;
}