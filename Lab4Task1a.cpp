#include <iostream>
#include <math.h>
double func(double x1)
{
	return pow(x1, 2.0) * 2 - 1331 / (x1 + 11) + 3;
}
int main()
{
	double x;
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
		jz _great
	_less :
		fstp t6
		fld t
		fstp t2
		jmp end
	_great :
		fstp t6
		fld t
		fstp t1
	end :
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
	}
_great1:
	{
		std::cout << "Not roots" << std::endl;
		return 0;
	}
_less1:
	std::cout << "Root: " << x << std::endl;
	return 0;
}
