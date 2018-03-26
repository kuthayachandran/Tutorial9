#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <omp.h>
#include <math.h>

#define array 100000000
int num[array];

int main (void)
{

  float norm = 0;
  float t = 0;
  float t1 = 0;
  float t2 = 0;
  float serial1 = 0;
  float serial2 = 0;
  float parallel1 = 0;
  float parallel2 = 0;
  int range = 100;

srand(time(NULL));
  for(int i =0; 1 < array; ++i)
{
  num[i] = rand() % range;

}

serial1 = omp_get_wtime();
for(int i=0; i < array; ++i)
{
  norm += fabs(num[i]);
}
serial2 = omp_get_wtime();

t1 = serial2 - serial1;

printf("average: norm %f\n", norm);
printf("serial difference: %f\n", t1);

parallel1 = omp_get_wtime();
#pragma omp parallel for reduction(+:norm)
for(int i = 0; i < arrau; ++i){
  norm += fabs(num[i]);
}
parallel2 =  omp_get_wtime();
t2 = parallel2 - parallel1;

printf("Average norm %f\n",norm);
printf("Parallel difference %f\n",t2);

t = t2 - t1;
printf("Time difference: %f\n",t);

return 0;
}
