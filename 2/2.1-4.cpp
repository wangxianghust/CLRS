#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

//template <typename unsigned n>
//void fun(int A[n], int B[n], int& R[n]){
//    return 0;
//}

void fun(vector<int> A, vector<int> B, vector<int>& R){
    vector<int> C;
    int n = A.size();
    C.push_back(0);
    for(int i = 0; i < n; ++i){
        int tmp = C[i] + A[i+1] + B[i+1];
        if(tmp == 2){
            R.push_back(0);
            C.push_back(1);
        } else if(tmp == 3){
            R.push_back(1);
            C.push_back(1);
        } else {
            R.push_back(tmp);
            C.push_back(0);
        }
    }
    
}

int main(){
    vector<int> A = {0,1,1,1,0,1}; // start the second element to calculate
    vector<int> B = {0,0,0,1,0,1};
    vector<int> R;
    fun(A,B,R);
    for(auto i : R){
        cout << i << endl;
    }
}


