//
// Created by isaac on 10/23/2022.
//

#ifndef PA2_AVLNODE_H
#define PA2_AVLNODE_H

template <class T>
class AVLNode {

protected:
    T data;
    AVLNode<T>* leftPtr;
    AVLNode<T>* rightPtr;
    int height;

    template <class Z> friend class AVLTree;

public:
    //constructor
    explicit AVLNode(const T& data, AVLNode<T>* lPtr = nullptr, AVLNode<T>* rPtr= nullptr, int h = 0);

    //destructor
    ~AVLNode();

    //setters
    void setData(const T& dat);
    void setLeftPtr(AVLNode<T>* lPtr);
    void setRigthPtr(AVLNode<T>* rPtr);
    void setHeight(int h);

    //getters
    T getData() const;
    AVLNode<T>* getLeftPtr()  const;
    AVLNode<T>* getRightPtr()  const;
    int getHeight() const;
};

//constructor definition
template <class T>
AVLNode<T>::AVLNode(const T& data, AVLNode<T> *lPtr, AVLNode<T> *rPtr, int h) {
    this->data =data;
    this->leftPtr = lPtr;
    this->rightPtr =rPtr;
    this->height = h;
}

//destructor definition
template <class T>
AVLNode<T>::~AVLNode(){

}

//setter definitions
template <class T>
void AVLNode<T>::setData(const T &dat) {data = dat;}
template<class T>
void AVLNode<T>::setLeftPtr(AVLNode<T>* lPtr){leftPtr = lPtr;}
template<class T>
void AVLNode<T>::setRigthPtr(AVLNode<T>* rPtr){rightPtr = rPtr;}
template<class T>
void AVLNode<T>::setHeight(int h){height = h;}

//setter definitions
template <class T>
T AVLNode<T>::getData() const {return data;}
template<class T>
AVLNode<T>* AVLNode<T>::getLeftPtr()  const{return leftPtr;}
template<class T>
AVLNode<T>* AVLNode<T>::getRightPtr()  const{return rightPtr;}
template<class T>
int AVLNode<T>::getHeight() const{return height;}



#endif //PA2_AVLNODE_H
