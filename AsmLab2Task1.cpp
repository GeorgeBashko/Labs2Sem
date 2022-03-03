#include <iostream>
using namespace std;
int main()
{
	int x = 0;
    int CppResult1 = 0;
	int CppResult2 = 0;
	int CppResult3 = 0;
	int AsmResult1 = 0;
	int AsmResult2 = 0;
	int AsmResult3 = 0;
	while (x == 0)
	{
		cout << "Enter x: ";
		cin >> x;
	}
	CppResult1 = (x * x * x * x * x + 2 * (x * x - 4) + x) / (x * x * x);
	CppResult2 = (2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x);
	CppResult3 = (4 * x - 1) * (4 * x + 1) / 4;
	int y = 2;
	int z = 4;
		__asm
	{
		 //First expression
		 mov eax, x
		 mov ecx, 4
		 beg:
		 imul x
		 loop beg
		 add eax,x 
		 mov AsmResult1,eax

		 mov eax,x
         imul x
		 sub eax,4 
		 mov ecx,y
		 imul ecx
		 add AsmResult1,eax

		 mov eax,x
		 mov ecx, 2
		 beg2:
		 imul x
		 loop beg2
		 mov ecx,eax
		 mov eax,AsmResult1
		 cdq
		 idiv ecx
		 mov AsmResult1,eax
         //Second expression
		 mov ecx,y
		 mov eax,x
		 imul y
		 sub eax,1
		 mov AsmResult2,eax
		 
		 mov eax, x
		 imul y
		 add eax, 1
		 imul AsmResult2
		 mov AsmResult2,eax

		 mov eax,x
		 add eax,3
		 imul AsmResult2
     	 mov AsmResult2,eax

		 mov eax,x
		 imul y
		 mov ecx,eax
		 mov eax,AsmResult2
		 cdq
		 idiv ecx
	     mov AsmResult2,eax
		 //Third expression
		 mov eax,x
	     mov ecx,z
		 imul ecx
		 sub eax,1
		 mov AsmResult3,eax

		 mov eax,x
		 mov ecx,z
		 imul ecx
		 add eax,1
		 mov ecx,AsmResult3
	     imul ecx
	     cdq
         mov ecx,z
		 idiv ecx
		 mov AsmResult3,eax
		}
	cout << "Result of first expression in Cpp: " << CppResult1<<endl;
	cout << "Result of first expression in asm: " << AsmResult1 << endl;
	cout << "Result of second expression in Cpp: " << CppResult2<<endl;
	cout << "Result of second expression in asm: " << AsmResult2 << endl;
	cout << "Result of third expression in Cpp: " << CppResult3 << endl;
	cout << "Result of third expression in asm: " << AsmResult3 << endl;
	return 0;
}
