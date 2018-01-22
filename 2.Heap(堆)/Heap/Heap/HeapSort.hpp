//
//  HeapSort.hpp
//  Heap
//
//  Created by ling on 2017/12/26.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <stdio.h>
#include <iostream>
#include "MaxHeap.hpp"

using namespace std;

template <typename T>
void heapSort1(T arr[], int n){
    
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for (int i = 0; i < n; i++) {
        maxHeap.insert(arr[i]);
    }
    //从小到大
    for (int i = n-1; i >= 0; i--) {
        arr[i] = maxHeap.extractMax();
    }
}

//Heapify:给定一个数组，使一个数组形成堆的排列
//只移位<=count/2,所以更快
template <typename T>
void heapSort2(T arr[], int n){
    
    MaxHeap<T> maxHeap = MaxHeap<T>(arr,n);
    for (int i = n-1; i >= 0; i--) {
        arr[i] = maxHeap.extractMax();
    }
}




#endif /* HeapSort_hpp */
