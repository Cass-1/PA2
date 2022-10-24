#include "AVLTree.h"

int main(){
    AVLTree<int> tree;

    for(int i = 1; i < 11; i++){
        tree.insert(i);
    }

    tree.inOrderPrint();
    cout << endl;
    cout << tree.treeHeight();

    cout << tree.contains(100) <<tree.contains(8);
    cout << endl<< "Validate: " << tree.validate()<<endl;


    //comment for testing git
    return 0;
}