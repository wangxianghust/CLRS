#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int ModifyCutRod(vector<int> &price, int n, int cost){
    vector<int> rod(n+1, 0); 
    for(int rod_size=1; rod_size<=n; ++rod_size){
        int q = INT_MIN;
        for(int cut_index=1; cut_index < rod_size; ++cut_index){
            q = max(q, price[cut_index-1] + rod[rod_size-cut_index] - cost);
        }
        // cut_index == rod_size, no cutting of the rod.
        rod[rod_size] = max(q, price[rod_size-1]);
    }
    return rod[n];
}

int main(){
    vector<int> price{1,5,8,9,10,17,17,20,24,30};
    int length = 5;
    auto ret = ModifyCutRod(price, length, 4); // eg. no cut
    cout << ret << endl;
}
