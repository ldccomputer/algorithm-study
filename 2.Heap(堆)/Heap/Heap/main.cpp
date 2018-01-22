//
//  main.cpp
//  Heap
//
//  Created by ling on 2017/12/25.
//  Copyright © 2017年 ling. All rights reserved.
//

#include <iostream>
#include "MaxHeap.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.size()<<endl;
    
    //堆插入元素
    srand(time(NULL));
    for (int i = 0; i < 15; i++) {
        maxheap.insert(rand()%100);
    }
    maxheap.testPrint();
    
    //堆取出最大元素
    while (!maxheap.isEmpty()) {
        cout<<maxheap.extractMax()<<" ";
    }
    
    return 0;
}
