#include <iostream> 
using namespace std; 
int main() 
{ 
    __int16 a3(0b1111001100111111), a2(0b1111111111111110), a1(0b100010010001111); 
    __int16 b3(0b1101110100110101), b2(0b1000100010101110), b1(0b100010010001111);
    unsigned __int16 c3(0), c2(0), c1(0);
    cin >> a1>>a2 >> a3; 
    cin >> b1 >> b2 >> b3; 
    __asm 
    { 
        mov ax, a1 
        mov bx, b1 
        adc ax, bx 
        mov c1, ax 
 
        mov ax, a2 
        mov bx, b2 
        adc ax, bx 
        mov c2, ax 
 
        mov ax, a3 
        mov bx, b3 
        adc ax, bx 
        mov c3, ax 
  } 
    cout << a3 << "  " << a2 << "  " << a1 << endl; 
    cout << b3 << "  " << b2 << "  " << b1 << endl; 
    cout << hex; 
    cout << c3 << "  " << c2 << "  " << c1 << endl; 
    cout << dec; 
    cout << c3 << "  " << c2 << "  " << c1 << endl; 
    return 0; 
}
