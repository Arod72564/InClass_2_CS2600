#include <stdio.h>
#include <stddef.h>

typedef struct {       //Employee struct
    long number;
    char *name;
    char *phone;
    double salary;
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;  //Pointer to employee struct