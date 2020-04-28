#include "basic.hpp"
#include "Particle.hpp"

/* constructor */
Particle::Particle()
{
  numParticle_ = NUM_PARTICLE; 

  // allocate variables
  theta_  = new double[numParticle_];
  w_      = new double[numParticle_];
  w0_     = new double[numParticle_];

  double average_w = 1.0;

  srand(0); // set seed for random generator
  for(int idParticle = 0; idParticle < numParticle_; idParticle++){

    theta_[idParticle] = randRange(0.0, 2.0*M_PI);

    // Step 2: change the distribution of angular velocity w
    w0_[idParticle] = average_w;
//    w0_[idParticle] = randGauss(average_w, SIGMA);
//    w0_[idParticle] = randCauchy(average_w, GAMMA);
  }
}

/* destructor */
Particle::~Particle()
{
  // free variables
  delete [] theta_;
  delete [] w_;
  delete [] w0_;
}
