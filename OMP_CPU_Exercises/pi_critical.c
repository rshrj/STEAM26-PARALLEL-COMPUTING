/*

This program will numerically compute the integral of

                  4/(1+x*x)

from 0 to 1.  The value of this integral is pi -- which
is great since it gives us an easy way to check the answer.

The is the original sequential program.  It uses the timer
from the OpenMP runtime library

History: Written by Tim Mattson, 11/99.

*/
#include <omp.h>
#include <stdio.h>

#define THREADS_WE_WANT 32

static long num_steps = 100000000;
double step;
int main() {
  double pi, globalSum = 0.0;
  double start_time, run_time;

  step = 1.0 / (double)num_steps;

  start_time = omp_get_wtime();
  int nthreads;
  // double threadSum[THREADS_WE_WANT];

  // omp_set_num_threads(THREADS_WE_WANT);
#pragma omp parallel
  {
    int idthread = omp_get_thread_num();
    int num_threads = omp_get_num_threads();
    double sum = 0.0;

    // If not on x86
    if (idthread == 0)
      nthreads = num_threads;

    for (int i = idthread; i < num_steps; i = i + num_threads) {
      double x = (i - 0.5) * step;
      sum = sum + 4.0 / (1.0 + x * x);
    }

    #pragma omp critical
      globalSum = globalSum + sum;
  }

  // for (int i = 0; i < nthreads; ++i) {
  //   globalSum = globalSum + threadSum[i];
  // }

  pi = step * globalSum;
  run_time = omp_get_wtime() - start_time;
  printf("\n pi with %ld steps is %lf in %lf seconds, using %d threads\n",
         num_steps, pi, run_time, nthreads);
}
