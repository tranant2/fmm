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
    std::vector<CPoint*> data;

    /** Constructor */
    QTNode(const int& d) : level(d) {
        q1 = nullptr;
        q2 = nullptr;
        q3 = nullptr;
        q4 = nullptr;
    }

    /** Set the value of data */
    void setLevel(const int& d) { level = d; }

    /** Get the value of level */
    int getData() { return level; }

    /** Return true is node is on the same level*/
    bool is_same_level(QTNode* node){
        //TODO check if same level
        //check is on the same level
    }

    /** Return true is node is this node nearest neighbor*/
    bool is_near_neighbor(QTNode* node){
        //TODO check if same level
        //check is nearest neighbor
    }

    /** Return true is node is this node is well separated*/
    bool is_well_separated(QTNode* node){
        //TODO check if same level
        //check if well separated
    }
};

#endif  // NODE