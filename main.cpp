#include "AVLTree.h"

int main(void){
    AVLTree<int> tree;

    for(int i = 1; i <11;i++){
        tree.insert(i);
    }

    tree.inOrderPrint();

    //comment for testing git
    return 0;
}