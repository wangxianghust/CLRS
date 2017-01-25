#include <iostream>
#include "MergeSort.cpp"
#include <utility>
using namespace std;

template<unsigned N>
pair<int,int> search(int (&A)[N], int value){
    int sum = 0;
    for(int i=0, j=N-1; i<j;){
        sum = A[i] + A[j];
        if(sum == value) return {A[i], A[j]};
        if(sum < value){
            ++i;
        } else {
            --j;
        }
    }
    return {-1,-1};
}

int main(){
    int A[] = {1,2,8,3,2,1};
    int size = sizeof(A)/sizeof(A[0]);
    MergeSort(A, 0, size-1);
    for(auto i : A){
        cout << i << endl;
    }
    auto ret = search(A, 110);
    cout << "The result :" << ret.first << " " << ret.second << endl;
}
