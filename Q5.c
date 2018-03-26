#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <math.h>

#define million 1000000

int main(int argc, char *argv[])
{

	float dx = 0;
	double x = 0;
	double y = 0;

	remove("calculations.txt");
	#ifdef _OPENMP
  int n = million*100;
	dx = 1/(n+1);
	int nthreads = 8;

	omp_set_num_threads(nthreads);


	#pragma omp parallel for private(x)
	for(int i = 0; i < n; i++)
	{
	x = i * dx;
	y = exp(x)*cos(x)*sin(x)*sqrt(5*x+6);
	if(i > 0 && (i % million) == 0){
	#pragma omp critical
	{
	#ifdef _OPENMP
	FILE * fp =  fopen("calculations.txt", "r+");
	fprintf(fp, "%d: %g - %g\n", i, x, y);
	fclose(fp);
	#endif
    }
	}
  }

	#endif
	return 0;
}
