#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define size 100

float a[size][size];
float b[size][size];
float c[size][size];

int main()
{

int i;
int j;
int k;

    
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            a[i][j] = (float)i + j;
            b[i][j] = (float)i - j;
            c[i][j] = 0.0f;
        }
    }

    #pragma omp parallel for private(i,j,k) shared(a,b,c)
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            for (k = 0; k < size; ++k) {
                c[i][j] = a[i][k] * b[k][j];
            }
        }
    }
    for (i=0; i<size; i++)
    {
      for (j=0; j<size; j++)
        printf("%4.1f  ", c[i][j]);
      printf("\n");


    return 0;
    }
}
