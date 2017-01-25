#include <iostream>
using namespace std;

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

template<unsigned M>
void max_heapity(int (&A)[M], int i, int size){  // here size is the heap size
    int l = left(i);
    int r = right(i);
    int largest;
    if((l <= size) && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }
    if((r <= size) && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        swap(A[largest], A[i]);
        max_heapity(A, largest, size);
    }
}

template<unsigned M>
void build_max_heap(int (&A)[M]){
    int size = M - 1;
    for(int i = size/2; i >= 1; --i){
        max_heapity(A, i, size);
    }
}

template<unsigned P>
void heap_sort(int (&A)[P]){
    build_max_heap(A);
    int size = P - 1;
    for(int i = size; i > 1; --i){
        swap(A[i], A[1]);
        max_heapity(A, 1, i-1);
    }
}

template<typename T>
T heap_maxmimum(T A[]){
    return A[1];
}

template<typename T, unsigned N>
T heap_extral_max(T (&A)[N], int size){
    if(size < 1) return -1;
    T key = A[1];
    int new_size = size - 1;
    swap(A[1], A[size]);
    max_heapity(A, 1, new_size);
    return key;
}

int main(){
    int A[] = {0,1,4,2,1,6,90,2,11,22,13,567,32,3};
    int size = sizeof(A)/sizeof(A[0]);
    build_max_heap(A);
    cout << "heap max is " << heap_maxmimum(A) << endl;
    auto max = heap_extral_max(A, size-1);
    cout << "heap_extral_max is " << max << endl;
    cout << "heap sort is " << endl;
    heap_sort(A);
    for(auto i : A) cout << i << endl;
}
