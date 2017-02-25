#include <iostream>

using namespace std;

struct node{
    node(int d):key(d), left(0), right(0), parent(0) {}
    int key;
    node* left;
    node* right;
    node* parent;
};

node* Minimum(node* root){
    if(root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    return nullptr;
}

node* Minmum_recur(node* root){
    if(root){
        if(!root->left){
            return root;
        }
        return Minmum_recur(root->left);
    }
    return nullptr;
}

node* Successor(node* x){
    if(x->right){
        return Minimum(x->right);
    }
    node* y = x->parent;
    while(y != nullptr && y->right == x){
        x = y;
        y = x->parent;
    }
    return y;
}

int main(){
    node* root = new node(6);
    node* l = new node(4);
    node* ll = new node(2);
    node* lr = new node(5);
    node* r = new node(7);
    node* rr = new node(8);
    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;
    r->right = rr;
    l->parent = root;
    r->parent = root;
    lr->parent = l;
    ll->parent = l;
    rr->parent = r;

    int min = Minimum(root)->key;
    cout << min << endl;
    cout << "min, recur " << Minmum_recur(root)->key << endl;

    cout << "Successor " << lr->key << " " << Successor(lr)->key << endl;
    
}
