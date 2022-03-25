#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double arr[2];
	double x, x1, x2;
	double t1 = -10;
	double t2 = 10;
	double t = 0;
	double cur, cur1, cur2, rez;
	double pogr = 0.000001;
	double a, b, c;
	double el = 11.0;
	double z = 0.0;
	double two = 2.0;
	double t3, t4, t5, t6;
	int kk = 0;
	double ten = 10;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	std::cout << "Enter c: ";
	std::cin >> c;
	__asm
	{
	_next:
		finit
			fstp t6
			//середина
			fld t1
			fadd t2
			fdiv two
			fstp t
			fld t
			//значение первом на конце
			mov ecx, 1
			fld t1
			beg :
		fmul t1
			loop beg
			fmul a
			fstp t3
			fld t1
			fadd el
			fstp cur
			fld b
			fdiv cur
			fstp cur
			fld t3
			fadd cur
			fstp cur
			fld c
			fadd cur
			fstp cur
			//значеие на втором конце
			mov ecx, 1
			fld t
			beg1 :
		fmul t
			loop beg1
			fmul a
			fstp t4
			fld t
			fadd el
			fstp cur1
			fld b
			fdiv cur1
			fstp cur1
			fld t4
			fadd cur1
			fstp cur1
			fld c
			fadd cur1
			fstp cur1
			//произведение
			fld cur
			fmul cur1
			fstp cur2
			fld  cur2
			fcom z
			fstsw ax
			sahf
			jc  _less
			jnz _great
			_zero :
		fld cur1
			fcom z
			fstsw ax
			sahf
			jz zero
			jmp zero1
			zero :
		fld t
			fstp x2
	}
	arr[kk] = x2;
	__asm
	{
		inc kk
		jmp _less
		zero1 :
		fld t1
			fstp x2
	}
	arr[kk] = x2;
	__asm
	{
		inc kk
		jmp _less
		_less :
		fstp t6
			fld t
			fstp t2
			jmp end2
			_great :
		fstp t6
			fld t
			fstp t1
			end2 :
		fld t2
			fsub t1
			fstp rez
			fabs
			fld  rez
			fcom pogr
			fstsw ax
			sahf
			jc  end1
			jnz _next
			end1 :
		fld t1
			fadd t2
			fdiv two
			fstp x
			mov ecx, 1
			fld x
			beg2 :
		fmul x
			loop beg2
			fmul a
			fstp t5
			fld x
			fadd el
			fstp cur
			fld b
			fdiv cur
			fstp cur
			fld t5
			fadd cur
			fstp cur
			fld c
			fadd cur
			fstp cur
			fld  cur
			fcom pogr
			fstsw ax
			sahf
			jc  _less1
			jnz _great1
			je _great1
			_less1 :
		fld x
			fstp x1
	}
	arr[kk] = x1;
	__asm
	{
		inc kk
		fld z
		fstp t1
		fld ten
		fstp t2
		mov eax, kk
		sub eax, 2
		cmp eax, 0
		je _less2
		jmp _next
	}
_great1:
	{
		std::cout << "Not roots" << std::endl;
		return 0;
	}
_less2:
	for (int i = 0; i < kk; i++)
	{
		std::cout << "Root: " << arr[i] << std::endl;
	}
	return 0;
}
