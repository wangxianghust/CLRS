#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int d_ary = 3;

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

int get_child(int parent, int order){
    return parent*d_ary + order;
}

int get_parent(int child){
    return (child - 1)/d_ary;
}

struct heap{
    heap(){}
    heap(vector<int> v, int size):vec(std::move(v)), heap_size(size) {}
    vector<int> vec;
    int heap_size;
};

void MinHeapity(heap &H, int parent){
    vector<int> &A = H.vec;
    vector<int> tmp;
    for(int order=1; order<=d_ary && get_child(parent, order) < H.heap_size; ++order){
        int child = get_child(parent, order);
        tmp.push_back(A[child]);
    }
    tmp.push_back(A[parent]);
    auto min_ele_iterator = min_element(tmp.begin(), tmp.end());
    int min_ele = *min_ele_iterator;
    if(min_ele != A[parent]){
        int order = min_ele_iterator - tmp.begin() + 1;
        int min_index = get_child(parent, order);
        swap(A[min_index], A[parent]);
        MinHeapity(H, min_index);
    }
}

void BuildMinHeap(heap &H){
    int size = H.heap_size;
    for(int i = (size + 1)/d_ary; i >= 0; --i){
        MinHeapity(H,i);
    }
}

vector<int> HeapSort(vector<int> &A){
    heap H;
    H.vec = A;
    H.heap_size = A.size();
    BuildMinHeap(H);
    
    while(H.heap_size > 1){
        swap(H.vec[H.heap_size], H.vec[0]);
        --H.heap_size;
        MinHeapity(H, 0);
    }
    return H.vec;
}

int HeapMin(heap &H){
    return H.vec[0];
}

int HeapExtractMin(heap &H){
    if(H.heap_size < 1) return -1;
    int key = H.vec[0];
    H.vec[0] = H.vec[H.heap_size - 1];
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
    while(get_parent(i) >= 0 && H.vec[i] < H.vec[get_parent(i)]){
        swap(H.vec[i], H.vec[get_parent(i)]);
        i = get_parent(i);
    }
}

void MinHeapInsert(heap &H, int key){
    ++H.heap_size;
    H.vec[H.heap_size-1] = INT_MAX;
    HeapDesKey(H, H.heap_size-1, key);
}


int main(){
    vector<int> A = {10,2,6,53,81,90,23,45,2,12};
    auto ret = HeapSort(A);
    print(ret);
    heap H(A, A.size());
    BuildMinHeap(H);
    print(H.vec);
    cout << HeapMin(H) << endl;
    cout << HeapExtractMin(H) << endl;
    print(H.vec, H.heap_size, "state");
    HeapDesKey(H, 5, 0);
    MinHeapInsert(H, -2);
    print(H.vec, H.heap_size, "MinHeapInsert");

    //HeapDelete(H, 8);
    //print(H.vec, H.heap_size, "Delete 81");
    //HeapDelete(H, 0);
    //print(H.vec, H.heap_size, "Delete 0");
    
}
