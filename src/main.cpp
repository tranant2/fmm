#include "QTNode.hpp"
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

  std::default_random_engine generator;
  std::normal_distribution<double> distribution(MU, SIGMA);

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
      std::cout << n << std::endl;
    }
    
    std::vector<CPoint*> data1;
    Quadtree tree1 = Quadtree(data1,-1,1,-1,1,0);
    std::cout << "start test" << std::endl;
    std::cout << tree1.empty() << std::endl;
    std::cout << "end test" << std::endl;
    /*
    CPoint p1 {.5,.5,1};
    CPoint p2 {-.5,.5,1};
    CPoint p3 {.5,-.5,1};
    CPoint p4 {-.5,-.5,1};
    std::vector<CPoint*> data = {&p1,&p2,&p3,&p4};
    Quadtree tree = Quadtree(data,-1,1,-1,1,0);
    std::cout << "start test" << std::endl;
    std::cout << tree.empty() << std::endl;
    std::cout << "end test" << std::endl;
    */
    return 0;
}