#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "ops.h"

/* validado */
#define FRACTUM_DEC3TOBCD(valor) ((valor/100 << 8) | (valor/10 << 4) | (valor%10)) /* < Transforma em BCD */
/* validado */
#define FRACTUM_DEC2TOBCD(valor) ((valor/10 << 4) | (valor%10)) /* < Transforma em BCD */
#define FRACTUM_SEPARA_BYTE_EVENTO 0x000F

unsigned short binaryTimes(unsigned short a, unsigned short b) {
    unsigned int result = 0;
    
    while (b > 0) {
        if (b & 1) {
            result += a;
            }
        a = a << 1;
        b = b >> 1;
    }
    
    printf("a %d Times b %d = : %d\n", a, b, result);

    return result;
}

unsigned short binarySub(unsigned short x, unsigned short y)
{
    
    while (y != 0)  // Iterate until carry becomes 0.
    {
        // step 1: get the borrow bit
        unsigned short borrow = (~x) & y;
        // step 2: get the difference using XOR
        x = x ^ y;
        // step 3: left shift borrow by 1
        y = borrow << 1;
    }
    
    //printf("Sub: %d\n", x);

    return x;
}

unsigned char binaryDiv(unsigned short x, unsigned short y) {

    unsigned short cont = 0;
    short res = 0;

    do {
        x = binarySub(x, y);
        res = x;
        res = binarySub(res, y);
        cont++;

    } while (res > 0);

    printf("x %d Div y %d = : %d\n", x, y, cont);

    return cont;
}

inline int printSomeInlineInt() {

    int it = 3;

    printf("some inline int: %d\n", it);

    return it;
}

static inline char printSomeInlineChar () {

    char ch = 'c';

    printf("c\n");

    return ch;
}

void decomposeEvent(unsigned int evento) 
{ 
    /* evento = 0x01B7 */
    unsigned char lsb = (unsigned char)((FRACTUM_DEC3TOBCD(evento)) & FRACTUM_SEPARA_BYTE_EVENTO); /* 1 byte LSB */ 
    unsigned char mid = (unsigned char)(((FRACTUM_DEC3TOBCD(evento)) >> 4) & FRACTUM_SEPARA_BYTE_EVENTO); /* 1 byte do meio */
    unsigned char msb = (unsigned char)(((FRACTUM_DEC3TOBCD(evento)) >> 8) & FRACTUM_SEPARA_BYTE_EVENTO); /* 1 byte MSB */

    printf("MSB is %X ", msb);
    printf("MID is %X ", mid);
    printf("LSB is %X\n", lsb);
}

void dec3ToBcd(unsigned int num) 
{
    unsigned char cents = num/100;
    unsigned char tens = (num/10)%10;
    unsigned char units = num%10;

    unsigned int bcd = (cents << 8) | (tens << 4) | units;

    printf("%d[BCD] is %d[DEC]\n", num, bcd);
    printf("%d[BCD] is %d[DEC]\n", num, FRACTUM_DEC3TOBCD(num));
}

void dec2ToBcd(unsigned char num) 
{
    unsigned char tens = num/10;
    unsigned char units = num%10;

    unsigned char bcd = (tens << 4) | units;

    //printf("%d[BCD] is %d[DEC]\n", num, bcd);
    printf("%d[BCD] is %d[DEC]\n", num, FRACTUM_DEC2TOBCD(num));
}

void bcd2ToDec(unsigned char bcd) 
{
    unsigned char tens = (bcd >> 4)*10;
    unsigned char units = bcd & 0x0F;

    unsigned dec = tens + units;

    printf("%d[DEC] is %d[BCD]\n", bcd, dec);
}

void printSomeEnuItems() 
{
    int i;
    someChildFooFlags_enu item;
    someChildFooFlags_enu* pItem;
    pItem = &item;

    
    printf("sizeof(someChildFooFlags_enu enum): %d in %p\n", sizeof(item), pItem);
    
    for (i = 0; i < sizeof(item); i++) {

        printf("someChildFooFlags_enu enum: %u in %p\n", *(pItem+i), pItem+i);

    }

}

void printSomeTagItems(void) 
{
    int i;
    someChildFooStruct_tag data;
    someChildFooStruct_tag* pData = &data;
    data.dia = 2;
    data.mes = 11;
    data.ano = 23;

    unsigned int* param;
    param = &(data.dia);

    for (i = 0; i < sizeof(data)/sizeof(unsigned int); i++)
    {
        printf("someChildFooStruct_tag item: %u in %p\n", *(param+i), param+i);
    }

    for (i = 0; i < sizeof(data)/sizeof(unsigned int); i++)
    {
        printf("someChildFooStruct_tag item: %u in %p\n", *(pData+i), pData+i);
    }

    for (i = 0; i < sizeof(data)/sizeof(unsigned int); i++)
    {
        switch (i) 
        {
            case 0:
                printf("someChildFooStruct_tag item: %u in %p\n", pData->dia, &(pData->dia));
                break;
            case 1:
                printf("someChildFooStruct_tag item: %u in %p\n", pData->mes, &(pData->mes));
                break;
            case 2:
                printf("someChildFooStruct_tag item: %u in %p\n", pData->ano, &(pData->ano));
            default:
                break;
        }
    }

}

unsigned int intTimes(unsigned int a, unsigned int b) {

    int i;
    int aux = a;
    
    for (i = 0; i < b-1; i++) {

        a += aux;
    }
    
    printf("(mult) %d\n", a);

    return a;
}

unsigned char intDiv(unsigned int x, unsigned short y) {

    unsigned char cont = 0;
    int res = 0;

    do {
        x -= y;
        res = x;
        res -= y;
        cont++;

    } while (res > 0);

    printf("(div) %d\n", cont);

    return cont;
}

void toggleBit(uint8_t* command, uint8_t bit) {

    printf("command before togglebit[%d]: %X\n", bit, (*command));
    printf("command now: %X\n", (*command) ^= (1 << bit));

}

void clearBit(uint8_t* command, uint8_t bit) {

    printf("command before clearbit[%d]: %X\n", bit, (*command));
    printf("command now: %X\n", (*command) &= ~(1 << bit));

}

void setBit(uint8_t* command, uint8_t bit) {

    printf("command before setbit[%d]: %X\n", bit, (*command));
    printf("command now: %X\n", (*command) |= (1 << bit));

}

uint8_t readBit(uint8_t* command, uint8_t bit) {

    if ((*command) & (1 << bit)) {
        printf("bit %d is 1\n", bit);

        return 1;
    } else if (!((*command) & (1 << bit))){
        printf("bit %d is 0\n", bit);

        return 0;
    }
}

void invertArr(uint8_t* arr, uint8_t lengthArr) {

    uint8_t aux, i;

    for (i = 0; i <lengthArr/2; i++) {
        aux = *(arr+i);
        *(arr+i) = *(arr+lengthArr-i-1);
        *(arr+lengthArr-i-1) = aux;

    }
}

uint8_t sliceReg(uint8_t register_value, uint8_t lsb, uint8_t msb) {

    uint8_t i, mask, res;

    for (i = 0; i < (msb-lsb+1); i++) {
         mask |= (1 << lsb+i);
    }
    
    res = register_value & mask;
    res = res >> lsb;

    printf("Val: %d sliced from bit %d to %d is %d", register_value, lsb, msb, res);

    return res;
}

uint8_t functionToBeAwaited(void) {

    /* this won't work. There are no independent processes binded to this function */
    //sleep(3);

    return 1;
}