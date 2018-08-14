#include <stdio.h>

#define NULL_REG 0x00
#define A_REG 0x01 
#define B_REG 0x02
#define C_REG 0x03

#define DATA_REG_LEN 3

typedef struct
{
    unsigned char addr;
    unsigned char data[DATA_REG_LEN];
} REGISTER;

static REGISTER reg[] = 
{
    {A_REG,    0x01,0x02,0x03},
    {B_REG,    0x11,0x12,0x13},
    {C_REG,    0x21,0x22,0x23},
    {NULL_REG, 0x00,0x00,0x00},
};

static int reg_table_len = sizeof(reg) / sizeof(reg[0]);

void write_reg(unsigned char addr, unsigned char *data)
{
    int i;
    for(i=0; i<reg_table_len; i++) {
        if(reg[i].addr == addr) {
            reg[i].data[0] = data[0];
            reg[i].data[1] = data[1];
            reg[i].data[2] = data[2];
            break;
        }
    }
}

void read_reg(unsigned char addr, unsigned char *data)
{
    for(int i=0; i < reg_table_len; i++) {
        if(reg[i].addr == addr) {
            data[0] = reg[i].data[0];
            data[1] = reg[i].data[1];
            data[2] = reg[i].data[2];
            break;
        }
    }
}

void print_reg(unsigned char addr)
{
    for(int i=0; i < reg_table_len; i++) {
        if(reg[i].addr == addr) {
            for(int j=0; j < sizeof(reg[0].data); j++)
                printf("0x%02x ", reg[i].data[j]);
            break;
        }
    }
}

int main()
{
    unsigned char wda[3] = {0xff, 0xff, 0xff};

    print_reg(A_REG);
    print_reg(NULL_REG);
    write_reg(NULL_REG, wda);
    print_reg(NULL_REG);

    read_reg(B_REG, wda);
    printf("0x%02x\n", wda[0]);
    printf("0x%02x\n", wda[1]);
    printf("0x%02x\n", wda[2]);

    return 0;
}
