#include <stdio.h>
#include <stdlib.h>
#define INPUTSIZE 9903
void main()
{
    //printf("Hello World");
  long m, n, p, q, c, d, k, sum = 0;
  long mat1_row, mat1_col, mat2_row, mat2_col = 0;
  long randomNumber = 0;
  long first[INPUTSIZE][INPUTSIZE], second[INPUTSIZE][INPUTSIZE], multiply[INPUTSIZE][INPUTSIZE];
 
  mat1_row = mat1_col = mat2_row = mat2_col = INPUTSIZE;

    for (c = 0; c < mat1_row; c++) {
      for (d = 0; d < mat2_col; d++) {
        for (k = 0; k < mat2_row; k++) {
            randomNumber = rand() % 1000;
          sum = sum + randomNumber * randomNumber;
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
  
}