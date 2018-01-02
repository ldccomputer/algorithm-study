//
//  BST.hpp
//  BinarySearchTree
//
//  Created by ling on 2017/12/28.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

using namespace std;

template <typename Key, typename Value>
class BST {
    
private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;
        
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };
    
    Node *root;
    int count;

    
public:
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        
    }
    
    int size(){
        return count;
    }
    
    bool isEmpty(){
        return  count == 0;
    }
    
    //二叉搜索树插入
    void insert(Key key, Value value){
        root = insert(root, key ,value);
    }
    
    //二叉搜索数查找-包含
    bool contain(Key key){
        return contain(key);
    }
    
    //二叉搜索树查找-搜索
    Value* search(Key key){
        return search(root, key)
    }
    
private:
    //向以node为根的二叉搜索中，插入节点(key,value)
    //从上向下做比较，当比左节点大的时候，就以左节点为根继续比较
    Node* insert(Node *node, Key key, Value value){
        if (node == NULL) {
            count ++;
            return new Node(key,value);
        }
        
        if (key == node->key) { //key刚好相同，更新value
            node->value = value;
        }else if (key < node->key){ //key位于左节点
            node->left = insert(node->left, key, value);
        }else{ //key位于右节点
            node->right = insert(node->right, key, value);
        }
    }
    
    //查看以node为根的二分搜索树中是否包含键值为key的节点
    bool contain(Node* node, Key key){
        if (node == NULL) {
            return false;
        }
        if (key == node->key) {
            return true;
        }else if (key < node->key){
            return contain(node->left, key);
        }else{
            return contain(node->right, key);
        }
    };
    
    //在以node为根的二分搜索树中查找key所对应的value,
    //Value* -> 在C++中，返回值若不是void，即不能为空，如果返回值可能为空，我们可以返回它的指针地址，指针地址可指向空
    Value* search(Node* node, Key key){
        if (node == NULL) {
            return NULL;
        }
        if (key == node->key) {
            return &(node->key);
        }else if (key < node->key){
            return search(node->left, key);
        }else{
            return search(node->right, key);
        }
    };
};

#endif /* BST_hpp */
