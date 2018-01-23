//
//  MyStack.hpp
//  Stack
//
//  Created by ling on 2018/1/23.
//  Copyright © 2018年 ling. All rights reserved.
//

#ifndef MyStack_hpp
#define MyStack_hpp

#include <stdio.h>
#include <iostream>

using namespace std;


class MyStack
{
private:
    char *m_pBuffer; //栈空间指针
    int m_iSize; //栈容量
    int m_iTop;  //栈顶,栈中元素个数
    
public:
    MyStack(int size){
        m_iSize = size;
        m_pBuffer = new char[size];
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
    bool push(char elem){
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
    char pop(char &elem){
        if (stackEmpty()) {
            return NULL;
        }
        m_iTop--;
        elem = m_pBuffer[m_iTop];
        return elem;
    }
    
    //遍历
    void stackTraverse(){
        for (int i = 0; i < m_iTop; i++) {
//            cout << i << endl;
            cout << m_pBuffer[i] << endl;
        }
    }
    
};


#endif /* MyStack_hpp */
