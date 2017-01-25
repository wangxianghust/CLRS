#include <iostream>
#include <vector>
#include <utility>
#include <random>

using namespace std;

template<typename T>
pair<int, int> Partition(vector<T> &A, int p, int r);

template<typename T> 
void print(const T &contain);

template<typename T>
pair<int,int> RandPartition(vector<T> &A, int p, int r);

template<typename T>
void QuickSort(vector<T> &A, int p, int r){
    if(p < r){
        pair<int, int> ret = RandPartition(A, p, r);
        QuickSort(A, p, ret.first-1);
        QuickSort(A, ret.second+1, r);
    }
}

template<typename T>
pair<int,int> Partition(vector<T> &A, int p, int r){
    T pivot = A[r];
    int small = p-1;
    int j;
    for(j = p; j < r; ++j){
        if(A[j] <= pivot){
            ++small;
            swap(A[small], A[j]);
        }
    }
    swap(A[++small], A[r]);

    int m = p - 1;
    int n = small;
    while(1){
        while( (m <= small) && (A[++m] != pivot) );
        while( (n >= p) && (A[--n] == pivot) );
        if(m < n) 
            swap(A[m], A[n]);
        else 
            return {n+1, small};
    }
}


template<typename T>
pair<int,int> RandPartition(vector<T> &A, int p, int r){
    uniform_int_distribution<int> u(p,r);
    default_random_engine e;
    int i = u(e);
    swap(A[i], A[r]);
    return Partition(A, p, r);
}

template<typename T> 
void print(const T &contain){
    for(auto begin = contain.cbegin(); begin != contain.cend(); ++ begin){
        cout << *begin << "  ";
    }
    cout << endl;
}

int main(){
    vector<int> A{50,1,2,3,89,6,3,43,3,23,3,54,100,0,100,100,10,101,10,10,10};
    QuickSort(A, 0, A.size()-1);
    print(A);
}


