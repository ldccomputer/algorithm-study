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
#include <iostream>
#include <queue>
#include <cassert>

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
        
        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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
        //后序排序 正好符合从下向上销毁节点
        destory(root);
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
        return search(root, key);
    }
    
    //前序遍历
    void preOrder(){
        preOrder(root);
    }
    
    //中序遍历
    void inOrder(){
        inOrder(root);
    }
    
    //后序遍历
    void postOrder(){
        postOrder(root);
    }
    
    //层序遍历  每一层地遍历
    void levelOrder(){
        
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            //取队首移出
            Node *node = q.front();
            q.pop();
            
            cout << node->key <<endl;
            //将其子节点加入队列
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    
    //寻找最小的键值
    Key minimum(){
        assert(count != 0);
        Node* maxNode = minimum(root);
        return maxNode->key;
    }
    
    //寻找最大的键值
    Key maximum(){
        assert(count != 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }
    
    //删除最小值的节点
    void removeMin(){
        if (root) {
            removeMin(root);
        }
    }
    
    //删除最大值的节点
    void removeMax(){
        if (root) {
            root = removeMax(root);
        }
    }
    
    // 从二分搜索树中删除键值为key的节点
    void remove(Key key){
        root = remove(root, key);
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
    
    void preOrder(Node *node){
        if (node != NULL) {
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node){
        if (node != NULL) {
            inOrder(node->left);
            cout<<node->key<<endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node *node){
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<endl;
        }
    }
    
    void destory(Node *node){
        if (node != NULL) {
            destory(node->left);
            destory(node->right);
            
            delete node;
            count--;
        }
    }
    
    // 返回以node为根的二分搜索树的最小键值所在的节
    Node* minimum(Node* node){
        if (node->left == NULL) {
            return node;
        }
        return minimum(node->left);
    }
    
    // 返回以node为根的二分搜索树的最大键值所在的节点
    Node* maximum(Node* node){
        if (node->right == NULL) {
            return node;
        }
        return maximum(node->right);
    }
    
    // 删除掉以node为根的二分搜索树中的最小节点
    // 自始而终，一直在遍历root，返回删除节点后新的二分搜索树的根
    Node* removeMin(Node* node){
        if (node->left == NULL) {
            //如果节点没有左子节点，那么删除节点后，由右子节点接替该节点的位置
            Node* rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }
        
        node->left = removeMin(node->left);
        return node;
    }
    
    // 删除掉以node为根的二分搜索树中的最大节点
    // 自始而终，一直在遍历root，返回删除节点后新的二分搜索树的根
    Node* removeMax(Node* node){
        if (node->right == NULL) {
            //如果节点没有右子节点，那么删除节点后，由左子节点接替该节点的位置
            Node *leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }
        
        node->right = removeMax(node->right);
        return node;
    }
    
    // 删除掉以node为根的二分搜索树中键值为key的节点
    // 自始而终，一直在遍历root，返回删除节点后新的二分搜索树的根
    Node* remove(Node* node, Key key){
        if (node == NULL) {
            return NULL;
        }
        
        if (key < node->key) {
            
            node->left = remove(node->left,key);
            return node;
        }else if (key > node->key){
            
            node->right = remove(node->right,key);
            return node;
        }else{ //key == node->key
            
            if (node->left == NULL) {
                Node* rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }
            if (node->right == NULL) {
                Node *leftNode = node->left;
                delete node;
                count --;
                return leftNode;
            }
            
            //以右节点的最小子节点为后继点
            //因为后面需要删除该节点，所以需要拷贝出来
            Node *successor = new Node(minimum(node->right));
            count ++;
            
            //返回来是移除最小节点后的根节点，也就是node的右节点
            successor->right = removeMin(node->right);
            successor->left = node->left;
            
            delete node;
            count --;
            
            //返回值为某个node的左或右子节点
            return successor;
        }
    }
    
};

#endif /* BST_hpp */
