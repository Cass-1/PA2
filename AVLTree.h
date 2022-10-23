//
// Created by isaac on 10/23/2022.
//

#ifndef PA2_AVLTREE_H
#define PA2_AVLTREE_H

#include "AVLNode.h"

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
        return a > b? a:b;
    }
    //does a single rotation to the left
    void rotateWithLeftChild(AVLNode<T>*& k2);
    //does a single rotation to the right
    void rotateWithRightChild(AVLNode<T>*& k1);
    //does a double rotation to the left
    void doubleWithLeftChild(AVLNode<T>*& k3);
    //does a double rotation to the right
    void doubleWithRightChild(AVLNode<T> *& k3);



public:
    //constructor
    AVLTree(){
        root = nullptr;
    }

    //destructor
    ~AVLTree(){
        deleteTreeHelper(root);
    }

    //returns the height of the tree
    int treeHeight(){
        int height = 0;
        treeHeightHelper(root, &height);
        return height;
    }

    //inserts a node
    void insert(const T& dat, AVLNode<T>*& rt);
};

template <class T>
void AVLTree<T>::deleteTreeHelper(AVLNode<T>* rt){
    if(rt == nullptr){
        return;
    }
    deleteHelper(rt->getLeftPtr());
    deleteHelper(rt->getLeftPtr());
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
void AVLTree<T>::insert(const T& dat, AVLNode<T>*& rt){
    //if we are past a leaf node, insert
    if(rt == nullptr){
        rt = new AVLNode<T>(dat, nullptr, nullptr);   //height defaults to 0
    }
    //if the data is < rt.data
    else if (dat < rt->data){
        //keep going down the tree and insert at the correct place
        insert(dat, rt->leftPtr);
        //check for height imballance
        if(height(rt->leftPtr) - height(rt->rightPtr) == 2){
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
        insert(dat, rt->rightPtr);
        //check for height imballance
        if(height(rt->rightPtr) - height(rt->leftPtr) == 2){
            //case 4
            if(rt->rightPtr->data < dat)
                rotateWithRightChild(rt);
            //case 3
            else
                doubleWithRightChild(rt);
        }
    }
    rt->height = max(rt->leftPtr->height, rt->rightPtr->height)+1;
}

#endif //PA2_AVLTREE_H
