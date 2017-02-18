#include <iostream>
#include <vector>

using namespace std;

bool Empty(vector<int> &start, vector<int> &finish, int i, int j, vector<int> &S){
    int size = start.size();
    int fi = finish[i];
    int sj = start[j];
    if(fi >= sj) return true;
    for(int k=0; k<size; ++k){
        bool flag = (start[k]>=fi) && (finish[k]<=sj);   
        if(flag) {
            S.push_back(k);
        };    
    }
    if(!S.empty()) return false;
    return true;
}

int Select_DP(vector<int> &start, vector<int> &finish){
    int size = start.size();
    vector<vector<int>> S(size, vector<int>(size,0));
    vector<vector<int>> count(size, vector<int>(size,0));

    for(int l=2; l<size; ++l){
        for(int i=0; i<size-l+1; ++l){
            vector<int> SS;
            int j = i+l-1;
            bool emp = Empty(start, finish, i, j, SS);
            if(emp){
                count[i][j] = 0;
            } else {
                for(int k=0; k<SS.size(); ++k){
                    int kk = SS[k];
                    int new_val = count[i][kk] + count[kk][j] + 1;
                    if(new_val > count[i][j]){
                        count[i][j] = new_val;
                    }
                }
            }     
        }
    }

    for(auto i : count){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return count[0][size-1];
}

int main(){
    vector<int> start{1,3,0,5,3,5,6,8,8,2,12,17};
    vector<int> finish{4,5,6,7,9,9,10,11,12,14,16,18};
    int ret = Select_DP(start, finish);
    cout << ret << endl;
}
    
