#include <iostream>
int main()
{
    int kx = -1;
    int ky = -1;
    int sv = -1;
    while (kx <= 0 || ky <= 0 || sv < 0)
    {
        std::cout << "Enter natural x koef,y koef and sv: "<<std::endl;
        std::cin >> kx;
        std::cin >> ky;
        std::cin >> sv;
    }
    std::cout << "Your equantion: " << kx << "x" << '+' << ky << "y" << '=' << sv << std::endl;
    int a[1000];
    int b[1000];
    int x = -1;
    int y = -1;
    int size3 = sv / kx;
    int size1 = 0;
    int size2 = sv / ky;
    __asm
    {
           mov esi, 0
        forx:
           mov ecx, y
           sub y, ecx
           sub y, 1
           add x,1
           mov ebx,x
           mov eax,size3
           cmp ebx,eax
           jle fory
           jg end
        fory:
           add y,1
           mov ebx,y
           mov eax,size2
           cmp ebx,eax
           jle next
           jg forx
        next:            
           mov eax,x           
           mul kx                
           mov ebx,eax             
           mov eax,y
           mul ky
           add eax,ebx
           cmp eax,sv
           je movArray
           jne fory
        movArray:
           mov eax,x
           mov a[esi*4],eax
           mov eax,y
           mov b[esi*4],eax
           inc size1
           inc esi  
           jmp fory
        end:
    }
     std::cout<< "Solutions to your equation in Asm: " << std::endl;
     for(int c = 0;c<size1;c++)
     std::cout << '(' << a[c] << "," << b[c] << ')' << std::endl;
     std::cout << "Solutions to your equation in Cpp: " << std::endl;
     for(int x =0;x<=size3;x++) 
     for (int y = 0; y <= sv/ky; y++)
     if (y* ky + x * kx == sv)    
     std::cout << '(' << x << ',' << y << ')' << std::endl;
     return 0;
}
