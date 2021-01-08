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

    /** Constructor */
    QTNode(const int& d) : level(d) {
        q1 = nullptr;
        q2 = nullptr;
        q3 = nullptr;
        q4 = nullptr;
    }

    /** Set the value of data */
    void setLevel(const int& d) { level = d; }

    /** Get the value of data */
    int getData() { return level; }

};

#endif  // NODE