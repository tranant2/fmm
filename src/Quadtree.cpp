#include "Quadtree.h"

void data_to_cpoint(double &x, double &y, std::vector<CPoint> &points){
  //TODO
  (void)x;
  (void)y;
  (void)points;
}
  
/**
 * Default better.
 * Initialize an filled quadtree.
 * depth: how deep you want the tree to go
 */
Quadtree::Quadtree(std::vector<CPoint*> &data, double xmin, double xmax, double ymin, double ymax,
                            int depth) : inode(0), isize(0), iheight(-1) {
    idepth = depth;
    root = buildSubtree(data, xmin, xmax, ymin, ymax, 0);
}

/** Deconstructor to delete all nodes */
Quadtree::~Quadtree() { this->deleteAll(root); }

/** Return true if it added a CPoint
 * into the QT. Else return false.
 */
bool Quadtree::insert(const CPoint& point) {
    //TODO
    (void)point;
    return false;
}

/** Return a vector of points
 * containing the data of the cell.
 */
bool Quadtree::getData(std::vector<CPoint*> &data) {
    //TODO: use recursion
    (void)data;
    return false;
}

/** Return iterator with first element of QT
iterator begin() const {
    if (isize == 0) {
        return this->end();
    }
    return QTIterator<CPoint>(this->first(root));
}*/

/** Return an iterator pointing past the last item in the BST.
iterator end() const { return QT::iterator(0); } */

/** Delete all nodes recuersively */
void Quadtree::deleteAll(QTNode* n) {
    if (n == nullptr) return;
    if (n->q1 != nullptr) {
        deleteAll(n->q1);
    }
    if (n->q2 != nullptr) {
        deleteAll(n->q2);
    }
    if (n->q3 != nullptr) {
        deleteAll(n->q3);
    }
    if (n->q4 != nullptr) {
        deleteAll(n->q4);
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

void Quadtree::splitdata(std::vector<CPoint*> data, std::vector<CPoint*> &data1,std::vector<CPoint*> &data2,
std::vector<CPoint*> &data3,std::vector<CPoint*> &data4, double xmid, double ymid){
    while (!data.empty()){  //while there are still points left
        CPoint* point = data.back();  //copy point
        data.pop_back();  //remove point
        double x = point->x;
        double y = point->y;
        if(x > xmid){  //split points along x
            if(y > ymid){  //split points along y
                data1.push_back(point);
            } else {
                data4.push_back(point);
            }
        } else {
            if(y > ymid){
                data2.push_back(point);
            } else {
                data3.push_back(point);
            }
        }
    }
}

/** Recursively build subtree*/
QTNode* Quadtree::buildSubtree(std::vector<CPoint*> &data, double xmin, double xmax, double ymin, double ymax,
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
    if (iheight==-1){        //case we start a new QT
        if (data.size()==0){  //and there is no data
            QTNode* curr = new QTNode(0,xmin,xmax,ymin,ymax);
            inode++;
            iheight++;
            return curr;
        }
        iheight++;
        inode++;
    } //else we continue and create data to be splitted into four.
    std::vector<CPoint*> data1;
    std::vector<CPoint*> data2;
    std::vector<CPoint*> data3;
    std::vector<CPoint*> data4;
    double xmid = (xmin+xmax)/2;
    double ymid = (ymin+ymax)/2;

    splitdata(data, data1, data2, data3, data4, xmid, ymid);

    QTNode* curr = new QTNode(xmin, xmax, ymin, ymax, depth);

    std::cout << "depth: "<< depth << std::endl;
    std::cout << "node: "<< inode << std::endl;
    if (depth == idepth - 1){  //if depth < log4(N) or reach desired depth, store data
        QTNode* curr1 = new QTNode(data1, xmid, xmax, ymid, ymax, depth + 1);
        QTNode* curr2 = new QTNode(data2, xmin, xmid, ymid, ymax, depth + 1);
        QTNode* curr3 = new QTNode(data3, xmin, xmid, ymin, ymid, depth + 1);
        QTNode* curr4 = new QTNode(data4, xmid, xmax, ymin, ymid, depth + 1);
        inode = inode + 4;
        isize += data1.size();  //update total points stored
        isize += data2.size();
        isize += data3.size();
        isize += data4.size();
        if (depth+1 > iheight){  //set tree height only if depth gotten larger
            iheight = depth + 1;
        }
        curr->q1 = curr1;
        curr->q2 = curr2;
        curr->q3 = curr3;
        curr->q4 = curr4;
        curr->q1->parent = curr;
        curr->q2->parent = curr;
        curr->q3->parent = curr;
        curr->q4->parent = curr;
        std::cout << "reached child" << std::endl;
        return curr;
    }  
    curr->q1 = buildSubtree(data1, xmid, xmax, ymid, ymax, depth + 1);  //connect parent to its children
    curr->q2 = buildSubtree(data2, xmin, xmid, ymid, ymax, depth + 1);
    curr->q3 = buildSubtree(data3, xmin, xmid, ymin, ymid, depth + 1);
    curr->q4 = buildSubtree(data4, xmid, xmax, ymin, ymid, depth + 1);
    inode = inode + 4;
    curr->q1->parent = curr;  //connect children to its parent
    curr->q2->parent = curr;
    curr->q3->parent = curr;
    curr->q4->parent = curr;
    if (depth+1 > iheight){  //set tree height only if depth gotten larger
        iheight = depth + 1;
    }
    return curr;
}

/** Get height recuersively */
int Quadtree::getHeight(QTNode* n, int depth) {
    //TODO
    (void)n;
    (void)depth;
    return 0;
}
