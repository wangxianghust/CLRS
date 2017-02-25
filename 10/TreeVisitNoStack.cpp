#include <iostream>
#include <memory>
#include <string>

using namespace std;
struct node;

using T = shared_ptr<node>;
struct node{
    node(int data):key(data), left(0), right(0), parent(0) {}
    int key;
    T left;
    T right;
    T parent;
};

//The visiting order is : root---> left ---> right
void TreeVisitNoStack(T root){
    T pre = 0;
    while(root){
        if(pre == root->parent){
            cout << root->key << " --- ";
            pre = root;
            if(root->left){
                root = root->left;
            } else if(root->right){
                root = root->right;
            } else {
                root = root->parent; //this denotes that we visit all the subtree of a node, and then 
                                     //current node go back to its parent, and visit the right child of parent.
            }
        } else if(pre == root->left && root->right){//we handle the recursive situation, 2 cases: one is that parent
            pre = root;                       //have the right child, and we visit it as a new root
            root = root->right;
        } else {                // case 2: we just recursive again.
            pre = root;
            root = root->parent;  
        } 
    }
    cout << endl;
}

void PreOrder(T root){
    if(!root) return;
    cout << root->key << "---";
    PreOrder(root->left);
    PreOrder(root->right);
}


int main(){
    T root = make_shared<node>(1); 
    T l = make_shared<node>(2);
    T r = make_shared<node>(3);
    T ll = make_shared<node>(4);
    T lr = make_shared<node>(5);
    root->left = l;
    l->parent = root;
    root->right = r;
    r->parent = root;

    l->left = ll;
    ll->parent = l;
    l->right = lr;
    lr->parent = l;
    
    TreeVisitNoStack(root);
    cout << "top is no stack , bottom is recursive" << endl;
    PreOrder(root);
}
