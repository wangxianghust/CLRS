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
        print(A);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

template<typename T>
int Partition(vector<T> &A, int p, int r){
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
    return small;
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
