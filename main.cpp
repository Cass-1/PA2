#include "AVLTree.h"

#include <vector>
#include <algorithm>
#include <random>

using std::vector;
using std::shuffle;

int main(){
    //setting up the forwards vector
    vector<int> oddForwards = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63,65,67,69,71,73,75,77,79,81,83,85,87,89,91,93,95,97,99};

    //set up the backwards vector
    vector<int> oddBackwards;
    for (int i = 49; i > -1; i--){
        oddBackwards.push_back(oddForwards.at(i));
    }

    //setting up the random vector
    vector<int> oddRandom = oddForwards;
    auto rng = std::default_random_engine {};
    shuffle(std::begin(oddRandom), std::end(oddRandom), rng);

    //inserting into the avltrees
    AVLTree<int> oddFor;
    for(auto& item: oddForwards){
        oddFor.insert(item);
    }
    AVLTree<int> oddBack;
    for(auto& item : oddBackwards){
        oddBack.insert(item);
    }
    AVLTree<int> oddRand;
    for(auto& item : oddRandom){
        oddRand.insert(item);
    }

    int hForward = oddFor.treeHeight();
    int hBackwards = oddBack.treeHeight();
    int hRandom = oddRand.treeHeight();

    cout << "The height of the acending order odd number avl tree is: " << hForward << endl;
    cout << "The height of the decending order odd number avl tree is: " << hBackwards << endl;
    cout << "The height of the shuffled order odd number avl tree is: " << hRandom << endl;

    int vForward = oddFor.validate();
    int vBackwards = oddBack.validate();
    int vRandom = oddRand.validate();

    cout << "The result of validate for the acending order odd number avl tree is: " << vForward << endl;
    cout << "The result of validate for the decending order odd number avl tree is: " << vBackwards << endl;
    cout << "The result of validate for the shuffled order odd number avl tree is: " << vRandom << endl;

    cout << "Contains for the acending order odd number avl tree are: ";
    for (int i = 1; i < 101; i++){
        if(i % 2 == 0 && oddFor.contains(i) == 1){
            cout << "MY AVL tree implementation is wrong ";
        }
        else if(i % 2 == 01&& oddFor.contains(i) == 0){
            cout << "MY AVL tree implementation is wrong ";
        }
        else{
            cout << oddFor.contains(i) << " ";
        }
    }

    cout << endl;

    cout << "Contains for the decending order odd number avl tree are: ";
    for (int i = 1; i < 101; i++){
        if(i % 2 == 0 && oddBack.contains(i) == 1){
            cout << "MY AVL tree implementation is wrong ";
        }
        else if(i % 2 == 01&& oddBack.contains(i) == 0){
            cout << "MY AVL tree implementation is wrong ";
        }
        else{
            cout << oddBack.contains(i) << " ";
        }
    }

    cout << endl;

    cout << "Contains for the shuffled order odd number avl tree are: ";
    for (int i = 1; i < 101; i++){
        if(i % 2 == 0 && oddRand.contains(i) == 1){
            cout << "MY AVL tree implementation is wrong ";
        }
        else if(i % 2 == 01&& oddRand.contains(i) == 0){
            cout << "MY AVL tree implementation is wrong ";
        }
        else{
            cout << oddRand.contains(i) << " ";
        }
    }
    //cout << ""<< endl;




    /*AVLTree<int> tree;

    for(int i = 1; i < 11; i++){
        tree.insert(i);
    }

    tree.inOrderPrint();
    cout << endl;
    cout << tree.treeHeight();

    cout << tree.contains(100) <<tree.contains(8);
    cout << endl<< "Validate: " << tree.validate()<<endl;*/


    //comment for testing git
    return 0;
}