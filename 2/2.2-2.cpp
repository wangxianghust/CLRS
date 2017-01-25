#include <iostream>
using namespace std;

template<unsigned M>
void sort(int (&A)[M]){
    for(int j = 0; j < M; ++j){
        int index = j;
        int maxValue = A[j];
        for(int i = j+1; i < M; ++i){
            if(A[i] > maxValue){
                maxValue = A[i];
                index = i;
            }
        }
        A[index] = A[j];
        A[j] = maxValue;
    }
}

int main(){
    int A[] = {1,4,2,1,7,8,90,34,2,42};
    sort(A);
    for(auto i : A){
        cout << i << endl;
    }
}
