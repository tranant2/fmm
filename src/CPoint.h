#ifndef POINT
#define POINT

class CPoint{
public:
    double x, y;
    double weight;

    /* Constructor */
    CPoint() : x(0.0), y(0.0), weight(1.0){};

    /* Constructor 2 */
    CPoint(const double& xx, const double& yy): x(xx), y(yy), weight(1.0){};

    /* Constructor 3 */
    CPoint(const double& xx, const double& yy, const double& w): x(xx), y(yy), weight(w){};

};

#endif  // POINT