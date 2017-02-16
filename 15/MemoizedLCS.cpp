#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int LookUp(string M, string N, vector<vector<int> > &common_len, int , int );
void PrintTrack(string M, string N, vector<vector<int> > &common_len, int , int );

int MemoizedLCS(string M, string N){
    int m = M.length();
    int n = N.length();
    vector<vector<int> > common_len(m+1, vector<int>(n+1, -1));
    int number =  LookUp(M, N, common_len, m, n);
    PrintTrack(M, N, common_len, m, n);
    cout << endl;
    return number;
}

int LookUp(string M, string N, vector<vector<int> > &common_len, int m, int n){
    if(common_len[m][n] > 0) return common_len[m][n];
    if( (m == 0) || (n == 0) ) {
        common_len[m][n] = 0;
    } else {
        if(M[m-1] == N[n-1]){
            common_len[m][n] = LookUp(M, N, common_len, m-1, n-1) + 1;
        } else {
            common_len[m][n] = max(LookUp(M, N, common_len, m-1, n), LookUp(M, N, common_len, m, n-1));
        }
    }
    return common_len[m][n]; 
}


void PrintTrack(string M, string N, vector<vector<int> > &common_len, int m, int n){
    if( m==0 || n==0 ) return;
    if(M[m-1] == N[n-1]){
        PrintTrack(M, N, common_len, m-1, n-1);
        cout << M[m-1] << "-->";
    } else {
        if(common_len[m-1][n] >= common_len[m][n-1]){
            PrintTrack(M, N, common_len, m-1, n);
        } else {
            PrintTrack(M, N, common_len, m, n-1);
        }
    }
}

int main(){
    string M("ABCBDAB");
    string N("BDCABA");
    M="10010101";
    N="010110110";
    
    int number = MemoizedLCS(M, N);
    cout << "Longest Length is : " << number << endl;
}
