#include <iostream>

#include "Coordinate.h"
#include "MyStack.h"

int main() {

    MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);

    pStack->push(Coordinate(1,2));
    pStack->push(Coordinate(3,4));

    pStack->stackTraverse();

    if (pStack->stackEmpty()){
        cout << "stack is  empty" << endl;
    }

    if (pStack->stackFull()){
        cout << "stack is full" << endl;
    }

    delete pStack;
    pStack = NULL;

    return 0;
}