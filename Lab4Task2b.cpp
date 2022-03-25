#include <iostream>
#include <cmath>
#include<iomanip>
int main()
{
    double pogr = 0.00001;
    double k = 1;
    double rez1 = 0, rez = 0;
    double cur = 0;
    double cur1;
    double ed = 1;
    double t = 2;
    double kv = sqrt(8);
    const double pi = 3.141592653589793239;
    double x;
    for (int i = 1; i <3; i++)
    {
        __asm
        {
        beg:
                finit
                fstp x
                fld rez1
                fstp rez
                fld k
                fmul t
                fsub ed
                fstp cur
                fld ed
                fdiv cur
                fstp cur
                fld cur
                fmul cur
                fstp cur

                fld rez
                fadd cur
                fstp rez
                fld k
                fadd ed
                fstp k
                fld rez
                fstp rez1
                fld rez
                fsqrt
                fmul kv
                fstp rez

                fld pi
                fsub rez
                fstp cur1
                fld cur1
                fcom pogr
                fstsw ax
                sahf
                jc  _less1
                jmp beg
        }
    _less1:
        std::cout << "Number of iterations to find " << 2*i+3 << " correct digits after the decimal point: " << k << std::endl;
        pogr /= 100;
        rez = 0;
        rez1 = 0;
        k = 1;
    }
    return 0;
}
