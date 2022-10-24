//
// Created by isaac on 10/23/2022.
//

#ifndef PA2_AVLTREE_H
#define PA2_AVLTREE_H

#include <iostream>
#include <cstdlib>
#include "AVLNode.h"

using std::cout;
using std::endl;

template <class T>
class AVLTree {
private:
    //pointer to root node
    AVLNode<T>* root;

    //helper to delete the entire tree
    void deleteTreeHelper(AVLNode<T>* rt);
    //helper to get the height of the tree
    void treeHeightHelper(AVLNode<T>* rt, int* height);
    //gets the height of a node, -1 if the node is null
    int height(AVLNode<T>* node){
        return node == nullptr? -1: node->height;
    }
    //gets the max of two numbers
    int max(int a, int b){
        if(a > b){
            return a;
        }
        else{
            return b;
        }
    }
    //does a single rotation to the left
    void rotateWithLeftChild(AVLNode<T>*& k2);
    //does a single rotation to the right
    void rotateWithRightChild(AVLNode<T>*& k1);
    //does a double rotation to the left
    void doubleWithLeftChild(AVLNode<T>*& k3);
    //does a double rotation to the right
    void doubleWithRightChild(AVLNode<T> *& k3);
    //inserts a node helper
    void insertHelper(const T& dat, AVLNode<T>*& rt);
    //finds if the tree contains a value
    void containsHelper(const T& data, AVLNode<T>* rt, bool& flag);
    //finds if the tree is ballanced
    bool validateHelper(AVLNode<T>* rt);

    //helper for inOrderprint
    void inOrderPrintHelper(AVLNode<T>* rt);



public:

    //constructor
    AVLTree(){
        root = nullptr;
    }

    //destructor
    ~AVLTree(){
        deleteTreeHelper(root);
    }

    //getter for the root
    AVLNode<T>* getRoot() const{
        return root;
    }
    //returns the height of the tree
    int treeHeight(){
        int height = 0;
        treeHeightHelper(root, &height);
        return height;
    }

    void insert(const T& dat){
        insertHelper(dat, root);
    }

    bool contains(const T& dat){
        bool flag = false;
        containsHelper(dat, root, flag);
        return flag;
    }

    bool validate(){
        return validateHelper(root);
    }

    void inOrderPrint(){
        inOrderPrintHelper(root);
    }
};

template <class T>
void AVLTree<T>::deleteTreeHelper(AVLNode<T>* rt){
    if(rt == nullptr){
        return;
    }
    deleteTreeHelper(rt->leftPtr);
    deleteTreeHelper(rt->rightPtr);
    delete rt;
}

template <class T>
void AVLTree<T>::treeHeightHelper(AVLNode<T> *rt, int *height){
    if(rt == nullptr)
        return;
    if(rt->getHeight() > *height)
        *height = rt->getHeight();
}

template <class T>
void AVLTree<T>::rotateWithLeftChild(AVLNode<T>*& k2){
    AVLNode<T>* k1 = k2->leftPtr;

    //rotation
    k2->leftPtr = k1->rightPtr;
    k1->rightPtr = k2;

    //updating height
    k2->height = max(height(k2->leftPtr), height(k2->rightPtr))+1;
    k1->height = max(height(k1->leftPtr), height(k1->rightPtr)) +1;

    //setting the pointer
    k2 = k1;
}

template <class T>
void AVLTree<T>::rotateWithRightChild(AVLNode<T>*& k1){
    AVLNode<T>* k2 = k1->rightPtr;

    //rotation
    k1->rightPtr = k2->leftPtr;
    k2->leftPtr = k1;

    //updating height
    k2->height = max(height(k2->leftPtr), height(k2->rightPtr))+1;
    k1->height = max(height(k1->leftPtr), height(k1->rightPtr)) +1;

    //updating pointer
    k1 = k2;
}

template <class T>
void AVLTree<T>::doubleWithLeftChild(AVLNode<T>*& k3){
    rotateWithRightChild(k3->leftPtr);
    rotateWithLeftChild(k3);
}

template <class T>
void AVLTree<T>::doubleWithRightChild(AVLNode<T> *& k3){
    rotateWithLeftChild(k3->rightPtr);
    rotateWithRightChild(k3);
}

template <class T>
void AVLTree<T>::insertHelper(const T& dat, AVLNode<T>*& rt){
    //if we are past a leaf node, insert
    if(rt == nullptr){
        rt = new AVLNode<T>(dat, nullptr, nullptr);   //height defaults to 0
    }
    //if the data is < rt.data
    else if (dat < rt->data){
        //keep going down the tree and insert at the correct place
        insertHelper(dat, rt->leftPtr);
        //check for height imballance
        int hL = height(rt->leftPtr);
        int hR = height(rt->rightPtr);
        if( hL - hR == 2){
            //cout << endl<< "Validate from insterting left: " << this->validate()<<endl;
            //case 1
            if(dat < rt->leftPtr->data)
                rotateWithLeftChild(rt);
            //case 2
            else
                doubleWithLeftChild(rt);
        }
    }
    //if rt.data < dat
    else if(rt->data<dat){
        //keep going down the tree and insert at the correct place
        insertHelper(dat, rt->rightPtr);
        //check for height imballance
        int hR = height(rt->rightPtr);
        int hL = height(rt->leftPtr);
        if( hR - hL == 2){
            //cout << endl<< "Validate from insterting right: " << this->validate()<<endl;
            //case 4
            if(rt->rightPtr->data < dat)
                rotateWithRightChild(rt);
            //case 3
            else
                doubleWithRightChild(rt);
        }
    }
    rt->height = max(height(rt->leftPtr), height(rt->rightPtr)) + 1;
}

//finds if the tree contains a value
template <class T>
void AVLTree<T>::containsHelper(const T& data, AVLNode<T>* rt, bool& flag){
    if(rt == nullptr)
        return;
    if(rt->data == data)
        flag = true;

    containsHelper(data, rt->leftPtr, flag);

    containsHelper(data, rt->rightPtr, flag);

}

template <class T>
bool AVLTree<T>::validateHelper(AVLNode<T>* rt){
    if(rt == nullptr)
        return true;
    int hLeft = height(rt->leftPtr);
    int hRight = height(rt->rightPtr);
    if(abs((hLeft - hRight)) != 2 && validateHelper(rt->leftPtr)&& validateHelper(rt->rightPtr)){
        return true;
    }
    return false;
}

template <class T>
void AVLTree<T>::inOrderPrintHelper(AVLNode<T>* rt){
    if(rt == nullptr)
        return;
    inOrderPrintHelper(rt->leftPtr);
    cout << rt->data;
    inOrderPrintHelper(rt->rightPtr);

}

#endif //PA2_AVLTREE_H
