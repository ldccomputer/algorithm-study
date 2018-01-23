//
//  AnnularQueue.hpp
//  Queue
//
//  Created by ling on 2018/1/22.
//  Copyright © 2018年 ling. All rights reserved.
//

#ifndef AnnularQueue_hpp
#define AnnularQueue_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

/*
 *  环形队列的实现
 */
class AnnularQueue
{
private:
    int *m_pQueue;          //队列数组指针
    int m_iQueueLen;        //队列元素个数
    int m_iQueueCapacity;   //队列数组容量
    int m_iHead;            //队头位置
    int m_iTail;            //队尾位置

public:
    AnnularQueue(int queueCapacity){
        m_iQueueCapacity = queueCapacity;
        m_pQueue = new int[m_iQueueCapacity];
        clearQueue();
    }
    
    ~AnnularQueue(){
        delete []m_pQueue;
        m_pQueue = NULL;
    }
    
    //清空队列
    void clearQueue(){
        m_iHead = 0;
        m_iTail = 0;
        m_iQueueLen = 0;
    }
    
    //获取队列长度
    int queueLength(){
        return m_iQueueLen;
    }
    
    //判断队列是否为空
    bool queueEmpty(){
        return m_iQueueLen == 0;
    }
    
    //判断队列为满
    bool queueFull(){
        return m_iQueueCapacity == m_iQueueLen;
    }
    
    //插入队列
    bool enQueue(int element){
        if (queueFull()) {
            return false;
        }else{
            m_pQueue[m_iTail] = element;
            m_iTail++;
            m_iTail = m_iTail % m_iQueueCapacity;
            m_iQueueLen++;
            return true;
        }
    }
    
    //移除队列
    bool deQueue(int &element){
        if (queueEmpty()) {
            return false;
        }else{
            element = m_pQueue[m_iHead];
            m_iHead++;
            m_iHead = m_iHead % m_iQueueCapacity;
            m_iQueueLen--;
            return true;
        }
    }
    
    //遍历队列
    void queueTraverse(){
        for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++) {
            cout << m_pQueue[i%m_iQueueCapacity] << endl;
        }
        cout << endl;
    }
};

#endif /* AnnularQueue_hpp */
