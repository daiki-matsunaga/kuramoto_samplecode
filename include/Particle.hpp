#ifndef particle_H__
#define particle_H__

#include "basic.hpp"

/* class */
class Particle
{
  public:
    Particle();
    ~Particle();

  // member functions (method)
  public:
    void    Update();
    void    CalcVelocity();
    void    Output(int iter);

  // member variables
  private:
    double  *theta_, *w_, *w0_;
    int     numParticle_;
};

#endif
