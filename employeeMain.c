#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){

    PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber);
    PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName);
    PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char *targetPhone);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, float targetSalary);


    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;


    //Searching by Phone Number

    //Example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-241-1215");
    if(matchPtr != NULL)
        printf("Employee phone 310-241-1215 is in record %d\n", matchPtr - EmployeeTable);
    else   
        printf("Employee phone 310-241-1215 is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if(matchPtr != NULL)
        printf("Employee phone 310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 310-555-1215 is NOT found in record\n");

    //searching by salary

    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 9.99);
    if(matchPtr != NULL)
        printf("Employee salary 9.99 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 9.99 is NOT found in record\n");

    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if(matchPtr != NULL)
        printf("Employee salary 4.50 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 4.50 is NOT found in record\n");


    return EXIT_SUCCESS;
}