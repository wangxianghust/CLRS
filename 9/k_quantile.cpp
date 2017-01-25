// for exercise 9.3-6, now still have bugs.
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// return the order-th of the array
int Partition(vector<int> &A, int p, int r, int pivot){
    auto piv = find(A.begin()+p-1, A.end(), pivot);
    int pivot_index = piv - A.begin(); 
    swap(A[r], A[pivot_index]);

    int small = p-1;
    for(int j=p; j<r; ++j){
        if(A[j] <= A[r]){
            swap(A[++small], A[j]);
        }
    }
    ++small;
    swap(A[small], A[r]);
    return small;
}

int MedianIndex(int array_size){
    if(array_size & 0x1){
        return array_size/2;
    } else {
        return array_size/2-1;
    }
}

// return the order-th of the array A
int Select(vector<int> &A, int p, int r, int order){
    if(order > r-p+1) return -1;
    if(r-p <= 1){
        return A[p];
    }

    int size = r-p+1;

    vector<vector<int> > groups;
    for(int i=p; i<r; i+=5){
        vector<int> tmp;
        for(int j=i; j<i+5 && j<r; ++j){
            tmp.push_back(A[j]);
        }
        groups.push_back(tmp);
    }

    
    //sort the group
    for(auto &g : groups){
        sort(g.begin(), g.end());
    }

    // get the pivot: the median of all group medians
    vector<int> medians;
    for(auto &g : groups){
        medians.push_back(g[MedianIndex(g.size())]);
    }
    int pivot = Select(medians, 0, medians.size()-1, MedianIndex(medians.size()));
    int q = Partition(A, p, r, pivot); 
    int order_tmp = q-p+1;
    if(order_tmp == order){
        return A[q];
    }

    if(order_tmp > order){
        return Select(A, p, q-1, order);
    } else {
        return Select(A, q+1, r, order-order_tmp);
    }

}

vector<int> joinVec(vector<int> &A, vector<int> &B, vector<int> &C){
    vector<int> ret;
    ret.insert(ret.end(), C.begin(), C.end());
    ret.insert(ret.end(), B.begin(), B.end());
    ret.insert(ret.end(), A.begin(), A.end());
    return ret;
}

vector<int> kQuantile(vector<int> &A, int p, int r, int k){
    if(1 == k) return vector<int>();
    vector<int> ret;
    int n = r-p+1;
    if(k & 0x1){   // k is odd, we take two elements to split the array
        int left_order = ceil( (k/2)*(n*1.0/k) ) - 1;
        int right_order = n - left_order -1;

        int left_item = Select(A, p, r, left_order); // the left_order element 
        int right_item = Select(A, p, r, right_order);

        int left_index = Partition(A, p, r, left_item);
        int right_index = Partition(A, p, r, right_item);

        auto left_elements = kQuantile(A, p, left_index-1, k/2);
        auto right_elements = kQuantile(A, right_index+1, r,  k/2);

        ret.push_back(left_item);
        ret.push_back(right_item);

        return joinVec(left_elements, ret, right_elements);
    } else {
        int order = ceil(n/2) - 1;
        int item = Select(A, p, r, order);
        int index = Partition(A, p, r, item);
        ret.push_back(item);
        
        auto l_ele = kQuantile(A, p, index-1,k/2);
        auto r_ele = kQuantile(A, index+1, r, k/2);
        return joinVec(l_ele, ret, r_ele);
    }
}

void print(const vector<int> &A){
    for(auto i : A){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> A{1,2,3,4,5,6,7};
    auto ret = kQuantile(A, 0, A.size(), 3);
    print(ret);
}
