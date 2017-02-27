#include <iostream>

using namespace std;

struct node{
    node(int d):key(d), left(0), right(0), parent(0){}
    int key;
    node* left;
    node* right;
    node* parent;
};

struct tree{
    tree(node* t):root(t){}
    node* root;
};

void LeftRotate(tree* t, node* x){
    if(! x->right) return;
    node* y = x->right;  //then we can handle the x and y seperately.
    x->right = y->left;
    if(y->left) y->left->parent = x;
    
    y->parent = x->parent;
    if(! x->parent) t->root = y;
    else if(x == x->parent->left) y = x->parent->left;
    else y = x->parent->right;

    y->left = x;
    x->parent = y;
}

void RightRotate(tree* t, node* x){
    if(! x->left) return;
    node* y = x->left;
    x->left = y->right;
    if(y->right) y->right->parent = x;

    y->parent = x->parent;
    if(!x->parent) t->root = y;
    else if(x == x->parent->left) y = x->parent->left;
    else y = x->parent->right;

    y->right = x;
    x->parent = y;
}

void print(node* root){
    if(! root)return;
    if(root->left)
        print(root->left);
    cout << root->key << "  ";
    if(root->right)
        print(root->right);
}

void PreOrder(node* root){
    if(! root) return;
    cout << root->key << "  ";
    if(root->left) PreOrder(root->left);
    if(root->right) PreOrder(root->right);
}

int main(){
    node* root = new node(5);
    node* afa = new node(3);
    node* y = new node(8);
    node* beta = new node(6);
    node* gama = new node(9);
    tree* t = new tree(root);
    root->left = afa;
    afa->parent = root;
    root->right = y;
    y->parent = root;
    y->left = beta;
    beta->parent = y;
    y->right = gama;
    gama->parent = y;

    print(t->root);
    LeftRotate(t, t->root);
    cout << "---LeftRotate,InOrder, the BST property is held---" << endl;
    print(t->root);
    cout << endl << "---PreOrder, It is really rotated---" << endl;
    PreOrder(t->root);
    cout << endl << "---RightRotate---" << endl;
    RightRotate(t, t->root);
    PreOrder(t->root);
}
