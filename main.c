#include <stdio.h>
#include <stdint.h>
void print_bin8(uint8_t v)
{
    for (int i = 7; i >= 0; i--){
        putchar((v & (1U << i)) ? '1' : '0');
    }
    putchar('\n');
}

uint8_t set_bit(uint8_t reg, uint8_t n) {return reg | (1U << n);}
uint8_t clear_bit(uint8_t reg, uint8_t n) {return reg & ~(1U << n);}
uint8_t toggle_bit(uint8_t reg, uint8_t n) {return reg ^ (1U << n);}
uint8_t check_bit(uint8_t reg, uint8_t n)  {reg & (1U << n);}
    int main(void)
{
    uint8_t reg = 0b00000100;

    print_bin8(reg);                                // 00000100
    reg = set_bit(reg, 1);     print_bin8(reg);     // 00000110
    reg = clear_bit(reg, 2);   print_bin8(reg);     // 00000010
    reg = toggle_bit(reg, 3);  print_bin8(reg);     // 00001010

    printf("bit3 = %d\n", check_bit(reg, 3));       // 1
    printf("bit2 = %d\n", check_bit(reg, 2));       // 0
    return 0;
}
