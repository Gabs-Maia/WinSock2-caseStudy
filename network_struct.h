#ifndef NETWORK_STRUCT_H
#define NETWORK_STRUCT_H

#include <stdint.h> 
#include <winsock2.h>


struct sockaddr_in {
    short sin_family;           
    unsigned short sin_port;    
    struct in_addr sin_addr;    
    char sin_zero[8];           
};

typedef struct in_addr {
    union {
        struct {
            u_char s_b1, s_b2, s_b3, s_b4;
        } S_un_b;
        struct {
            u_short s_w1, s_w2;
        } S_un_w;
        u_long S_addr;
    } S_un;
} IN_ADDR, *PIN_ADDR, FAR *LPIN_ADDR;

struct sockaddr {
    unsigned short sa_family;  
    char sa_data[14];          
};

#endif 
