#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Node{    // Here we define left child is always smaller than right
    int value;
    Node *left;
    Node *right;

    Node(int v):value(v),left(nullptr),right(nullptr){};    // give the ways to initialize the node.
    Node(int v, Node* l, Node* r):value(v), left(l), right(r){};
    
};

int second_smallest(vector<int> &A){
    queue<Node*> q;         // we use pointer to manage the ndoes.
    for(auto ele : A){
        Node *node = new Node(ele);
        q.push(node);
    }

    Node* root(nullptr);
    while(!q.empty()){
        int size = q.size();
        if(1 == size){
            root = q.front();
            break;
        }

        for(int i=0; i<size; i+=2){
            if(i == size-1){
                Node *n1 = q.front();
                q.push(n1);
                q.pop();
                break;
            }
            Node *node1 = q.front();
            q.pop();
            Node *node2 = q.front();
            q.pop();
            if( node1->value < node2->value  ){
                Node* new_node = new Node(node1->value, node1, node2);
                q.push(new_node);
            } else {
                Node* new_node = new Node(node2->value, node2, node1);
                q.push(new_node);
            }
        }
    }

    int smallest = INT_MAX;
    while(root){                // firstly we test if root exist, then we can test whether it has child
        if(root->right && root->left){
            int test = root->right->value;
            if(test < smallest) smallest = test;
            root = root->left;
        } else break;
    }

    return smallest;
}

int main(){
    vector<int> v = {0,-2,1,2,3,4,5,6,7,-19};
    cout << second_smallest(v) << endl;
}
