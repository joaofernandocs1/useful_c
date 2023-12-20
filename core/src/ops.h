#include <stdint.h>

#define MAX_DATA 8

typedef enum foo_flags {
    FOO_F = 4,
    FOO_S = 2,
    FOO_T = 9

} someChildFooFlags_enu;

typedef struct {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
} someChildFooStruct_tag;

typedef union {
    someChildFooStruct_tag data;
    unsigned int data_buffer[MAX_DATA];
} someTestUnion_uni;

void decomposeEvent(unsigned int evento);
void dec2ToBcd(unsigned char num);
void bcd2ToDec(unsigned char bcd);
void dec3ToBcd(unsigned int num);
void toggleBit(uint8_t* command, uint8_t bit);
void clearBit(uint8_t* command, uint8_t bit);
void setBit(uint8_t* command, uint8_t bit);
uint8_t readBit(uint8_t* command, uint8_t bit);
void invertArr(uint8_t* arr, uint8_t lengthArr);
uint8_t sliceReg(uint8_t register_value, uint8_t lsb, uint8_t msb);