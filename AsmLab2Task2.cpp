#include <iostream>
using namespace std;
int main()
{
	int num = -1;
	int ed = 0;
	int ed1 = 0;

	while (num < 0)
	{
		cout << "Enter number: ";
		cin >> num;
	}
	__asm
	{
		//first variant
		mov eax,num
		beg2:
		add ed1,1
		mov ebx, eax
		sub ebx,1
		and eax, ebx
		jnz beg2
		//second variant
		mov ecx,32
		mov eax,num
		beg:
		shr eax,1
		jnc beg1
		add ed,1
		beg1:
		loop beg
	}
	cout <<"The number of ones in binary notation of the number(first variant): " << ed<<endl;
	cout << "The number of ones in binary notation of the number(second variant): " << ed1;
	return 0;
}
