#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

template<typename T>
void print(vector<T> &A){
    for(auto i : A)
        cout << i << " ";
    cout << endl;
}

template<typename T>
void print(vector<T> &A, int count, string info){
    cout << "-----" << info << "-----" << endl;
    for(int i = 0; i < count; ++i)
        cout << A[i] << " ";
    cout << endl;
}


int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

int parent(int i){
    return (i-1)/2;
}

struct heap{
    heap(){}
    heap(vector<int> v, int size):vec(std::move(v)), heap_size(size) {}
    vector<int> vec;
    int heap_size;
};

void MinHeapity(heap &H, int i){
    vector<int> &A = H.vec;
    int l = left(i);
    int r = right(i);
    int smallest;
    if(A[l] < A[i] && l < H.heap_size){
        smallest = l;
    } else {
        smallest = i;
    }    

    if(A[r] < A[smallest] && r < H.heap_size){
        smallest = r;
    }
    
    if(smallest != i){
        swap(A[i], A[smallest]);
        MinHeapity(H, smallest);
    }
}

void BuildMinHeap(heap &H){
    int size = H.heap_size;
    for(int i = size/2; i >= 0; --i){
        MinHeapity(H, i);
    }
}

vector<int> HeapSort(vector<int> &A){
    heap H;
    H.vec = A;
    H.heap_size = A.size();
    BuildMinHeap(H);
    //print(H.vec);

    while(H.heap_size > 1){
        swap(H.vec[H.heap_size-1], H.vec[0]);
        --H.heap_size ;
        MinHeapity(H, 0);
        //print(H.vec);
    }
    return H.vec;
}

int HeapMin(heap &H){
    return H.vec[0];
}

int HeapExtractMin(heap &H){
    if(H.heap_size < 1) return -1;
    int key = H.vec[0];
    H.vec[0] = H.vec[H.heap_size-1];
    --H.heap_size;
    MinHeapity(H, 0);
    return key;
}

void HeapDesKey(heap &H, int i, int key){
    if(key > H.vec[i]){
        cout << "error, key is bigger than old" << endl;
        return ;
    }
    H.vec[i] = key;
    while(parent(i) >= 0 && H.vec[i] < H.vec[parent(i)]){
        swap(H.vec[i], H.vec[parent(i)]);
        i = parent(i);
        //print(H.vec);
    }
}

void MinHeapInsert(heap &H, int key){
    ++H.heap_size;
    H.vec[H.heap_size-1] = INT_MAX;
    HeapDesKey(H, H.heap_size-1, key);
}

void HeapDelete(heap &H, int i){
    int last = H.vec[H.heap_size-1];
    --H.heap_size;
    int delete_node = H.vec[i];
    H.vec[i] = last;
    if(last >= delete_node){
        MinHeapity(H, i);
    } else {
        HeapDesKey(H, i, last);
    }
}

struct node{
    node(int a=0): start(a), finish(0), id(0){}
    int start;
    int finish;
    int id;
};

bool cmp(node a, node b){
    return a.finish < b.finish;
}

void initial(vector<int> &start, vector<int> &finish, vector<node> &nodes){
    int size = start.size();
    for(int i=0; i<size; ++i){
        nodes[i].start = start[i];
        nodes[i].finish = finish[i];
        nodes[i].id = i;
    }
    sort(nodes.begin(), nodes.end(), cmp);
}

void Greedy(vector<node> &nodes){
    int size = nodes.size();
    vector<int> A;
    A.push_back(nodes[0].finish);
    heap H(A, A.size());
    for(int i=1; i<size; ++i){
        int start = nodes[i].start;
        if(start < HeapMin(H)){ //no room is satisfied the activity
            cout << "this is new room : " << nodes[i].finish << endl;
            MinHeapInsert(H, nodes[i].finish); // get a new room for this activity
        } else {
            // update the min element to new finish;
            HeapExtractMin(H);
            MinHeapInsert(H, nodes[i].finish);
        }   
    }
    cout << "we need classroom number is : " << H.heap_size << endl;
}


int main(){
    vector<int> start{1,3,0,5,3,5,6,8,8,2,12,17};
    vector<int> finish{4,5,6,7,9,9,10,11,12,14,16,18};
    int size = start.size();
    vector<node> nodes(size, node());
    initial(start, finish , nodes);

    Greedy(nodes);
}

