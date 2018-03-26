#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <omp.h>

#define million 100000000

int main (int argc, char *argv[])
{
    int n = million;
    double y[n];
    double x;
    double dx = 1.0 / (n+1.0);
    int nthreads; int thread_num;

    #ifdef _OPENMP
    omp_set_num_threads(nthreads);
    #endif

    #pragma omp parallel for private(x)
    for (int i = 0; i < n; ++i)

    {
      x = i*dx;
      y[i] = exp(x)*cos(x)*sin(x)*sqrt(5*x+6.0);

      #pragma omp critical
      {
        #ifdef _OPENMP
        thread_num = omp_get_thread_num();
        printf("This thread = %d, num = %d, step size = %f\n",
               thread_num, y, x);
        #endif

}
    }

    return 0;
}
