#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> CountSort(vector<int> &A){
    int size = A.size();
    vector<int> result(size, 0);
    int k = *max_element(A.begin(), A.end());
    vector<int> tmp(k,0);
    for(int i=0; i<size; ++i){
        tmp[A[i]] = tmp[A[i]] + 1;
    }
    for(int i=1; i<=k; ++i){
        tmp[i] = tmp[i] + tmp[i-1];
    }
    for(int i=size-1; i>=0; --i){
        result[tmp[A[i]]] = A[i];
        --tmp[A[i]];
    }
    return result;
}

int query(const vector<int> &A, int a, int b){    // for question 8.2-4
    int ret = 0;
    int size = A.size();
    int k = *max_element(A.begin(), A.end());
    vector<int> tmp(k,0);
    for(int i=0; i<size; ++i){
        tmp[A[i]] = tmp[A[i]] + 1;
    }
    for(int i=a; i<=b; ++i){
        ret += tmp[i];
    }
    return ret;
}

template<typename Container>
void print(Container &con, string info=" "){
    cout << "---" << info << "---" << endl;
    for(auto begin=con.cbegin(); begin != con.cend(); ++begin){
        cout << *begin << " ";
    }
    cout << endl;
}

int main(){
    vector<int> A = {6,0,2,0,1,3,4,6,1,3,2};
    print(A, "initial");
    auto ret = CountSort(A);
    print(ret, "sorted");
    cout << query(A,1,3) << endl;
    cout << query(A,5,5) << endl;
    
    return 0;
}
