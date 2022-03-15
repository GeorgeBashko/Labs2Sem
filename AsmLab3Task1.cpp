#include <iostream>
#include<iomanip>
int main()
{
    int num = 0;
    while (num <= 0)
    {
        std::cout << "Enter a number: ";
        std::cin >> num;
    }
    long long rezCpp = 0;
    unsigned int rezAsm = 0;
    __asm
    {
            mov eax, num
            mov ecx, 11
            beg1:
            mul num
            loop beg1
            mov ebx,eax
            mov eax,num
            mov ecx, 7
            beg2:
            mul num
            loop beg2
            add eax,ebx
            add eax,num
            mov rezAsm,eax
    }
    std::cout << "Result in ASM: " << rezAsm << std::endl;
    rezCpp = pow(num, 12) + pow(num, 8)  +num;
    std::cout << "Result in C++ is: " << rezCpp << std::endl;
    return 0;
}
