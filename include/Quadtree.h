#ifndef QUAD_TREE
#define QUAD_TREE

#include "QTNode.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <random>

/* Data of a CPoint
* You can create an onject like Cpoint p1 {0,0,50};
*/
struct CPoint{
  double x;
  double y;
  double weight;
};

/* Convert data into cpoint objects
*/
void data_to_cpoint(double &x, double &y, std::vector<CPoint> &points);

#endif  //QUAD_TREE