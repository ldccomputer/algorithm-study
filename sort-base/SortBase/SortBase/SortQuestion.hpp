//
//  SortQuestion.hpp
//  SortBase
//
//  Created by ling on 2017/12/19.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef SortQuestion_hpp
#define SortQuestion_hpp

#include <stdio.h>
#include <iostream>
#include "SortTestHelper.hpp"

using namespace std;

template <typename T>
int getMaxNumber(T arr[], int l, int r){
    
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    
    T v = arr[l];
    
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



#endif /* SortQuestion_hpp */
