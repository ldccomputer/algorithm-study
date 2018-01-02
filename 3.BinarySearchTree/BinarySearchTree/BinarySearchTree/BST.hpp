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
};

#endif /* BST_hpp */
