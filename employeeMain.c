#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber);
    PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName);
    PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char *phone);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary);


    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
  
    //Search by phone

    //Example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-293-2934");
    if(matchPtr != NULL)
        printf("Employee phone number 714-293-2934 is in record %ld\n", matchPtr - EmployeeTable);
    else   
        printf("Employee phone number 714-293-2934 is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
    if(matchPtr != NULL)
        printf("Employee phone number 714-555-2749 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number 714-555-2749 is NOT found in the record\n");


    //Search by salary

    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 9.99);
    if(matchPtr != NULL)
        printf("Employee salary 9.99 is in record %ld\n", matchPtr - EmployeeTable);
    else   
        printf("Employee salary 9.99 is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if(matchPtr != NULL)
        printf("Employee salary 4.50 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 4.50 is NOT found in the record\n");

    return EXIT_SUCCESS;
}