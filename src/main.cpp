#include "basic.hpp"
#include "Particle.hpp"
#include <time.h>

/* main function */
int main()
{
  Particle particle;

  clock_t start, end;

  // main loop - iteration
  start = clock();
  for(int iter = 0; iter <= MAXITER; iter++){
    particle.Output(iter);    // output result

    particle.CalcVelocity();  // calculate particle velocity
    particle.Update();        // update particle position
  }
  end = clock();

  printf("Computational time: %.3f [s]\n", (double)(end - start)/CLOCKS_PER_SEC);

  return 0;
}
