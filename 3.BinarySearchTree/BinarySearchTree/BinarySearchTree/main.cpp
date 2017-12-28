//
//  main.cpp
//  BinarySearchTree
//
//  Created by ling on 2017/12/28.
//  Copyright © 2017年 ling. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T>
int binarySearch(T arr[], int n, T targe){
    
    //在arr[l...r]中查找
    int l = 0, r = n-1;
    while (l <= r) {
        //若l,r上最大的整数，mid会溢出
        //int mid = (l+r)/2;
        int mid = l+(r-l)/2;
        if (arr[mid] == targe) {
            return mid;
        }
        
        if(targe < arr[mid]){
            //arr[l...mid-1]
            r = mid-1;
        }else{
            //arr[mid+1...r]
            l = mid+1;
        }
    }
    return  -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
