#include <iostream>
#include <cmath>
#include<iomanip>
int main()
{
    double ln;
    double pogr = 0.00001;
    int k1 = 1;
    double k = 1;
    double ed = -1;
    double ed1 = 1;
    double ced;
    double rez = 0, rez1 = 0;
    double x;
        __asm
        {
        beg1:
                fstp x
                fld ed
                mov ecx, k1
                beg :
            fmul ed
                loop beg
                inc k1
                fstp ced
                fld ed1
                fdiv k
                fstp rez
                fld ced
                fmul rez
                fstp rez
                fld rez1
                fadd rez
                fstp rez1
                fld k
                fadd ed1
                fstp k
                fldln2
                fsub rez1
                fstp ln
                fld ln
                fabs
                fcom pogr
                fstsw ax
                sahf
                jc  _less1
                jmp beg1
        }
    _less1:
        std::cout << "Number of iterations to find " << 5 << " correct digits after the decimal point : " << k << std::endl;
    return 0;
}
