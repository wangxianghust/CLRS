#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int Partition(vector<T> &A, int p, int r);

template<typename T> 
void print(const T &contain);

template<typename T>
void QuickSort(vector<T> &A, int p, int r){
    if(p < r){
        int q = Partition(A, p, r);
        QuickSort(A, p, q);
        QuickSort(A, q+1, r);
    }
}

template<typename T>
int Partition(vector<T> &A, int p, int r){
    T pivot = A[p];
    int i = p-1;
    int j = r+1;
    while(1){
        while(A[--j] > pivot);
        while(A[++i] < pivot);
        if(i < j) 
            swap(A[i], A[j]);
        else 
            return j;
    }
}

template<typename T> 
void print(const T &contain){
    for(auto begin = contain.cbegin(); begin != contain.cend(); ++ begin){
        cout << *begin << "  ";
    }
    cout << endl;
}

int main(){
    vector<int> A{50,1,2,3,89,6,3,43,3,23,3,54,100,0};
    QuickSort(A, 0, A.size()-1);
    print(A);
}

