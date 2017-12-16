//
//  QuickSort.hpp
//  SortBase
//
//  Created by ling on 2017/12/17.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include <iostream>
#include "SortTestHelper.hpp"

using namespace std;

template <typename T>
int _partition(T arr[], int l, int r){
    
    //拿第一位做参考值
    T v = arr[l];
    
    //划分两组，以v为参考值，但v此时是在第一位，所以需要设置j来获得v最后摆放的位置
    //arr[l+1...j] < v ; arr[j+1...i] >v
    
    //j = v的索引
    int j = l;
    for (int i = l+1; i<=r; i++) {
        if (arr[i] < v) {
            //把i位置的数字放到分界线的前一个位置
            swap(arr[j+1], arr[i]);
            //此时<v的部分多了一位，j需要后退一位
            j++;
        }
    }
    
    //最后将v的位置从第一位放到j位置
    swap(arr[l], arr[j]);
    
    //返回分界线位置
    return j;
}

template <typename T>
void _quickSort(T arr[], int l, int r){
    
    if (l >= r) {
        return;
    }
    
    int p = _partition(arr, l, r);
    _quickSort(arr, l, p-1);
    _quickSort(arr, p+1, r);
    
}

template <typename T>
void quickSort(T arr[], int n){
    _quickSort(arr, 0, n-1);
}

#endif /* QuickSort_hpp */
