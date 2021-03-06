/**
 * Author: Anthony Tran
 * 
 * A cell object which holds information
 * about a cell.
 */
#ifndef NODE
#define NODE

#include <string>
#include <utility>
#include <vector>

/* Data of a CPoint
* You can create an onject like Cpoint p1 {0,0,50};
*/
struct CPoint{
  double x;
  double y;
  double weight;
};

/**
 * The purpose of this class is to create a cell object. This is
 * used to make a quadtree
 * //Set the layout to be:
    //--------------------------
    //|           |            |
    //|     2     |      1     |
    //|           |            |
    //--------------------------
    //|           |            |
    //|     3     |      4     |
    //|           |            |
    //--------------------------
 */
class QTNode {
  private:
    int level; 

  public:
    QTNode* q1;
    QTNode* q2;
    QTNode* q3;
    QTNode* q4;
    QTNode* parent;
    double xmin;
    double xmax;
    double ymin;
    double ymax;
    std::vector<CPoint*> data;

    /** Constructor */
    QTNode(const double& x0,const double& x1,
     const double& y0, const double& y1, const int& d) : 
    level(d), xmin(x0), xmax(x1), ymin(y0), ymax(y1) {
        q1 = nullptr;
        q2 = nullptr;
        q3 = nullptr;
        q4 = nullptr;
        parent = nullptr;
    }

    /** Constructor 2*/
    QTNode(const std::vector<CPoint*>& d, const double& x0,const double& x1,
     const double& y0, const double& y1, const int& l) : 
    data(d), level(l), xmin(x0), xmax(x1), ymin(y0), ymax(y1) {
        q1 = nullptr;
        q2 = nullptr;
        q3 = nullptr;
        q4 = nullptr;
        parent = nullptr;
    }

    /** Set the value of level */
    void setLevel(const int& d) { level = d; }

    /** Get the value of level */
    int getLevel() { return level; }

    /** Set the values of data */
    void setData(std::vector<CPoint*> &d) { data = d; }

    /** Get the values of data */
    std::vector<CPoint*> getData() { return data; }

    /** Return true is node is on the same level*/
    bool is_same_level(QTNode* node){
        //TODO check if same level
        //check is on the same level
        (void)node;
        return false;
    }

    /** Return true is node is this node nearest neighbor.
     * Two nodes are said to be near neighbours if they are at the same refinement 
     * level and share a boundary point. (A box is a near neighbour of itself.)
    */
    bool is_near_neighbor(QTNode* node){
        //TODO check if same level
        //check is nearest neighbor
        (void)node;
        return false;
    }

    /** Return true is node is this node is well separated.
     * Two nodes are said to be well separated if they are 
     * at the same refinement level and are not near neighbours.
    */
    bool is_well_separated(QTNode* node){
        //TODO check if same level
        //check if well separated
        (void)node;
        return false;
    }
};

#endif  // NODE