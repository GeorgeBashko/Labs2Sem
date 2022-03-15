#include <iostream>
int main()
{
	int a[100];
	int c = 0;
	__asm
	{
	  mov esi,0
	  mov eax,0
	  mov a[esi*4],eax
	  inc esi
	  mov eax,1
	  mov a[4*esi],eax
	  beg:
	  mov eax,a[esi*4]
	  mov ebx,a[4*esi-4]
	  add eax,ebx
	  jc end
	  inc esi
	  mov a[esi*4],eax
      inc c
	  jnc beg
	  end:
	}
	std::cout << "The amount of Fibonacci numbers is " << c << std::endl;
	for (int i = 0; i <= c; i++)
		std::cout << a[i] << std::endl;
    return 0;
}
