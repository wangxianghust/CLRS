#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template<typename Container>
void print(const Container &con){
    for(auto beg=con.cbegin(); beg != con.cend(); ++beg){
        cout << *beg << " ";
    }
    cout << endl;
}

int Partition(vector<int> &A, int p, int r, int pivot){
    int small = p-1;
    int pivot_index;
    for(int j=p; j<=r; ++j){
        if(A[j] < pivot){
            swap(A[++small], A[j]);
        } else if(A[j] == pivot){
            swap(A[++small], A[j]);
            pivot_index = small;  // pivot_index <= small
        }
    }
    swap(A[pivot_index], A[small]);
    return small;        
}

int MedianIndex(int array_size){
    if(array_size & 0x1){
        return array_size/2;
    } else {
        return array_size/2-1;
    }
}

int Select(vector<int> &A, int p, int r, int kth){
    if(kth > r-p+1) return -1;
    if(r-p <= 1){
        return A[p];
    }
    // group
    vector<vector<int> > groups;
    for(int i=p; i<=r; i+=5){
        vector<int> tmp;
        for(int j=i; j<i+5 && j<=r; ++j){
            tmp.push_back(A[j]);
        }
        print(tmp);
        groups.push_back(tmp);
    }
    
    for(auto &g : groups){
        sort(g.begin(), g.end());
    }

    vector<int> medians;
    for(auto &g : groups){
        medians.push_back(g[MedianIndex(g.size())]);
    }

    int pivot = Select(medians, 0, medians.size()-1, MedianIndex(medians.size()));
    cout << " pivot " << pivot << endl;
    int q = Partition(A, p, r, pivot);
    int order_tmp = q-p+1;
    cout << "order_tmp " << order_tmp << endl;
    if(order_tmp == kth){
        return A[q];
    }

    if(order_tmp > kth){
        return Select(A, p, q-1, kth);
    } else {
        return Select(A, q+1, r, kth-order_tmp);
    }

}


int main(){
    vector<int> A{1,2,3,7,5,4,6,8,9,11,10,12};
    int kth;
    cout << " Input the kth " << endl;
    while(cin >> kth){
        int ret = Select(A, 0, A.size()-1, kth);
        cout << ret << endl;
        A = {1,2,3,7,5,4,6,8,9,11,10,12};
        print(A);
    }
}
