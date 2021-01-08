#include "Cell.hpp"
#include "Quadtree.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <random>

const int MU = 0;
const double SIGMA = 1e-11;
//const double Q = 1.602e-19;
//const double EPS0 = 8.854e-12;
const double LENGTH = 5e-11;

/* Create the random data.
*/
void * getData(std::vector<double> &p){
  const int nrolls=1000;  // number of experiments
  const int npoints=10;    // maximum number of stars to distribute

  default_random_engine generator;
  normal_distribution<double> distribution(MU, SIGMA);

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>-LENGTH)&&(number<LENGTH)) {
        p.push_back(number);
        if (p.size() == npoints){
          break;
        }
    };
  }
}

int main()
{
    std::vector<double> x;
    std::vector<double> y;
    getData(x);  // Get normal distributions of points of charges around 0,0
    getData(y);
    for (double n : x){
      std::cout << n << endl;
    }

    return 0;
}