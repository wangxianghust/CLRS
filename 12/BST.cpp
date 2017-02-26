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

void InOrderWalk(node* root){
    if(!root) return;
    InOrderWalk(root->left);
    cout << root->key << " --- ";
    InOrderWalk(root->right);
}

void Insert(node* root, node* z){
    node* y = nullptr;  //save the current node which is the parent of z in the future.
    while(root){
        y = root;
        if(z->key > y->key){
            root = root->right;
        } else {
            root = root->left;
        }
    }
    z->parent = y;
    if(y == nullptr){
        root = z; //in this case, T is null.
    } else if(z->key > y->key){
        y->right = z;
    } else {
        y->left = z;
    }
}

void InsertRecur(node* root, node* z){
    if(root){
        if(!root->left && z->key < root->key){
            z->parent = root;
            root->left = z;
            return;
        }
        if(!root->right && z->key > root->key){
            z->parent = root;
            root->right = z;
            return;
        }
        if(z->key > root->key) return InsertRecur(root->right, z);
        if(z->key < root->key) return InsertRecur(root->left,z);
    }
    root = z;
}

void Transplant(node* root, node* u, node* v){ //use v to replace u
    if(!root) root = v;
    else if(u == u->parent->left){
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if(v){
        v->parent = u->parent;
    }
}
void Delete(node* root, node* z){
    if(root){
        if(z->left == nullptr){
            Transplant(root, z, z->right);
        } else if(z->right == nullptr){
            Transplant(root, z, z->left);
        } else {
            node* y = Minimum(z->right);
            if(y->parent != z) {//y->parent == z, y has no left child, then z->left can be y->left;
                Transplant(root, y, y->right); //make space of right tree for next operation.
                //hanle the y right subtree.
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(root, z, y);
            y->left = z->left;
            z->left->parent = y;        
        }
    }
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
    InOrderWalk(root);
    cout << endl;

    Insert(root, new node(1));
    InOrderWalk(root); 
    cout << endl;

    InsertRecur(root, new node(10));
    InOrderWalk(root);
    cout << endl;

    Delete(root, l);
    Delete(root, ll);
    InOrderWalk(root);
    cout << endl;
    
}
