#include <stdio.h>
#include <stdlib.h>
#include "ops.h"

#define UART_DEBUGGING

typedef enum {
    CONFIG_REG_ADDRESS = 0,
    STATUS_REG_ADDRESS,
    FIFOSTATUS_REG_ADDRESS,
}regAddressess_enu;

const char* getRegName(regAddressess_enu regAddress) {

    switch (regAddress) {
        case CONFIG_REG_ADDRESS:
            return "CONFIG_REG_ADDRESS %X";
        case STATUS_REG_ADDRESS:
            return "STATUS_REG_ADDRESS %X";
        case FIFOSTATUS_REG_ADDRESS:
            return "FIFOSTATUS_REG_ADDRESS %X";
    }
}

#ifdef UART_DEBUGGING
    #define PRINT_UART(message, regValue) \
        { \
            uint8_t uartBuffer[30]; \
            sprintf(uartBuffer, getRegName(message), regValue); \
            puts(uartBuffer); \
        } 
#endif

#ifndef UART_DEBUGGING
    #define PRINT_UART(message, regValue) \
    { \
        ; \
    } 
#endif

#define printf_format(x) _Generic((x), \
    char: printf("this is the %c character\n", x), \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p")

int main () {

    unsigned char dec = 31;
    unsigned char bcd = 0b00110001; /* 49[DEC] = 31[BCD] */
    unsigned int hEvento = 0x01B7; /* 0x01B7[HEX] = 439[DEC] */
    unsigned int iEvento = 439;

    //bcdUiToDec(bcd);
    //decUiToBcd(dec);

    //dec3ToBcd(hEvento);
    //dec3ToBcd(iEvento);

    //dec2ToBcd(11);
    //dec2ToBcd(23);
    
    //decomposeEvent(hEvento);
    //decomposeEvent(iEvento);

    /*someChildFooStruct_tag data_hoje;
    someTestUnion_uni data_storage;
    data_hoje.dia = 8;
    data_hoje.mes = 11;
    data_hoje.ano = 2023;
    int i;

    for (i = 0; i < MAX_DATA; i++) {
        printf("data_buffer[%d]: %d\n", i, data_storage.data_buffer[i]);
    }*/

    /*uint8_t number = 0b00110001;
    uint8_t number2 = 0b00110101;

    sliceReg(number2, 2, 5);*/

    /*static volatile uint8_t finishedFunctionToBeAwaited = 0x00;
    uint8_t started = 0x01;
    
    do {
        if (started) {
            finishedFunctionToBeAwaited = functionToBeAwaited();
        }

    } while (started && finishedFunctionToBeAwaited);*/

    uint8_t ui8ConfigRegCurrentValue = 0x3F;
    char ch = 'h';

    //printf_format(ch);

    PRINT_UART(CONFIG_REG_ADDRESS, ui8ConfigRegCurrentValue);

    return 0;
}