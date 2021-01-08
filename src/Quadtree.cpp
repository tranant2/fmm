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
        vector<CPoint> array = bst.inorder();
        if (!array.empty()) {
            root = buildSubtree(array, 0, bst.size() - 1, 0);
            isize = this->inorder().size();
        }
    }

    /** Deconstructor to delete all nodes */
    ~BST() { this->deleteAll(root); }

    /** Return true if it added a copy of a data item
     * into the BST. Else return false for duplicate.
     */
    bool insert(const Data& item) {
        // If no element exist in tree
        if (iheight == -1) {
            // I was creating this on the stack so I was having
            // error. Don't forget to create this on the heap since
            // you want to keep it for later.
            root = new BSTNode<Data>(item);
            iheight++;
            isize++;
            return true;
        }

        BSTNode<Data>* curr = root;
        int tempHight = 0;

        // While the item is not a duplicate
        while ((item < curr->getData()) || (curr->getData() < item)) {
            // Go left if values less then parent's
            if (item < curr->getData()) {
                if (curr->left == nullptr) {
                    curr->left = new BSTNode<Data>(item);
                    // Don't forget to assign parent node!
                    curr->left->parent = curr;
                    isize++;
                    if (iheight < ++tempHight) {
                        iheight++;
                    }
                    return true;
                } else {
                    tempHight++;
                    curr = curr->left;
                }
                // Go right if data is bigger than parent's
            } else if (curr->getData() < item) {
                if (curr->right == nullptr) {
                    curr->right = new BSTNode<Data>(item);
                    curr->right->parent = curr;
                    isize++;
                    if (iheight < ++tempHight) {
                        iheight++;
                    }
                    return true;
                } else {
                    tempHight++;
                    curr = curr->right;
                }
            }
        }
        return false;
    }

    /** Find a node containting the data item, else return nullptr */
    iterator find(const Data& item) const {
        BSTNode<Data>* curr = root;
        if (curr == nullptr) {
            return this->end();
        }

        // While the item is not found
        while ((item < curr->getData()) || (curr->getData() < item)) {
            // Go left if data is less then parent's
            if (item < curr->getData()) {
                if (curr->left == nullptr) {
                    return this->end();
                } else {
                    curr = curr->left;
                }
                // Go right if data bigger than parent's
            } else if (curr->getData() < item) {
                if (curr->right == nullptr) {
                    return this->end();
                } else {
                    curr = curr->right;
                }
            }
        }
        // Return founded node
        return BSTIterator<Data>(curr);
    }

    /** Return true if node was deleted, else false. */
    bool deleteNode(const Data& item) {
        BSTNode<Data>* curr = root;
        // if empty, return false
        if (curr == nullptr) {
            return false;
        }
        // While the item is not found
        while ((item < curr->getData()) || (curr->getData() < item)) {
            // Go left if data is less then parent's
            if (item < curr->getData()) {
                if (curr->left == nullptr) {
                    return false;
                } else {
                    curr = curr->left;
                }
                // Go right if data is bigger than parent's
            } else if (curr->getData() < item) {
                if (curr->right == nullptr) {
                    return false;
                } else {
                    curr = curr->right;
                }
            }
        }
        // If we are here, we found the element
        // and we have a pointer to it's node

        // 0 Child
        if (curr->left == nullptr && curr->right == nullptr) {
            // Check if parent if null first
            if (curr->parent == nullptr) {
                root = nullptr;
                // Set 1 parent's child to nullptr
            } else if (item < curr->parent->getData()) {
                curr->parent->left = nullptr;
            } else {
                curr->parent->right = nullptr;
            }
            delete curr;
            isize--;
            // 1 Child
        } else if (curr->left == nullptr || curr->right == nullptr) {
            // If the child is on the right
            if (curr->left == nullptr) {
                curr->right->parent = curr->parent;
                // if item it a left child
                // and if curr is parent node
                // join child to parent.
                if (curr->parent != nullptr && item < curr->parent->getData()) {
                    curr->parent->left = curr->right;
                } else {
                    curr->parent->right = curr->right;
                }
            } else {
                curr->left->parent = curr->parent;
                // if item it a left child
                // and if curr is parent node
                // join child to parent.
                if (curr->parent != nullptr && item < curr->parent->getData()) {
                    curr->parent->left = curr->left;
                } else {
                    curr->parent->right = curr->left;
                }
            }
            delete curr;
            isize--;
            // 2 Child
        } else {
            BSTNode<Data>* s = curr->successor();
            // If successor is a left child,
            // parent's left child adopts
            // successor's child.
            if (s->getData() < s->parent->getData()) {
                // Note s doesn't have a left child else
                // it would have been the successor.
                s->parent->left = s->right;
                // else, parent's right child adopts
                // successor's child.
            } else {
                s->parent->right = s->right;
            }
            // Then tell successor's child
            // who it's adopted parents are
            // if the child exist.
            if (s->right != nullptr) {
                s->right->parent = s->parent;
            }
            // replace curr data with successor's data
            curr->setData(s->getData());
            delete s;
            isize--;
        }
        iheight = getHeight(root, 0);
        return true;
    }

    /** Return isize */
    unsigned int size() const { return isize; }

    /** Return iheight */
    int height() const { return iheight; }

    /** Return if BST is empty */
    bool empty() const { return (isize == 0); }

    /** Return iterator with first element of BST */
    iterator begin() const {
        if (isize == 0) {
            return this->end();
        }
        return BSTIterator<Data>(this->first(root));
    }

    /** Return an iterator pointing past the last item in the BST. */
    iterator end() const { return typename BST<Data>::iterator(0); }

    /** Return BST in order from least to greatest.
     * Vist left, current, then right.
     */
    vector<Data> inorder() const {
        BSTNode<Data>* curr = root;
        vector<Data> array;
        // If array empty, return null array.
        if (curr == nullptr) {
            return array = {};
        }
        return *(this->inorder(&array, curr));
    }

    /**
     * DO NOT CHANGE THIS METHOD
     * Prints a tree, including its structure to an
     * output stream to help with grading and debugging.
     */
    void print(ostream* out) {
        if (empty()) {
            *out << "(Empty tree)" << endl;
            return;
        }

        // Using a queue to traverse a tree is otherwise
        // known as a breadth first traversal of the tree.
        // It's useful here to show which nodes are on which
        // level.
        queue<BSTNode<Data>*> toVisit;
        toVisit.push(root);
        int nodesPerLevel = 1;
        int totalSpacing = 1 << iheight;

        for (int i = 0; i <= iheight; i++) {
            for (int j = 0; j < nodesPerLevel; j++) {
                BSTNode<Data>* curr = toVisit.front();
                toVisit.pop();
                if (curr == nullptr) {
                    *out << "X";
                    // If we have an entire missing subtree, we
                    // would like to print X's in place of all
                    // nodes because it avoids ambiguity
                    toVisit.push(nullptr);
                    toVisit.push(nullptr);
                } else {
                    *out << curr->getData();
                    toVisit.push(curr->left);
                    toVisit.push(curr->right);
                }
                for (int k = 0; k < totalSpacing / nodesPerLevel; k++) {
                    *out << "\t";
                }
            }
            *out << endl;
            nodesPerLevel *= 2;
        }
    }

  private:
    /** Helper function for begin() to find the first element of the BST*/
    static BSTNode<Data>* first(BSTNode<Data>* root) {
        BSTNode<Data>* curr = root;
        // basically find the left most node.
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    /** Does inorder traversal recursivly */
    static vector<Data>* inorder(vector<Data>* array, BSTNode<Data>* curr) {
        // If reach a leaf, store data
        if ((curr->left == nullptr) && (curr->right == nullptr)) {
            array->push_back(curr->getData());
        } else {
            // Go left first
            if (curr->left != nullptr) {
                inorder(array, curr->left);
            }
            // store current node
            array->push_back(curr->getData());
            // then go right.
            if (curr->right != nullptr) {
                inorder(array, curr->right);
            }
        }
        return array;
    }

    /** Delete all nodes recuersively */
    static void deleteAll(BSTNode<Data>* n) {
        if (n == nullptr) return;
        if (n->left != nullptr) {
            deleteAll(n->left);
        }
        if (n->right != nullptr) {
            deleteAll(n->right);
        }
        delete n;
        /* Pseudocode:
           if current node is null: return;
           recursively delete left sub-tree
           recursively delete right sub-tree
           delete current node
        */
    }

    /** Recursively biuld subtree that's balanced */
    BSTNode<Data>* buildSubtree(vector<Data>& data, int start, int end,
                                int depth) {
        // Gives the median. If there are two median, give the larger one.
        int nodeNum = int((end - start + 1) / 2 + start);
        BSTNode<Data>* curr = new BSTNode<Data>(data[nodeNum]);
        // Reach leaf node
        if (end == start) {
            curr->left = nullptr;
            curr->right = nullptr;
            iheight = depth + 1;
            return curr;
        }
        curr->left = buildSubtree(data, start, nodeNum - 1, depth + 1);
        curr->left->parent = curr;

        // We reached a right leaf
        if (nodeNum + 1 > end) {
            curr->right = nullptr;
            iheight = depth + 1;
            return curr;
        } else {
            curr->right = buildSubtree(data, nodeNum + 1, end, depth + 1);
            curr->right->parent = curr;
        }
        return curr;
    }

    /** Get height recuersively */
    static int getHeight(BSTNode<Data>* n, int depth) {
    }

    // Add more helper functions above
};
