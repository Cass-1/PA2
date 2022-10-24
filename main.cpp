#include "AVLTree.h"

int main(){
    AVLTree<int> tree;

    for(int i = 11; i > 0; i--){
        tree.insert(i);
    }

    tree.inOrderPrint();

    //comment for testing git
    return 0;
}