#include <iostream>
using namespace std;

template<unsigned N>
int BinaySearch(int (&A)[N], int value){
    int low = 0;
    int high = N;
    while(low <= high){
        int mid = (low + high)/2;
        if(A[mid] == value) return mid;
        if(A[mid] < value){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

template<unsigned M>
int BinaySearch(int (&A)[M], int low, int high, int value){
    if(low > high)return -1;
    int  mid = (low + high)/2;
    if(A[mid] == value) return mid;
    if(A[mid] > value){
        return BinaySearch(A, low, mid-1, value);
    } else {
        return BinaySearch(A, mid+1, high, value);
    }
}

int main(){
    int A[] = {1,2,3,4,5,6,7};
    cout << BinaySearch(A,3) << endl;
    cout << BinaySearch(A,8) << endl;
    cout << BinaySearch(A,0,7,5) << endl;
    cout << BinaySearch(A,0,7,9) << endl;
}
