#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int ExtractMin(vector<vector<int> > &A){
    int minmum = A[0][0];
    A[0][0] = INT_MAX;
    int i(0), j(0);
    while( (i<A.size()) && (j<A[0].size()) ){
        int ori(i),orj(j);
        int right = INT_MAX;
        int down = INT_MAX;

        if(i<A.size()-1) down = A[i+1][j];
        if(j<A[0].size()-1) right = A[i][j+1];

        if(right == INT_MAX && down == INT_MAX) break;
        if(right <= down){
            ++j; // walk right
        } else {
            ++i;
        }
        swap(A[i][j], A[ori][orj]);
    }
    return minmum;
}

void Insert(vector<vector<int>> &A, int value){
    int i = A.size() - 1;
    int j = A[0].size() - 1;
    A[i][j] = value;

    while((i>=0) && (j>=0)){
        int left = INT_MIN;
        int up = INT_MIN;

        if(i>0) up = A[i-1][j];
        if(j>0) left = A[i][j-1];

        if(value >= up && value >= left) break;
        
        if(value < up){
            swap(A[i][j], A[i-1][j]);
            --i;
        } else {
            swap(A[i][j], A[i][j-1]);
            --j;
        }
    }

}

bool Search(vector<vector<int>> &A, int value){
    // start from the left-bottom and top-right to search
    // why? take the top-right as an example, when value is smaller than the key
    // we should walk left, vice versa, bigger then down. so we walk (m+n) at most.
    int row = 0;
    int col = A[0].size() - 1;
    while(row<A.size() && col>=0){
        cout << row << " " << col << endl; // print the search paths
        if(A[row][col] == value) return true;
        if(value > A[row][col]){
            ++row;
        } else {
            --col;
        }
    }
    return false;
}

void print_young(const vector<vector<int>> &A){
    for(auto row : A){
        cout << endl;
        for(auto item : row){
            cout << item << " ";
        }
    }
    cout << endl;
}

int main() {
    
    int arr1[4] = {2,3,12,INT_MAX};
    int arr2[4] = {4,8,16,INT_MAX};
    int arr3[4] = {5,9,INT_MAX,INT_MAX};
    int arr4[4] = {14,INT_MAX,INT_MAX,INT_MAX};
    
    vector<int> v1(arr1,arr1+4);
    vector<int> v2(arr2,arr2+4);
    vector<int> v3(arr3,arr3+4);
    vector<int> v4(arr4,arr4+4);
    
    vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    
    for(int i  = 0;i < 9;i++)
        cout << ExtractMin(v) << endl;
    for(int i  = 0;i < 9;i++)
        Insert(v, i);
    print_young(v);
    cout << Search(v, 8) << endl;

    return 0;
}
