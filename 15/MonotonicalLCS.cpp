#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char **LCS(string M, string N){
    int m = M.length();
    int n = N.length();

    //char arrow[m+1][n+1];
    int common_len[m+1][n+1]; // one more space is for the initial state.
    char **arrow = 0;  // it is defined as pointer to pointer which denotes the 2-dimension array,*((char*)arrow + n*i + j) 
    arrow = new char*[m+1];
    for(int i=0; i<m+1; ++i){
        arrow[i] = new char[n+1];
    }

    common_len[m][0] = 0;
    common_len[0][n] = 0;
    for(int i=0; i<m; ++i){
        common_len[i][0] = 0;
        arrow[i+1][0] = M[i];
    }
    for(int j=0; j<n; ++j){
        common_len[0][j] = 0;
        arrow[0][j+1] = N[j];
    }

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(M[i] == N[j]){
                common_len[i+1][j+1] = common_len[i][j] + 1;
                arrow[i+1][j+1] = 'Y';
            } else if(common_len[i][j+1] >= common_len[i+1][j]){
                common_len[i+1][j+1] = common_len[i][j+1];
                arrow[i+1][j+1] = 'T';
            } else {
                common_len[i+1][j+1] = common_len[i+1][j];
                arrow[i+1][j+1] = 'L';
            }
        }
    }
    for(int i=0; i<m+1; ++i){
        for(int j=0; j<n+1; ++j){
            cout << common_len[i][j] << "--" << arrow[i][j] << "  " ;
        }
        cout << endl;
    }
    
    return arrow;
}

void PrintTrack(string M, char **arrow, int m, int n, int i, int j){
    if( (i == 0) || (j == 0) ) return;
    if( arrow[i][j] == 'Y'){  // use the pointer to get arrow[i][j]:  *((char*)arrow + n*i + j) == 'Y', when we convert array to pointer use this way.
        PrintTrack(M, arrow, m, n, i-1, j-1);
        cout << M[i-1] << "--";
    } else if(arrow[i][j] == 'L'){
        return PrintTrack(M, arrow, m, n, i, j-1);
    } else {
        return PrintTrack(M, arrow, m, n, i-1, j);
    }
}

int main(){
    string M("abcyedfgzmw");
    string N(M);
    sort(N.begin(), N.end());    
    char** ret = LCS(M, N); 
    int m = M.length();
    int n = N.length();
    PrintTrack(M, ret, m+1, n+1, m, n);
    cout << endl;
    for(int i=0; i<m+1; ++i){
        delete [] ret[i];
    }
    delete [] ret;

}

