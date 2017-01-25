// for problem 8-2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &A);

void InPlaceCS(vector<int> &A){
    int size = A.size();
    int max = *max_element(A.begin(), A.end());
    vector<int> Count(max+1);

    for(int i=0; i<size; ++i){
        ++Count[A[i]];
    }
    for(int i=1; i<=max; ++i){
        Count[i] = Count[i] + Count[i-1];
    }

    for(int i=size-1, j=1; j<size; ++j){
        // one iteration get one right location, so we only need
        // size-1 iterations, no more or will get the wrong index of Count;
        int index = Count[A[i]]-1;
        --Count[A[i]];
        if(index != i){
            swap(A[index], A[i]);
        } else {
            --i;
        }
    }
}

void print(vector<int> &A){
    for(auto i : A){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> A{1,2,6,3,10,4,3,100,12,5};
    print(A);
    InPlaceCS(A);
    print(A);
}
