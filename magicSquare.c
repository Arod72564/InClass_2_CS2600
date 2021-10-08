#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int checkIfLoShu(int *array);
void createMagicSquare(int *array, int *countPtr);
void displayArray(int *array);


int main(){
    int loShuArray[3][3] = { {8,1,6},{3,5,7},{4,9,2} };
    int notLoShuArray[3][3] = { {1,6,2},{3,7,8},{4,5,9} };
    int randomArray[3][3];
    int count = 0;
    int *countPtr = &count;
    srand(time(NULL));

    // Use function to check if magic square on array that is correct
    if(checkIfLoShu(loShuArray)){
        printf("This is a Lo Shu Magic Square\n");
    } else {
        printf("This is NOT a Lo Shu Magic Square\n");
    }

    // Use function to check if magic square on array that is NOT correct
    if(checkIfLoShu(notLoShuArray)){
        printf("This is a Lo Shu Magic Square\n");
    } else {
        printf("This is NOT a Lo Shu Magic Square\n");
    }

    // loop to create an randomized array that will break out when it is a Lo Shu Square
    do{
        createMagicSquare(randomArray, countPtr);
    }while(!checkIfLoShu(randomArray));

    printf("Total number of squares generated: %d\n", count);
    printf("Correctly generated Lo Shu Magic Square:\n");
    displayArray(randomArray);

    return 0;
}


/*
 * This function is used to check if the array is a Lo Shu Magic Square. It uses a pointer to iterate through the array
 * checking if each space has 1-9. It also checks to see if each row, column, and diagonol is equal to 15.
 * 
 * Parameters: It takes one 2d array of 3x3 size
 * Returns: returns 1 if it is a Lo Shu Square, and 0 if it is not
 */
int checkIfLoShu(int *array){
    // checking if the array has 1-9
    int checkNum = 1;
    for(int i = 0; i < 9; i++){ // search through array 9 times for each possible number 1-9
        for(int j = 0; j < 9; j++){ // loop through each index of array and check for 1-9; increment check variable if found
            if(checkNum == *(array+j))
                checkNum++;
        }
    }

    if(checkNum != 10)
        return 0;       // if checkNum is not 10, array did not hold 1-9; return 0

    //adding rows, columns, and diagronals together
    int row1 = array[0] + array[1] + array[2];
    int row2 = array[3] + array[4] + array[5];
    int row3 = array[6] + array[7] + array[8];
    int col1 = array[0] + array[3] + array[6];
    int col2 = array[1] + array[4] + array[7];
    int col3 = array[2] + array[5] + array[8];
    int diagonal1 = array[0] + array[4] + array[8];
    int diagonal2 = array[2] + array[4] + array[6];

    //if the rows, columns, and diagonals equal 15, return 1 else return 0
    if (row1 == 15 && row2 == 15 && row3 == 15 &&
        col1 == 15 && col2 == 15 && col3 == 15 &&
        diagonal1 == 15 && diagonal2 == 15){
            return 1;
    } else {
        return 0;
    }
}


/*
 * This function fills a 3x3 array with 1-9 in random order. Numbers 1-9 will not be repeated and only used once in the array.
 * 
 * Parameters: one 2d array of 3x3 size, & pointer to counter variable
 * Returns: function does not return anything
 */
void createMagicSquare(int *array, int *countPtr){
    int num = 0;

    for(int i = 0; i < 9; i++){ //for each index of array generate rand number and assign
        num = (rand()%9)+1; //random number 1-9
        *(array+i) = num;

        //search array for num so it will not repeat
        for(int j = 0; j < i; j++){ //loop iterates through current assigned nums in array; if number is already present decrement i
            if(*(array+j) == num){
                i--;
                break;
            }

        }
    }

    (*countPtr)++; //iterate counter variable when function is done
}


/*
 * This function displays an array of 3x3 size in matrix format
 * 
 * Parameters: one 2d array of 3x3 size
 * Returns: function does not return anything
 */
void displayArray(int *array){
    printf("\n[%d %d %d]\n[%d %d %d]\n[%d %d %d]\n",*(array), *(array+1), *(array+2), *(array+3), *(array+4), *(array+5), *(array+6), *(array+7), *(array+8));
}