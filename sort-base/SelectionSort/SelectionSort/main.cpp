//
//  main.cpp
//  SelectionSort
//
//  Created by ling on 2017/12/10.
//  Copyright © 2017年 ling. All rights reserved.
//

#include <iostream>
#include "Student.hpp"
#include "SortTestHelper.hpp"

using namespace std;

//使用模板(泛型)
template <typename T>
void selectionSort(T arr[], int n){
    
    for (int i = 0; i < n; i++) {
        
        //寻找[i,n]区间的最小值
        int minxIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minxIndex]) {
                minxIndex = j;
                //提前结束当前循环
                continue;
            }
        }
        swap(arr[i], arr[minxIndex]);
    }
}

int main(int argc, const char * argv[]) {

    int n = 10000;
    //生成随机数字数组
    int *a = SortTestHelper::generateRandomArray(n, 0, n);
    //执行选择排序
    selectionSort(a, n);
    //打印排序结果
    SortTestHelper::printArray(a, n);
    //计算排序性能
    SortTestHelper::testSort("Selector Sort", selectionSort, a, n);
    delete[] a;
    
    Student s[3] = { {"D",90}, {"W",100}, {"T",94} };
    selectionSort(s, 3);
    SortTestHelper::printArray(s, 3);
    
    return 0;
}
