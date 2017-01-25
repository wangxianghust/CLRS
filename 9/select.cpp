#include <iostream>
#include <vector>
#include <random>
#include <stack>

using namespace std;

int RandomPartition(vector<int> &A, int p, int r){
    uniform_int_distribution<int> u(p,r);
    default_random_engine e;
    int index = u(e);
    swap(A[r], A[index]);

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

int RandomSelect(vector<int> &A, int p, int r, int order){
    if(order > r-p+1) return -1;
    if(p == r){
        return A[p];
    }

    int q = RandomPartition(A, p, r);
    int order_tmp = q-p+1;
    if(order_tmp == order){
        return A[q];
    } 

    if(order_tmp > order){
        return RandomSelect(A, p, q-1, order);
    } else {
        return RandomSelect(A, q+1, r, order-order_tmp);
    }
}

int RandomSelect_Iter(vector<int> &A, int p, int r, int order){
    stack<int> sta;
    sta.push(p);
    sta.push(r);
    while(!sta.empty()){
        int rr = sta.top();
        sta.pop();
        int pp = sta.top();
        sta.pop();
        
        if(order > rr-pp+1) return -1;
        if(rr == pp){
            return A[pp];
        }
        int q = RandomPartition(A, pp, rr);
        int order_tmp = q-pp+1;
        if(order_tmp == order){
            return A[q];
        }

        if(order_tmp > order){
            sta.push(pp);
            sta.push(q-1);
        } else {
            sta.push(q+1);
            sta.push(rr);
            order = order - order_tmp;
        }
    }
}

int main(){
    vector<int> A = {1,3,5,6,8,7,9,0,2,4};
    cout << RandomSelect(A, 0, A.size()-1, 2) << endl;
    cout << RandomSelect(A, 0, A.size()-1, 12) << endl;
    cout << RandomSelect_Iter(A, 0, A.size()-1, 5) << endl;
    cout << RandomSelect_Iter(A, 0, A.size()-1, 8) << endl;
}
