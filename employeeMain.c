#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    //defined in employeeOne.c or employeeTwo.c
    //prototypes being defined for compiler as functions are not included in .h
    PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber);
    PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName);

    //defined in employeeTable.c
    //these data variables are not in the includes, use 'extern' so that the compiler does not declare the variables
    //     as they are located elsewhere (employeeTable.c), but it gives the format for the variables
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //declaration, instead of Employee *matchPtr we can use this as we defined in typedef located in employee.h
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if(matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else   
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
        printf("matchPtr: %d. EmployeeTable: %d. employee Tony Bobcat is in record %d\n", matchPtr, EmployeeTable, matchPtr - EmployeeTable);
    else
        printf("employee Tony Bobcat is NOT found in record");

    return EXIT_SUCCESS;
}