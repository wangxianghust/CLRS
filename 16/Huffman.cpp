// reference : http://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct node{
    node():id(0), name(' '), f(0), left(nullptr), right(nullptr) {}
    node(int i, char n, unsigned _f):id(i), name(n), f(_f) {}
    int id;
    char name;
    unsigned f;
    node* left;
    node* right;
};

struct cmp{
    bool operator()(node *a, node *b){  //modify the compare function, the small f is priori than big here.
        return a->f > b->f;
    }
};

void initial(vector<char> &name, vector<unsigned> &fre, vector<node> &nodes){
    int size = name.size();
    for(int i=0; i<size; ++i){
        nodes[i].id = i;
        nodes[i].name = name[i];
        nodes[i].f = fre[i];
    }
}

void printTree(node* root, string str){
    if(!root) return;
    if(root->name != '$'){
        cout << root->name << " : " << str << endl;
        //cout << root->name << " : " << str << " " << root->id  << endl;
    }

    printTree(root->left, str+"0");
    printTree(root->right, str+"1");

}

void Huffman(vector<char> &name, vector<unsigned> &fre){
    int size = name.size();
    vector<node> nodes(size);
    initial(name, fre, nodes);

    std::priority_queue<node*, vector<node*>, cmp> pq;
    for(int i=0; i<size; ++i){
        pq.push(new node(nodes[i])); //when we use a pointer, we should new it to allocate the memory.
    }
    
    int id = size;
    node *parent, *left, *right;
    while(pq.size() != 1){
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        
        parent = new node(id++, '$', left->f + right->f);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    printTree(pq.top(), "");
}

int main(){
    //vector<char> name{ 'a', 'b', 'c', 'd', 'e', 'f' };
    //vector<unsigned> fre{ 5, 9, 12, 13, 16, 45 };
    vector<char> name{ 'a', 'b', 'c', 'd', 'e', 'f' , 'g', 'h'};
    vector<unsigned> fre{1,1,2,3,5,8,13,21};
    Huffman(name, fre);
}
