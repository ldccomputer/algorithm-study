//
//  SortTestHelper.hpp
//  SelectionSort
//
//  Created by ling on 2017/12/10.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef SortTestHelper_hpp
#define SortTestHelper_hpp

#include <stdio.h>
#include <iostream>
#include <cassert>
using namespace std;

namespace SortTestHelper {
    
    //生成随机数组
    int* generateRandomArray(int n, int rangeL, int rangeR){
        
        assert(rangeR - rangeL);
        
        //被new的属性，最后要被delete释放内存
        int *arr = new int[n];
        //随机函数的初始化函数
        srand(time_t(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    
    //打印数组
    template<typename T>
    void printArray(T arr[], int n){
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    
    //测试数组是否排序成功
    template<typename T>
    bool isSorted(T arr[], int n){
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
    
    //计算排序时间
    //void(*sort)(T[], int)  函数指针
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int),T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        
        //验证排序不成功，就报警
        assert(isSorted(arr, n));
        cout << sortName << ":" << double(endTime-startTime)/CLOCKS_PER_SEC << "s" << endl;
        return;
    }
}

#endif /* SortTestHelper_hpp */
