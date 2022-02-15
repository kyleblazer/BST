#include "bst.h"

using namespace std;

int main(int argc, char **argv){
    BST<char> *B = new BST<char>();
    B->insert('c');
    B->insert('j');
    B->insert('i');
    B->insert('k');
    B->insert('p');
    B->insert('a');
    B->insert('g');
    B->insert('h');
    B->insert('q');
    B->insert('w');
    B->printNodes();
    delete B;
}