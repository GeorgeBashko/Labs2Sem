#include <iostream>
void CppFraction(int a, int b)
{
	int nod1 = 1;
    int min = 0;
	if (a < b)
		min = a;
	else
		min = b;
	for (int i = abs(min); i > 0; i--) {
		if ((abs(a)) % i == 0 && b % i == 0)
		{
			nod1 = i;
			break;
		}
	}
	std::cout << "New fraction in Cpp: " << a / nod1 << '/' << b / nod1 << std::endl;
}
int main()
{
	int num = 0;
	int den = 0;
	int nod= 1;
	std::cout << "Enter numenator: ";
	std::cin >> num;
	while (den <= 0)
	{
		std::cout << "Enter denumenator: ";
		std::cin >> den;
	}
	int num1 = num;
	std::cout << "Your fraction: " << num << '/' << den << std::endl;
	CppFraction(num, den);
	__asm
	{
		mov eax,num
		mov ebx,0
		cmp eax,ebx
		jge pos
		neg num
     pos:
		mov ecx,num
   	 beg:
	    mov eax, num
		cdq
		div ecx
		cmp edx,0
		jne if1
		mov eax,den
		cdq
		div ecx
		cmp edx,0
		jne if1
		mov nod,ecx
		jmp end
	 if1:
		loop beg
   	 end:
		mov eax,num1
		cdq
		idiv nod
		mov num,eax
		mov eax,den
		cdq
		div nod
		mov den,eax
	}
	std::cout << "New fravtion in asm: " << num << '/' << den << std::endl;
	return 0;
}
