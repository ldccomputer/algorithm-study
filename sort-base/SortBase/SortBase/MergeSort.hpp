//
//  MergeSort.hpp
//  SortBase
//
//  Created by ling on 2017/12/13.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <iostream>
#include "SortTestHelper.hpp"

using namespace std;

template<typename T>
void _merge(T arr[], int l, int mid, int r){
    
    T aux[r-l+1];
    for (int i = l; i <= r; i++) {
        //i是从l开始的
        aux[i-l] = arr[i];
    }
    
    //三个标识符,i,j代表归并的两部分的头，k初始位置在i
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {//越界了，代表i部分全部都排序了，而j部分还没开始排序
            arr[k] = aux[j-l];
            j++; //比较完后，往后移一位
        }else if( j > r){//越界了，代表j部分全部都排序了，而i部分还没开始排序
            arr[k] = aux[i-l];
            i++;
        }else if (aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }else{
            arr[k] = aux[j-l];
            j++;
        }
        
    }
    
}

/**
  * 插入排序在数字近乎相同的情况下，效率极高，因为其n^2，n的系数极小
  */
template<typename T>
void insertionSort(T arr[], int l, int r){
    
    for (int i = 1+l; i <= r; i ++) {
        
        T e = arr[i];
        int j;
        for (j = i; j > l; j--) {
            if (arr[j-1] > e) {
                arr[j] = arr[j-1];
            }else{
                arr[j] = e;
                break;
            }
        }
    }
}

template<typename T>
void _mergeSort(T arr[], int l, int r){
    
    //
    if(r-l <= 15){
        insertionSort(arr, l, r);
        return;
    }
    
    if(l >= r){
        return;
    }
    
    int mid = (l+r)/2;
    //看下面的数据可得出，左右不断递归，划分一半。等最小集合l>=r，就开始从小集合merge到大集合merge
    _mergeSort(arr, l, mid);
    _mergeSort(arr, mid+1, r);
    _merge(arr, l, mid, r);
}

/*
 mid:0 mid:1 mid:3 mid:2 mid:5 mid:6 mid:8 mid:7 mid:4
 arr:0 0 1 1 2 3 5 6 7 8
 */

template<typename T>
void mergeSort(T arr[], int n){
    _mergeSort(arr, 0, n-1);
//    SortTestHelper::printArray(arr, n);
}

#endif /* MergeSort_hpp */
