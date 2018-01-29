//
// Created by ling on 2018/1/29.
//

#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class MyStack
{
private:
    T *m_pBuffer; //栈空间指针
    int m_iSize; //栈容量
    int m_iTop;  //栈顶,栈中元素个数

public:
    MyStack(int size){
        m_iSize = size;
        m_pBuffer = new T[size];
        m_iTop = 0;
    }

    ~MyStack(){
        delete []m_pBuffer;
        m_pBuffer = NULL;
    }

    bool stackEmpty(){
        return m_iTop == 0;
    }

    bool stackFull(){
        return m_iTop == m_iSize;
    }

    void clearStack(){
        m_iTop = 0;
    }

    int stackLength(){
        return m_iTop;
    }

    //入栈
    bool push(T elem){
        if (stackFull()) {
            return false;
        }
        //自下向上,栈顶自增
        m_pBuffer[m_iTop] = elem;
        //栈顶指向更高一级，但这时，m_iTop处是空的
        m_iTop++;
        return true;
    }

    //出栈
    bool pop(T &elem){
        if (stackEmpty()) {
            return false;
        }
        m_iTop--;
        elem = m_pBuffer[m_iTop];
        return true;
    }

    //遍历
    void stackTraverse(){
        for (int i = 0; i < m_iTop; i++) {
//            m_pBuffer[i].printCoordinate();
            cout << m_pBuffer[i];
        }
    }

};



#endif //STACK_MYSTACK_H
