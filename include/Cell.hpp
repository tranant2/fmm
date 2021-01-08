/**
 * Author: Anthony Tran
 * 
 * A cell object which holds information
 * about a cell.
 */
#ifndef CELL_HPP
#define CELL_HPP

#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * The purpose of this class is to create a cell object. This is
 * used to make a quadtree
 */
class Cell {
  private:
    char data;
    unsigned int level;

  public:
    Cell* q1;
    Cell* q2;
    Cell* q3;
    Cell* q4;

    /* Constructor */
    Cell(const char& d, const unsigned int f) : data(d), level(f) {
        q1 = nullptr;
        q2 = nullptr;
        q3 = nullptr;
        q4 = nullptr;
    };

    /* Constructor 2 */
    Cell(const char& d)
        : data(d), level(0) {  // empty node = 0 for identification
        q1 = nullptr;
        q2 = nullptr;
        q3 = nullptr;
        q4 = nullptr;
    };

    /** Set the value of data */
    void setData(const char& d) { data = d; }

    /** Get the value of data */
    char getData() { return data; }

    /** Set the value of level */
    void setLevel(const unsigned int& f) { level = f; }

    /** Get the value of level */
    unsigned int getLevel() { return level; }
};

#endif  // CELL_HPP