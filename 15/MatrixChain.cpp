#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;
using RetType = pair<vector<vector<int> >, vector<vector<int>> >;

RetType MatrixChain(vector<int> &chain){
    int num = chain.size() - 1; // the number of the matrixs
    vector<vector<int> > matrix(num, vector<int>(num, 0)); // save the different size matrix results;
    vector<vector<int> > split(num, vector<int>(num, 0)); // save the split index the matrixs
    for(int i=0; i<num; ++i){
        matrix[i][i] = 0;
    }

    for(int i=2; i<=num; ++i){ // the length of sub-matrix
        for(int j=1; j<=num-i+1; ++j){// start from the j-th matrix, until num-i+1-th matrix.
            int n = j+i-1;  // the end of the matrix chain.
            matrix[j-1][n-1] = INT_MAX;
            for(int k=j; k<n; ++k){ // bottom-up, first calculate the shorter matrix, k is the split matrix order.
                // how to understand n-1+1: n is the order of matrixs --> n-1 denotes the correspond chain index --> n-1+1 denotes the column of the the matrix(row*column). 
                int q = matrix[j-1][k-1] + matrix[k+1-1][n-1] + chain[j-1]*chain[k-1+1]*chain[n-1+1]; // convert the reall measure to program index
                if(q < matrix[j-1][n-1]){
                    matrix[j-1][n-1] = q;
                    split[j-1][n-1] = k-1;
                }
            }   
        }     
    }
    return make_pair(matrix, split);
}

void PrintMatrix(vector<vector<int>> &split, int start, int end){
    if(start == end){
        cout << "A" << start+1;
    } else {
        cout << "(";
        PrintMatrix(split, start, split[start][end]);
        PrintMatrix(split, split[start][end]+1, end);
        cout << ")";
    }
}

int main(){
    vector<int> chain{30,35,15,5,10,20,25};
    auto ret = MatrixChain(chain);
    auto matrix = ret.first;
    cout << matrix[1][4] << endl;
    auto split = ret.second;
    for(auto i : matrix){
        for(auto j : i) cout << j << "---";
        cout << endl;
    }
    PrintMatrix(split, 0, 5);
    cout << endl;
}
