#include <iostream>
#include <vector>
#include <climits>

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

int HeapExtractMax(heap &H){
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

int main(){
    vector<int> A = {10,2,6,53,81,90,23,45,2,12};
    auto ret = HeapSort(A);
    //print(ret);
    heap H(A, A.size());
    BuildMinHeap(H);
    print(H.vec);
    cout << HeapMin(H) << endl;
    cout << HeapExtractMax(H) << endl;
    print(H.vec, H.heap_size, "state");
    HeapDesKey(H, 5, 0);
    MinHeapInsert(H, -2);
    print(H.vec, H.heap_size, "MinHeapInsert");

    HeapDelete(H, 8);
    print(H.vec, H.heap_size, "Delete 81");
    HeapDelete(H, 0);
    print(H.vec, H.heap_size, "Delete 0");
    
}
