#include <iostream>
#include <vector>

using namespace std;

int search(int l, int r, vector<int> &A, int key){
    while(r - l > 1){
        int mid = (l + r)/2;
        if(A[mid] >= key){
            r = mid;
        } else {
            l = mid;
        }
    }
    return r; //the ceil of the location.
}

int EfficientLCS(vector<int> &A){
    int size = A.size();
    if(size == 0) return 0;
    // tail means, the index and value map, index+1 is the string length, value is the end value of correspond length.
    vector<int> tail(size, 0);
    tail[0] = A[0];
    int length = 1;
    for(int i=1; i<size; ++i){
        if(A[i] > tail[length-1]){
            tail[length++] = A[i];
        } else if(A[i] < tail[0]){
            tail[0] = A[i];
        } else {
            int index = search(0, length-1, tail, A[i]);
            tail[index] = A[i];
        }
    }
    return length;
}

int main(){
    vector<int> A{2,5,3,7,11,8,10,13,6};
    //vector<int> A{2,5,3,7,11};
    cout << "Length of Longest Increasing Subsequence is " << EfficientLCS(A) << endl;
}
