#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LCS2Enties(string M, string N){
    int m = M.length();
    int n = N.length();
    if(m < n){
        swap(m,n);
        swap(M,N);
    };

    vector<vector<int> > common_len(2, vector<int>(n+1, 0));
    for(int i=1; i<m+1; ++i){
        for(int j=1; j<n+1; ++j){
            if(M[i-1] == N[j-1]){
                common_len[1][j] = common_len[0][j-1] + 1;
                //cout << common_len[1][j] << endl;
            } else {
                if(common_len[1][j-1] >= common_len[0][j]){
                    common_len[1][j] = common_len[1][j-1];
                } else {
                    common_len[1][j] = common_len[0][j];
                }
            }
        }
        //common_len[0] = common_len[1];
        for(int i=0; i<n+1; ++i){
            common_len[0][i] = common_len[1][i];
        }
    }
    return common_len[1][n];
}

// compared with above funcion, use one variable q to save common_len[i-1][j-1], then excepted one row, 
// we only need a common_len[i-1][j], which located at entry[j] here.
int LCSEnty(string M, string N){
    int m = M.length();
    int n = N.length();
    if(m < n){
        swap(m,n);
        swap(M,N);
    };

    vector<int> entry(n+1, 0);
    for(int i=1; i<m+1; ++i){
        int q=0;
        for(int j=1; j<n+1; ++j){
            if(M[i-1] == N[j-1]){
                q = entry[j-1] +1;
            } else {
                if(entry[j] >= entry[0]){ // entry[0] = common_len[i][j-1], entry[j] = common_len[i-1][j]
                    q = entry[j];
                } else {
                    q = entry[0];
                }
            }
            entry[j-1] = entry[0];
            entry[0] = q;
        }
        entry[n] = q; 
        entry[0] = 0;
    }
    return entry[m-1];
}

int main(){
    string M("ABCBDAB");
    string N("BDCABA");
    M="01011011011";
    N="1001010111";
    
    int number = LCS2Enties(N, M);
    cout << "Longest Length is , by LCS2Enties: " << number << endl;

    int num = LCSEnty(M,N);
    cout << "by one row : " << num << endl;
}
