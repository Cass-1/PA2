#include "AVLTree.h"

int main(){
    AVLTree<int> tree;

    for(int i = 1; i < 11; i++){
        //tree.insert(i);
    }

    tree.inOrderPrint();
    cout << endl;
    cout << tree.treeHeight();


    //comment for testing git
    return 0;
}