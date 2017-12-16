//
//  main.cpp
//  SortBase
//
//  Created by ling on 2017/12/10.
//  Copyright © 2017年 ling. All rights reserved.
//

#include <iostream>
#include "Student.hpp"
#include "SortTestHelper.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

using namespace std;

/*
 *  选择排序，已排序的最后一位被未排序的数字轮番比较
 */
template <typename T> //使用模板(泛型)
void selectionSort(T arr[], int n){
    
    for (int i = 0; i < n; i++) {
        
        //寻找[i,n]区间的最小值
        int minxIndex = i;
        for (int j = i+1; j < n; j++) {
            //从小到大排序
            if (arr[j] < arr[minxIndex]) {
                minxIndex = j;
            }
        }
        swap(arr[i], arr[minxIndex]);
    }
}

/*
 *  冒泡排序,未排序的数字与相邻进行比较，如更大即交换位置，然后继续与相邻比较
 *  与选择排序的区别： 选择排序是先记录位置，最后遍历完再交换。而冒泡是相邻比较符合交换就交换
 */
template <typename T>
void bubblingSort(T arr[], int n){
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

/*
 *  插入排序， 未排序的第一位与已排序的部分轮番比较, 可以提前结束，速度更快！
 *  数组越有序，插入排序越有优势！
 */
template<typename T>
void insertionSort(T arr[], int n){
    
    for (int i = 1; i < n; i ++) {
        
        for (int j = i; j > 0; j--) {
            //从小到大排序
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }else{
                //前面的位置数字更小，所以中止
                break;
            }
        }
    }
}

/*
 * 改进后的插入排序, 未排序的第一位与已排序的部分轮番比较，如果更小，即排序部分向后移一位，
 * 若更大，即值放入空位中。减少swap操作
 * 插入排序在数字近乎相同的情况下，效率极高，因为其n^2，n的系数极小
 */
template<typename T>
void insertionFastSort(T arr[], int n){
    
    for (int i = 1; i < n; i ++) {
        
        T e = arr[i];
        int j;
        for (j = i; j > 0; j--) {
            //当前j = i
            if (arr[j-1] > e) {
                //移后一位
                arr[j] = arr[j-1];
            }else{
                //将e放入被移位后的空值
                arr[j] = e;
                break;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    /*   条件 n = 100000;
     *   quickSort Sort:0.01103s
     *   mergeSort Sort:0.015046s
     *   Insert Fast Sort:4.90452s
     *   Selector Sort:7.84825s
     *   Insert Sort:9.56368s
     *   bubbling Sort:24.049s
     *
     */
    
    int n = 100000;
    //生成随机数字数组
    int *a = SortTestHelper::generateRandomArray(n, 0, n);
    
//    int *b = SortTestHelper::copyIntArray(a, n);
//    执行选择排序
//    selectionSort(b, n);
//    打印排序结果
//    SortTestHelper::printArray(b, n);
//    计算排序性能
//    SortTestHelper::testSort("Selector Sort", selectionSort, b, n);
//    delete[] b;
//    
//
//    int *c = SortTestHelper::copyIntArray(a, n);
//    SortTestHelper::testSort("Insert Sort", insertionSort, c, n);
//    delete[] c;
//
//    int *d = SortTestHelper::copyIntArray(a, n);
//    SortTestHelper::testSort("Insert Fast Sort", insertionFastSort, d, n);
//    delete[] d;
//
//    int *e = SortTestHelper::copyIntArray(a, n);
//    SortTestHelper::testSort("bubbling Sort", bubblingSort, e, n);
//    delete[] e;

    int *f = SortTestHelper::copyIntArray(a, n);
    SortTestHelper::testSort("mergeSort Sort", mergeSort, f, n);
    delete[] f;
    
    int *g = SortTestHelper::copyIntArray(a, n);
    SortTestHelper::testSort("quickSort Sort", quickSort, g, n);
    delete[] g;
    
    //结构体排序
//    Student s[3] = { {"D",90}, {"W",100}, {"T",94} };
//    selectionSort(s, 3);
//    SortTestHelper::printArray(s, 3);
    
//    int w = (1+2)/2;
//    cout << "xxxx:" << w << endl;
    
    return 0;
}
