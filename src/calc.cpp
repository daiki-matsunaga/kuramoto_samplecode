#include "basic.hpp"
#include "Particle.hpp"

double randRange(double min, double max){return (rand()/(RAND_MAX/(max - min)) + min);}
double randBasic(){return (rand()/(double)(RAND_MAX));}
double randGauss(double mu, double sigma){return sigma*sqrt(-2.0*log(randBasic()))*sin(2.0*M_PI*randBasic()) + mu;}
double randCauchy(double mu, double gamma){return mu + gamma*tan(M_PI*(randBasic() - 0.5));} 

void Particle::CalcVelocity()
{
  // calculate r and psi
  double  vx = 0.0, vy = 0.0;
  for(int idParticle = 0; idParticle < numParticle_; idParticle++){
    double  theta = theta_[idParticle];
    vx += cos(theta);
    vy += sin(theta);
  }
  vx /= (double)numParticle_;
  vy /= (double)numParticle_;

  // Step 3: calculate r and psi
  /*
  double  r   = ...; 
  double  psi = ...; 
  */

  // Step 3: add interaction term: using K, r, psi and theta_[idParticle]
  for(int idParticle = 0; idParticle < numParticle_; idParticle++)
    w_[idParticle] = w0_[idParticle];
}

void Particle::Update()
{
  for(int idParticle = 0; idParticle < numParticle_; idParticle++)
    theta_[idParticle] += w_[idParticle]*DT;
}

