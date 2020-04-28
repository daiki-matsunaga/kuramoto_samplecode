#ifndef basic_H__
#define basic_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DT              1.0e-2
#define OUTDT           4.0e-2
#define TMAX            2.0e+1
#define MAXITER         ((int)((TMAX)/(DT)))
#define OUTGAP          ((int)((OUTDT)/(DT)))

#define NUM_PARTICLE    50

#ifndef K
#define K               3.0
#endif

#define SIGMA           0.4
#define GAMMA           0.5

double randRange(double min, double max);
double randBasic();
double randGauss(double mu, double sigma);
double randCauchy(double mu, double gamma); 

#endif
