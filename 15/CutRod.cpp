#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

pair<int,int> CutRod(vector<int> &price, int n){  // count is the number of #iteration
    static int count = 0;
    if(n == 0) return {0, ++count};
    int q= INT_MIN;
    for(int i=1; i<=n; ++i){
        q = max(q, price[i-1] + CutRod(price, n-i).first);
        ++count;
    }
    return make_pair(q, count);
}

int BottomUpCutRod(vector<int> &price, int n){
    vector<int> rod(n+1, 0);
    for(int j=1; j<=n; ++j){ // j denote the length of the road, rod[j] denote the optional solution of length j
        int q = INT_MIN;
        for(int i=1; i<=j; ++i){
            q = max(q, price[i-1]+rod[j-i]);  // price[i-1] denote the first cut location.
        }
        rod[j] = q;
    }
    return rod[n]; 
}

vector<int> InitialCutRod(int n){
    vector<int> rod(n+1, INT_MIN);
    return rod;
}

int MemoroizedCutRod(vector<int> &price, int n, vector<int> &rod){
    if(rod[n] >= 0) return rod[n];
    int q;
    if(n == 0){
        q = 0;
    } else {
        q = INT_MIN;
        for(int i=1; i<=n; ++i){  // static the price of different length
            q = max(q, price[i-1] + MemoroizedCutRod(price, n-i, rod));
        }
        rod[n] = q; // save the q length road prices.
    }
    return q;
}

pair<vector<int>, vector<int> > ExtendBottomUpCutRod(vector<int> &price, int n){
    vector<int> rod(n+1, 0);
    vector<int> split(n+1, 0);
    for(int i=1; i<=n; ++i){
        int q = INT_MIN;
        for(int j=1; j<=i; ++j){
            if(q < price[j-1] + rod[i-j]){
                q = price[j-1] + rod[i-j];
                split[i] = j;
            }
        }
        rod[i] = q;
    }
    return make_pair(rod, split);
}

void PrintTrack(vector<int> &split, int n){
    int length = n;
    while(length > 0){
        cout << split[length] << " --- ";
        length -= split[length];
    }
    cout << endl;
} 

int main(){
    vector<int> price{1,5,8,9,10,17,17,20,24,30};
    int length = 7;
    auto ret = CutRod(price, length);
    cout << ret.first << endl;
    cout << "calculate number : " << ret.second << endl;
    auto ret2 = BottomUpCutRod(price, length);
    cout << ret2 << endl;
    vector<int> rod = InitialCutRod(length);
    auto ret3 = MemoroizedCutRod(price, length, rod);
    cout << ret3 << endl;

    auto ret4 = ExtendBottomUpCutRod(price, length);
    auto r = ret4.first;
    cout << r[length] << endl;
    PrintTrack(ret4.second, length);
}
