//#include "basic.hpp"
#include "Particle.hpp"

void Particle::Output(int iter)
{
  if(iter%OUTGAP != 0) return;

  printf("----- calculating %05d/%05d -----\n", iter/OUTGAP, MAXITER/OUTGAP);

  FILE *fp;
  char filename[256];

  sprintf(filename, "result/result%05d.dat", iter/OUTGAP);
  if((fp = fopen(filename, "w")) == NULL){printf("FAILED TO OPEN FILE.\n"); exit(1);};
  for(int idParticle = 0; idParticle < numParticle_; idParticle++)
    fprintf(fp, "%15e %15e %15e %7d\n",
        cos(theta_[idParticle]), sin(theta_[idParticle]),
        w0_[idParticle], idParticle);
  fclose(fp);

  // Step 4: calculate the order parameter, r 
  /*
  double rx = 0.0, ry = 0.0;
  for(int idParticle = 0; idParticle < numParticle_; idParticle++){
    rx += ...;
    ry += ...;
  }

  sprintf(filename, "result/K%.2e.dat", K);
  if((fp = fopen(filename, "a")) == NULL){printf("FAILED TO OPEN FILE.\n"); exit(1);};
  fprintf(fp, "%15e %15e\n", iter*DT, ...);
  fclose(fp);
  */
}
