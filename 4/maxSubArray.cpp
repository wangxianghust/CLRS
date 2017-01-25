#include <iostream>
using namespace std;
#include <vector>

template<unsigned M>
vector<int> find_max_crossing_subarray(int (&A)[M], int low, int mid, int high){
    int left_sum = -100000;
    int sum = 0;
    int max_left = mid;
    for(int i = mid; i >= low; --i){
        sum += A[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -100000;
    sum = 0;
    int max_right = mid + 1;
    for(int i = mid+1; i <= high; ++i){
        sum += A[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }

    vector<int> v{max_left, max_right, left_sum+right_sum};
    return v;
}

template<unsigned N>
vector<int> find_max_subarray(int (&A)[N],int low, int high){
    if(low == high){
        vector<int> v{low, high, A[low]};
        return v;
    } 
    else{
        int mid = (low + high) / 2;
        vector<int> left = find_max_subarray(A, low, mid);
        vector<int> right = find_max_subarray(A, mid + 1, high);
        vector<int> cross = find_max_crossing_subarray(A, low, mid, high);
        if(left[2] >= right[2] && left[2] >= cross[2]){
            return left;
        } else if(right[2] >= left[2] && right[2] >= cross[2]){
            return right;
        } else {
            return cross;
        }
    }
}


int main(){
    int Aa[] = {3,-2,1,6,-1,2};
    int A[] = {-1,-2,-3,-6,-9};
    int size = sizeof(A)/sizeof(A[0]);
    auto ret = find_max_subarray(A, 0, size-1);
    for(auto i : ret)
        cout << i << endl;
}
