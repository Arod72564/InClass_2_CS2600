#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize; // adds address of Employee to the bytes of the table size.

    for(;  ptr < endPtr; ptr++){    //search table until end of table
        if(ptr->number == targetNumber) //check if it equals the employee number
            return (PtrToEmployee) ptr; //return location of the number to callee.
    }
    return NULL; //happens if no Employee number matches in loop above
}

//Essentially same fucntionality as above but comparing strings to check if equal

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName){ //Difference in fucntion signature is only in last parameter
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){
        if(strcmp(ptr->name, targetName) == 0) //strcmp returns 0 if true
            return (PtrToEmployee) ptr;
    }
    return NULL;
}