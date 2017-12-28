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
};

#endif /* BST_hpp */
