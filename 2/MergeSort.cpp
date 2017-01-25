#include <iostream>
using namespace std;

template<unsigned M>
void Merge(int (&A)[M], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1];
    int R[n2+1];
    for(int i=0; i < n1; ++i){
        L[i] = A[p+i];
    }
    L[n1] = 100000; // the end sign;
    for(int j = 0; j < n2; ++j){
        R[j] = A[q+j+1];
    }
    R[n2] = 100000;
    
    int i=0;
    int j=0;
    for(int k=p; k<r+1; ++k){
        if(L[i] <= R[j]){
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }

    /// for test recurcive loop
    for(int k=p; k<r+1; ++k){
        cout << A[k] << "---";
    }
}

void print(const int* beg, const int* end){
    while (beg != end){
        cout << *beg++ << "-->";
    }    
}

template<unsigned N>
void MergeSort(int (&A)[N], int p, int r){
    if(p < r){
        int q = (p+r)/2;
        cout << "MergeSort" << endl;
        MergeSort(A, p, q);
        cout << "sort L" << endl;
        cout << endl;
        print( begin(A), end(A) );
        cout << endl;
        MergeSort(A, q+1, r);
        cout << "sort R" << endl;
        Merge(A, p, q, r);
        cout << "merge L&R" << endl;
    }
}
/*
int main(){
    //int A[] = {3,1,2,5,0,7,90,78,1,1};
    int A[] = {1,3,2,5,0};
    int size = sizeof(A)/sizeof(A[0]);
    MergeSort(A, 0, size-1);
}
*/
