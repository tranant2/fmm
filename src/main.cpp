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
void getData(std::vector<double> &p){
  const int nrolls=1E4;  // number of experiments
  const int npoints=1E3;    // maximum number of stars to distribute

  std::default_random_engine generator;
  std::normal_distribution<double> distribution(MU, SIGMA);

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>-LENGTH)&&(number<LENGTH)) {
      p.push_back(number);
    }
    if (p.size() == npoints){
      break;
    }
  }
}

int main()
{
  std::vector<double> x;
  std::vector<double> y;
  getData(x);  // Get normal distributions of points of charges around 0,0
  getData(y);

  std::vector<CPoint*> data;
  while (!x.empty()){
    CPoint p {x.back(),y.back(),1};
    data.push_back(&p);
    x.pop_back();
    y.pop_back();
  }

  std::cout << "start TREE test = reach child:" << std::endl;
  Quadtree tree = Quadtree(data,-1,1,-1,1,2);
  std::cout << "start EMPTY test = 0:" << std::endl;
  std::cout << tree.empty() << std::endl;
  std::cout << "start SIZE test = "<< 100 << ':' << std::endl;
  std::cout << tree.size() << std::endl;
  std::cout << "start NUMNODE test = 21:" << std::endl;
  std::cout << tree.numNode() << std::endl;
  std::cout << "start DEPTH test = 3:" << std::endl;
  std::cout << tree.height() << std::endl;

  tree.tree_to_matrix();
  
  return 0;
}