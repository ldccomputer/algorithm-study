//
//  IndexHeap.hpp
//  Heap
//
//  Created by ling on 2017/12/27.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef IndexHeap_hpp
#define IndexHeap_hpp

#include <stdio.h>
#include <istream>
#include <assert.h>
#include <cmath>

using namespace std;

//索引堆
template <typename Item>
class IndexHeap {
private:
    Item *data;  //数据
    int *indexs; //数据在堆中的位置
    int *revs;   //indexs中的序号对应的数据的序号
    int count;
    int capacity;
    
    //向上移交换
    void shiftUp(int k){
        //子节点要比父节点小
        while (k > 1 && data[indexs[k/2]] < data[indexs[k]]) {
            swap(indexs[k/2], indexs[k]);
            revs[indexs[k/2]] = k/2;
            revs[indexs[k]] = k;
            k /= 2;
        }
    }
    
    //向下移交换
    void shiftDown(int k){
        
        while (2*k <= count) { //保证有左节点
            //代表要与k交换位置的节点
            int j = 2*k;
            //有右节点，而且右节点比左节点大
            if ( j+1 <= count && data[indexs[j+1]] > data[indexs[j]]) {
                j += 1;
            }
            
            //k节点大于子节点
            if (data[indexs[k]] >= data[indexs[j]]) {
                break;
            }
            
            swap(indexs[k], indexs[j]);
            revs[indexs[k]] = k;
            revs[indexs[j]] = j;
            k = j;
        }
    }
    
public:
    IndexHeap(int capacity){
        //从1开始
        data = new Item[capacity+1];
        indexs = new int[capacity+1];
        revs = new int[capacity+1];
        //提前初始化
        for (int i = 0; i <= capacity; i++) {
            revs[i] = 0; //从1开始，0没有意义
        }
        count = 0;
        this->capacity = capacity;
    }

    ~IndexHeap(){
        delete [] data;
        delete [] indexs;
        delete [] revs;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    //插入
    //用户角度，i上从0开始
    void insert(int i, Item item){
        assert(count+1 <= capacity);
        assert(i+1>=1 && i+1 <= capacity);

        i += 1;
        //先插入数组最后一位,0位留空
        data[i] = item;
        indexs[count+1] = i;
        
        revs[i] = count+1;
        
        count ++;
        //再进行堆的移位操作
        shiftUp(count);
    }

    //移出最大节点
    Item extractMax(){
        assert(count > 0);

        Item ret = data[indexs[1]];
        //将最大父节点与末位交换位置
        swap(indexs[1], indexs[count]);
        revs[indexs[1]] = 1;
        revs[indexs[count]] = 0; //指向0，代表删除了
        //移除父节点
        count --;
        //排序
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex(){
        
        assert(count > 0);

        int ret = indexs[1] -1;

        swap(indexs[1], indexs[count]);
        revs[indexs[1]] = 1;
        revs[indexs[count]] = 0; //指向0，代表删除了
        
        count --;
        shiftDown(1);

        return 0;
    }

    bool contain(int i){
        //对于用户来说，i上从0开始的
        assert( i+1 >= 0 && i+1 <= capacity);
        return revs[i+1] != 0;
    }
    
    Item getItem(int i){
        assert(contain(i));
        assert(i > 0);
        return data[i+1];
    }
    
    void change( int i, Item newItem ){
        assert(contain(i));
        i += 1;
        data[i] = newItem;
        
        //找到indexs[j] = i, j表示data[i]在堆中的位置
        //之后再上下移位，排好序
//        for (int j = 1; j <= count; j++) {
//            if (indexs[j] == i) {
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }
        
        //但是这种遍历使复杂的达到了O(n)+O(logn),我们可以新建数组记录j的位置，那就能达到O(logn)
        int j = revs[i];
        shiftUp(j);
        shiftDown(j);
        
    }
    
    
};


#endif /* IndexHeap_hpp */

