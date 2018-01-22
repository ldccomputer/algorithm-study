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


/*
 *  缺点：完全有序的数据，每次都取第一位进行分组，退化为O(n^2)
 *  优化方案：1.随机取1位作为分组参考值
 */

/*
 * 参考图片1，2 v - <v - >v 已排序都在左边，待排序数组在右边
 * 接近有序的情况下，快排的效率还是会退化到O(n^2) 因为<v和>v两级的分化会很大，可参考图片3
 */
template <typename T>
int _partition(T arr[], int l, int r){
    
    //为了避免出现完全有序，每次取第一位为参考导致退化为O(n^2)的情况,随机取1位
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    
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


/*
 *  优化： 双路快速排序法,避免接近有序导致两极分化大
 */
template <typename T>
int _partitionTwoWay(T arr[], int l, int r){
    
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v =arr[l];
    
    int i = l+1, j=r;
    while (true) {
        //i往后移一位
        while ( i <= r && arr[i] < v ) i++;
        //j往前移一位
        while ( j >= l+1 && arr[j] > v) j--;
        // 中止最外层while
        if (i > j) break;
        //此时 arr[i] > arr[j]
        swap( arr[i], arr[j]);
        //交换后，继续对比i，j，v
        i++;
        j--;
    }
    
    swap(arr[l], arr[j]);
    
    return j;
}

/*
 *  图5~9  将arr[l...r]分为 <v; ==v; >v三部分,之后递归 <v, >v 两部分继续三路快速排序
 */
template <typename T>
void _quickSortThreeWay(T arr[], int l, int r){
    
    if (l >= r) {
        return;
    }
    
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v =arr[l];
    
    int lt = l;    //arr[l+1 ... lt] < v  初始化数组为空
    int gt = r+1;  //arr[gt ... r] > v    初始化数组为空
    int i = l+1;   //arr[lt+1 ... i] == v 初始化数组为空
    while ( i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt+1]); //此时 把arr[i] 放入到 [l+1 ... lt]的末位
            lt ++; //<v阵列扩充一位
            i ++;
        }
        else if (arr[i] > v){
            swap(arr[i], arr[gt-1]); //此时 把arr[i] 放入到 [gt...r]的首位
            gt --; //>v阵列扩充一位
            //此时i指向arr[gt-1],所以i不需要移动
        }
        else{
            i++; //此时 arr[i]就在 [lt+1 ... i]内
        }
    }
    
    //此时lt就是<v的末位, 置换后,[lt ... gt-1]都是 ==v
    swap(arr[l], arr[lt]);
    
    _quickSortThreeWay(arr, l, lt-1);
    _quickSortThreeWay(arr, gt, r);
}

template <typename T>
void _quickSort(T arr[], int l, int r){
    
    if (l >= r) {
        return;
    }
    
    int p = _partition(arr, l, r);
//    int p = _partitionTwoWay(arr, l, r);
    _quickSort(arr, l, p-1);
    _quickSort(arr, p+1, r);
    
}

template <typename T>
void quickSort(T arr[], int n){
    
    srand(time(NULL));
    _quickSort(arr, 0, n-1);
//    _quickSortThreeWay(arr, 0, n-1);
}

#endif /* QuickSort_hpp */
