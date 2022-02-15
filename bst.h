#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T key);
        virtual ~TreeNode();

        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;

};

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        bool contains(T value);
        bool deleteNode(T k);
        bool isEmpty();
        // T calcSum();

        T* getMin();
        T* getMax();
        TreeNode<T> *getSuccessor(TreeNode<T> *d);
        void printNodes();
        void recPrint(TreeNode<T> *node);
        void depthFirstSearch(TreeNode<T> *node);
    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){
    
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }
    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
void BST<T>::printNodes(){
    recPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
T* BST<T>::getMin(){
    TreeNode<T> *current = root;
    if(isEmpty()){
        return NULL;
    }
    while (current->left!=NULL){
        current = current->left;
    }
    return &(current->key);
}

template <class T>
T* BST<T>::getMax(){
    TreeNode<T> *current = root;
    if(isEmpty()){
        return NULL;
    }
    while (current->right!=NULL){
        current = current->right;
    }
    return &(current->key);
}

template <class T>
void BST<T>::depthFirstSearch(TreeNode<T> *node, T seachVal){

}

void BST<T>::recursive


// template <class T>
// T BST<T>::calcSum(TreeNode<T> *node){
//     if(node == NULL){
//         return 0;
//     }
//     return (node->key + calcSum(node->left)+calcSum(node->right));
// }

template <class T>
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);
    if (isEmpty()){
        root = node;
    }
    else{
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        while (true){
            parent = current;
            if (value < current->key){
                current = current->left;
                if(current == NULL){
                    parent -> left = node;
                    break;
                }
            }
            else{
                current = current -> right;
                if(current == NULL){
                    parent -> right = node;
                    break;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::contains(T value){
    if(isEmpty()){
        return false;
    }
    else{
        TreeNode<T> *current = root;
        while (current->key != value){
            if (value <current-> key){
                current = current -> left;
            }
            else{
                current = current -> right;
            }
            if (current == NULL){
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool BST<T>::deleteNode(T k){
    if (isEmpty()){
        return false;
    }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;
    while(current->key != k){
        parent = current;
        if(k < current->key){
            isLeft = true;
            current = current -> left;
        }
        else{
            isLeft = false;
            current = current -> right;
        }
        if (current == NULL){
            return false;
        }
    }
    if (current->left == NULL && current->right == NULL){
        //no children
        if(current == root){
            root == NULL;
        }
        else if (isLeft){
            parent -> left = NULL;
        }
        else{
            parent -> right = NULL;
        }
    }
    else if (current->right == NULL){
        //doesn't have right child
        if(current == root){
            root = current->left;
        }
        else if (isLeft){
            parent -> left = current->left;
        }
        else{
            parent -> right = current->left;
        }
    }
    else if (current->left == NULL){
        //doesn't have left child
        if(current == root){
            root = current->right;
        }
        else if (isLeft){
            parent -> left = current->right;
        }
        else{
            parent -> right = current->right;
        }
    }
    else{
        TreeNode<T> *successor = getSuccessor(current);
        if (current == root){
            root = successor;
        }
        else if (isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }
        successor->left = current ->left;
        current ->left = NULL;
        current ->right = NULL;
    }
    return true;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;
    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    if (successor!= d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

#endif