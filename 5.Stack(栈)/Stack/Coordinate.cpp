//
// Created by ling on 2018/1/29.
//

#include "Coordinate.h"
#include <iostream>

using namespace std;

Coordinate::Coordinate(int x, int y) {
    m_iX = x;
    m_iY = y;
}

void Coordinate::printCoordinate() {

    cout << "x:" << m_iX << " y:" << m_iY << endl;
}

ostream &operator<<(ostream &out, Coordinate &coor)
{
    out << "x:" << coor.m_iX << " y:" << coor.m_iY << endl;

    return out;
}