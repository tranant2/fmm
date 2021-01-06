#include "Cell.hpp"
#include "CPoint.h"
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <complex>
#include <random>

using namespace std;

const int MU = 0;
const double SIGMA = 1e-11;
const double Q = 1.602e-19;
const double EPS0 = 8.854e-12;
const double LENGTH = 5e-11;

double * getData(){
  const int nrolls=1000;  // number of experiments
  const int npoints=100;    // maximum number of stars to distribute

  default_random_engine generator;
  normal_distribution<double> distribution(MU, SIGMA);

  double * p;
  p = new double[npoints];  //TODO: change into CPoint

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>-LENGTH)&&(number<LENGTH)) {
        p[i] = number;
    };
  }
  return p;
}


int main()
{
    double * x = getData();  // Get normal distributions of points of charges around 0,0
    double * y = getData();
    
    double * p = x;
    for (int i = 0; i < 10; i++)
      cout << *p++ << ' ';

    delete[] x;
    delete[] y;
}