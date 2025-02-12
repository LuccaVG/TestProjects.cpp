#include <iostream>

int main()
{
    int a = 2; // 10 in binary
    int b = 3; // 11 in binary

    // (a & ~b)
    // a  = 10
    // ~b = 00 (since b is 3 (11 in binary) and ~b is 00 in 2-bit)
    // ---------
    // a & ~b = 00

    // (~a & b)
    // ~a = 01 (since a is 2 (10 in binary) and ~a is 01 in 2-bit)
    // b  = 11
    // ---------
    // ~a & b = 01

    int c = (a & ~b) | (~a & b); 
    // 00 | 01 = 01

    // c = 01

    // (a & b)
    // a  = 10
    // b  = 11
    // ------
    // 10

    int d = ((a & b) << 1) | c; 
    // (10 << 1) = 100
    // A operacao | (OR bit a bit) retorna 1 em qualquer posicao onde pelo menos um dos bits seja 1.             
    // 100 | 001 = 101
    
    // Shift 1 bit to the right
    d = d >> 1; // 101 >> 1 = 100

    std::cout << d << std::endl; // Output: 4

    return 0;
}
