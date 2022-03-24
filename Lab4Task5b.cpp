#include <iostream>
int main()
{
    double x = 0;
    double k = 1;
    double ten = 10;
    double z = 0;
    double neg = 0;
    double o = 1;
    double log = 0;
    double real = 0;
    double dr = 0;
    double zf = 0.5;
    double scale = 0;
    double dm= 0;
    double rez = 0;
    std::cout << "Enter x: " << std::endl;
    std::cin >> x;
    __asm
    {
        finit
        fld x
        fcom z
        fstsw ax
        sahf 
        jc _less
        fstp x
        jmp norm
        _less:
        fld neg
        fsub o
        fstp neg
        fmul neg
        fstp x
     norm:
        fld x
        fld ten
        fyl2x
        fstp log
        fld log
        frndint
        fstp real
        fld log
        fsub real
        fstp dr
        fld dr
        fcom z
        fstsw ax
        sahf
        jc _less1
        jmp norm1
     _less1:
        fld real
        fsub o
        fstp real
        fld log
        fsub real
        fstp dr
     norm1:
        fld real
        fld o
        fscale
        fstp scale
        fld dr
        f2xm1
        fadd o
        fstp dm
        fld dm
        fmul scale
        fstp rez
        fld neg
        fcom z
        fstsw ax
        sahf
        jc _less2
        jmp end
     _less2:
        fld o
        fdiv rez
        fstp rez
        fld x
        fchs
        fstp x
     end:
    }
    std::cout <<"10^"<<x<<" = "<<rez << std::endl;
    return 0;
}
