//
// Created by ling on 2018/1/29.
//

#ifndef STACK_COORDINATE_H
#define STACK_COORDINATE_H

#include <ostream>

using namespace std;

class Coordinate {

    friend ostream &operator<<(ostream &out, Coordinate &coor);

public:
    Coordinate(int x = 0, int y = 0);
    void printCoordinate();

private:
    int m_iX;
    int m_iY;
};


#endif //STACK_COORDINATE_H
