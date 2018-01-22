//
//  main.cpp
//  Queue
//
//  Created by ling on 2018/1/22.
//  Copyright © 2018年 ling. All rights reserved.
//

#include <iostream>
#include "AnnularQueue.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    AnnularQueue *q = new AnnularQueue(4);
    
    //插入测试
    q->enQueue(10);
    q->enQueue(12);
    q->enQueue(8);
    q->enQueue(3);
    q->queueTraverse();
    
    //移除测试
    int e = 0;
    q->deQueue(e);
    cout << e << endl;
    cout << endl;
    q->queueTraverse();
    
    //清除测试
    q->clearQueue();
    q->queueTraverse();
    
    return 0;
}
