#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stack>

using namespace std;

struct node;
using T = shared_ptr<node>;
struct node{
    node(int data): key(data), left(0), right(0) {}
    int key;
    T left;
    T right;
};

void print(vector<int> &ret, string info=""){
    cout << info << endl;
    for(auto i:ret){
        cout << i << "---";
    }
    cout << endl;
}
vector<int> InOrderWalk(T root){
    vector<int> ret;
    if(!root) return ret; 
    T cur = root;
    stack<T> sta;

    while(cur || !sta.empty()){
        while(cur){
            sta.push(cur);
            cur = cur->left;
        }
        cur = sta.top();
        sta.pop();
        ret.push_back(cur->key);
        cur = cur->right;
    }
    print(ret, "InOrderWalk using stack");
    return ret;
}

int main(){
    T root = make_shared<node> (10);
    T l = make_shared<node> (4);
    T r = make_shared<node> (17);
    T ll = make_shared<node> (1);
    T lr = make_shared<node> (5);
    T rl = make_shared<node> (16);
    T rr = make_shared<node> (21);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;
    r->left = rl;
    r->right = rr;

    InOrderWalk(root);
}
