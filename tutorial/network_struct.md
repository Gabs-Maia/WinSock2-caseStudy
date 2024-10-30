# INFORMATION ACCESS AND ADDRESSES:

# 📡 Network Communication Structures (STRUCTS):

In this file, we'll define three different structures that will be used to hold information regarding network communication. When communicating, it is important to know where things are coming from as well as having a good notion of the thing itself. 

In this form of network communication, TCP, we'll be using IP addresses, clients, and servers... just the usual. 🌐 🚀

:)

### 📜 DEFINING OUR SCOPE:

After creating our header file, we'll need to define the necessary data types for our project. These types will be used a lot throughout the project.

```C
#ifndef NETWORK_STRUCT_H
#define NETWORK_STRUCT_H

#include <stdint.h> 
#include <winsock2.h>
```

- `stdint.h`: A standard library that defines fixed-width integers like `uint8_t` and `uint16_t`.
- `winsock2.h`: Windows socket programming API functions (a package with a bunch of functions).

The two libraries mentioned above are all we'll need for now. The second one is the API provided by Windows. The procedures needed to run a server in C for our application won't work outside of Windows. This means that for each OS, we'll need to implement our own solution. The Windows API is called WinSock2.📂
<br><br>


> 📌 ***Link to documentation***: [WinSock_Documentation](https://learn.microsoft.com/en-us/windows/win32/winsock/using-winsock)


#### 📶 STORING ADDRESSES:

In the context of socket programming we deal with cconnections based on proper communications. In the context of sockets, functions like connect(), bind(), and accept() require a pointer to the specified address.

> For this, we'll make a struct (short for Structure) that'll define:

- ***Address Family***: We need to tell the network functions what type of address they'll deal with. `sin_family`

- ***Port Number***: An address is needed in order to find what we want. With the proper routing we're able to connect and listen to a socket. `sin_port` <br>

- ***IP Address***: For destination identification we provide the IPv4 adress that'll be used. `sin_adrr`

- ***Structuring (Padding)***: Ensure that things are of a proper size and that structs are not in different formats. `sin_zero`

```C
struct sockaddr_in {
    short sin_family;           
    unsigned short sin_port;    
    struct in_addr sin_addr;    
    char sin_zero[8];           
};
```

#### 📶 DEFINING THE ORDER OF ACESS:

We want to access data one at a time. Preferebly having them inside of the same memory space... 

```c 
typedef struct in_addr {
    union {
```

With `typedef`we create aliases. This is a shortcut used for reusability of definitions. This way we won't need to use `struct` every time we need it.

```c 
union {}S_un;
```
Unions allow for the occupation of a single memory space by different data types. Different types of structs can than be used in one place.

```c
struct { u_short s_w1, s_w2; } S_un_w;
```
The representation of the IP address in two 16-bit words. It’s named `S_un_w`.

<details>
<summary>Why use 16-bit words ???</summary>
Let's say we have the following IP address `192.168.1.1`. Storing and operating over it can be very tricky, but if we divide it into different chunks of representation, thing may become easier.

```
11000000 10101000 00000001 00000001
```

You can split this into two 16-bit words:

- First 16-bit word: 11000000 10101000 (or 192.168 in decimal)

- Second 16-bit word: 00000001 00000001 (or 1.1 in decimal)
</details>

<br>

```c 
struct {u_char s_b1, s_b2, s_b3, s_b4;} S_un_b;
```

The struct above holds the address values of an IP address. 

```c
} IN_ADDR, *PIN_ADDR, FAR *LPIN_ADDR;
```

`IN_ADDR`: This alias represents struct in_addr.

`*PIN_ADDR`: This alias represents a pointer to IN_ADDR.

`FAR *LPIN_ADDR`: A far pointer to IN_ADDR. The FAR keyword is not that relevant outside of 16-bit Windows programming. 


## 🖥️ FINAL CODE:

```C
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

```