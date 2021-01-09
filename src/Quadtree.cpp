#include "Quadtree.h"

void data_to_cpoint(double &x, double &y, std::vector<CPoint> &points){
  //TODO
}

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
    Quadtree* root;

    // Number of Data items stored in this QT.
    unsigned int isize;

    // Height of this QT.
    int iheight;

  public:
    /** Define iterator as an aliased typename for QTIterator<Data>. */
    //TODO

    /**
     * Default constructor.
     * Initialize an empty BST.
     */
    QT() : root(0), isize(0), iheight(-1) {}

    /** Copy Constructor */
    QT(const QT& bst) : root(0), isize(0), iheight(-1) {
        //TODO
    }

    /** Deconstructor to delete all nodes */
    ~QT() { this->deleteAll(root); }

    /** Return true if it added a CPoint
     * into the QT. Else return false.
     */
    bool insert(const CPoint& point) {
    }

    /** Return a vector of points
     * containing the data of the cell.
     */
    bool getData(std::vector<CPoint*> &data) {
        //TODO: use recursion
    }

    /** Return isize */
    unsigned int size() const { return isize; }

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
    static void deleteAll(QTNode* n) {
        if (n == nullptr) return;
        if (n->q1 != nullptr) {
            deleteAll(n->q1);
        }
        if (n->q2 != nullptr) {
            deleteAll(n->q1);
        }
        if (n->q3 != nullptr) {
            deleteAll(n->q1);
        }
        if (n->q4 != nullptr) {
            deleteAll(n->q1);
        }
        delete n;
        /* Pseudocode:
           if current node is null: return;
           recursively delete q1 sub-tree
           recursively delete q2 sub-tree
           ...
           delete current node
        */
    }

    /** Recursively build subtree*/
    QTNode* buildSubtree(std::vector<CPoint*> &data, double xmin, double xmax, double ymin, double ymax,
                                int depth) {
        /**
         * 1. split data in half x wise
         * 2. split splited data in half y wise
         * 3. stop if we reach a certain level, or once there is no longer two points in a cell
         * 4. create the four quadrant nodes
         * 5. Connect this tree to new tree
         * 6. connect new tree to this tree
         * 7. once reach leaf level, store data.
         */
        //TODO: If data is small, return curr with q1-q4=nullptr

        if (depth==10){
            curr.data=data
            return curr;
        }
        QTNode* curr = new QTNode();
        curr->q1 = buildSubtree(data1, xmin1, xmax1, ymin1, ymax1, depth++);
        curr->q2 = buildSubtree(data1, xmin1, xmax1, ymin1, ymax1, depth++);
        curr->q3 = buildSubtree(data1, xmin1, xmax1, ymin1, ymax1, depth++);
        curr->q4 = buildSubtree(data1, xmin1, xmax1, ymin1, ymax1, depth++);

    }

    /** Get height recuersively */
    static int getHeight(QTNode* n, int depth) {
        //TODO
    }

    // Add more helper functions above
};
