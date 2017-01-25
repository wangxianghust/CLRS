#include <iostream>
#include <unordered_map>
#include <tuple>

using namespace std;

template<unsigned N>
tuple<int,int> FindSum(int (&A)[N], int sum){
    unordered_map<int,int> value_index;
    for(int i=0; i<N; ++i){
        int remain = sum - A[i];
        if(value_index.count(remain) > 0){  // if exists, this can be found before n times scan.
            return make_tuple(i, value_index[remain]);
        }
    value_index[A[i]] = i; // put the value and correspond index to map
    }
    return make_tuple(-1,-1);
}

int main(){
    int A[] = {1,2,3,4,5,5,6,7,9};
    auto ret = FindSum(A, 9);
    cout << get<0>(ret) << "--->" << get<1>(ret) << endl;
}
