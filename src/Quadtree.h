#ifndef QUAD_TREE
#define QUAD_TREE

#include "QTNode.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <random>

/* Convert data into cpoint objects
*/
void data_to_cpoint(double &x, double &y, std::vector<CPoint> &points);

/**
 * This class creates a quadtree. Given a
 * set of points in 2-d, this recursively
 * creates a cell, divide the parent's cell into two and
 * divides those cells into two again to make 4 childrens.
 */
class Quadtree {
  protected:
    // Pointer to the root of this QT, or 0 if the QT is empty.
    // root=buildsubtree; should create the tree with everything in it.
    QTNode* root;

    // Number of Data items stored in this QT.
    unsigned int isize;

    // Number of notes stored in this QT.
    unsigned int inode;

    // Height of this QT.
    int iheight;

    // Depth of this QT.
    int idepth;

  public:
    /** Define iterator as an aliased typename for QTIterator<Data>. */
    //TODO

    /**
     * Default constructor.
     * Initialize an empty QT.
     */
    Quadtree() : root(0), isize(0), iheight(-1) {}

    /**
     * Default better.
     * Initialize an filled quadtree.
     */
    Quadtree(std::vector<CPoint*> &data, double xmin, double xmax, double ymin, double ymax,
                                int depth);

    /** Copy Constructor */
    Quadtree(const Quadtree&);

    /** Deconstructor to delete all nodes */
    ~Quadtree();

    /** Return true if it added a CPoint
     * into the QT. Else return false.
     */
    bool insert(const CPoint& point);

    /** Return a vector of points
     * containing the data of the cell.
     */
    bool getData(std::vector<CPoint*> &data);

    /** Return isize */
    unsigned int size() const { return isize; }

    /** Return isize */
    unsigned int numNode() const { return inode; }

    /** Return isize */
    QTNode* getRoot() const { return root; }

    /** Return iheight */
    int height() const { return iheight; }

    /** Return if QT is empty */
    bool empty() const { return (isize == 0); }

    /** Return iterator with first element of QT
    iterator begin() const {
        if (isize == 0) {
            return this->end();
        }
        return QTIterator<CPoint>(this->first(root));
    }*/

    /** Return an iterator pointing past the last item in the BST.
    iterator end() const { return QT::iterator(0); } */

  private:
    /** Delete all nodes recuersively */
    static void deleteAll(QTNode* n);

    /** Split data into 4 */
    void splitdata(std::vector<CPoint*> data, std::vector<CPoint*> &data1,std::vector<CPoint*> &data2,
    std::vector<CPoint*> &data3,std::vector<CPoint*> &data4, double xmid, double ymid);

    /** Recursively build subtree*/
    QTNode* buildSubtree(std::vector<CPoint*> &data, double xmin, double xmax, double ymin, double ymax,
                                int depth);

    /** Get height recuersively */
    static int getHeight(QTNode* n, int depth);
};

#endif  //QUAD_TREE