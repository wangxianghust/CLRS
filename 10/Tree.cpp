#include <iostream>
#include <vector>
#include <memory>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
struct node;

using T = shared_ptr<node>; 
struct node{
    node(int data):key(data), left(nullptr), right(nullptr) {}
    int key;
    T left;
    T right;
};

void print(vector<int> &ret, string info){
    cout << info << endl;
    for(auto i: ret){
        cout << i << "--->";
    }
    cout << endl;
}

void PreOrder(T root){
    if(!root) return;
    cout << root->key << "---";
    PreOrder(root->left);
    PreOrder(root->right);
}

vector<int> PreOrderIter(T root){
    vector<int> ret;
    stack<T> wait_to_visit;
    if(!root) return ret;
    wait_to_visit.push(root);
    while(! wait_to_visit.empty()){
        root = wait_to_visit.top();
        wait_to_visit.pop();
        ret.push_back(root->key);
        if(root->right){
            wait_to_visit.push(root->right);
        }

        if(root->left){
            wait_to_visit.push(root->left);
        }
    }
    print(ret, "PreOrderIter");
    return ret;
}

void InOrder(T root){
    if(!root) return;
    InOrder(root->left);
    cout << root->key << "---";
    InOrder(root->right);
}

vector<int> InOrderIter(T root){
    vector<int> ret;
    stack<T> wait_to_visit;
    if(! root) return ret;
    T current_node = root;

    while(current_node || !wait_to_visit.empty()){
        while(current_node){
            wait_to_visit.push(current_node);
            current_node = current_node->left;
        }
        current_node = wait_to_visit.top();
        ret.push_back(current_node->key);
        wait_to_visit.pop();  
        current_node = current_node->right;
    }
    print(ret, "InOrderIter");
    return ret;
}

void PostOrder(T root){
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->key << "---";
}

vector<int> PostOrderIter(T root){
    vector<int> ret;
    stack<T> wait_to_visit;
    if(!root) return ret;
    wait_to_visit.push(root);

    while(! wait_to_visit.empty()){
        root = wait_to_visit.top();
        wait_to_visit.pop();
        ret.push_back(root->key);

        if(root->left) wait_to_visit.push(root->left);
        if(root->right) wait_to_visit.push(root->right);
    }
    reverse(ret.begin(), ret.end());
    print(ret, "PostOrderIter");
    return ret;
}

int main(){
    T root = make_shared<node>(1); 
    root->left = make_shared<node>(2);
    root->right = make_shared<node>(3);
    T a = make_shared<node>(4);
    T b = make_shared<node>(5);
    root->left->left = a;
    root->left->right = b;
    PreOrder(root);
    cout << " PreOrder " << endl;
    PreOrderIter(root);
    InOrder(root);
    cout << " InOrder " << endl;
    InOrderIter(root);
    PostOrder(root);
    cout << " PostOrder " << endl;
    PostOrderIter(root);

}
