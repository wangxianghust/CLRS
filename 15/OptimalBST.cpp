#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printRoot(vector<vector<int>> &a){
    int size = a.size()-1;
    for(int i=1; i<=size; ++i){
        for(int j=1; j<=size; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void printE(vector<vector<double>> &a){
    int size = a.size()-2;
    for(int i=1; i<=size; ++i){
        for(int j=1; j<=size; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void printBST(vector<vector<int>> &root, int i, int j, int r, int size){
    cout << "i : " << i << " j : " << j << endl;
    int root_child = root[i][j];
    if(root_child == root[1][size]){ //test is it a root.
        cout << "k" << root_child << " is the root" << endl;
        printBST(root, i, root_child-1, root_child, size);
        printBST(root, root_child+1, j, root_child, size);
        return;
    }

    if(j < i-1) return;
    else if(j == i-1){ //these are dummy keys;
        if(j < r){
            cout << "d" << j << " is the left child of k" << r << endl;
        } else {
            cout << "d" << j << " is the right child of k" << r << endl;
        }
        return;
    } else { //these are internal nodes;
        if(root_child < r){
            cout << "k" << root_child << " is the left child of k" << r << endl;
        } else {
            cout << "k" << root_child << " is the right child of k" << r << endl;
        }
    }

    printBST(root, i, root_child-1, root_child, size);
    printBST(root, root_child+1, j, root_child, size);
}

vector<vector<int>> OptimalBST(vector<double> &p, vector<double> &q, int size){
    //why use size+2, because the key number is size, the dummy number is size+1
    //and the vector starts from index o, to denote the (size+1)th value we need 
    //size+e memory to contain it.
    vector<vector<double> > w(size+2, vector<double>(size+2, 0));
    vector<vector<double> > e(size+2, vector<double>(size+2, 0));
    vector<vector<int> > root(size+2, vector<int>(size+2, 0)); 

    for(int i=1; i<=size+1; ++i){
        w[i][i-1] = q[i-1];
        e[i][i-1] = q[i-1];
    }

    for(int l=1; l<=size; ++l){
        for(int i=1; i<=size-l+1; ++i){
            int j = i+l-1;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            e[i][j] = INT_MAX;
            for(int k=i; k<=j; ++k){
                double temp = e[i][k-1] + e[k+1][j] + w[i][j];
                if(temp < e[i][j]){
                    e[i][j] = temp;
                    root[i][j] = k;
                }
            }
        }
    }
    printE(e);
    cout << "-----" << endl;
    printRoot(root);
    return root;
}

int main(){
    vector<double> p{-1, 0.15, 0.10, 0.05, 0.1, 0.2};
    vector<double> q{0.05, 0.1, 0.05, 0.05, 0.05, 0.1};
    int size = 5;  //the number of distinct keys, and dummy keys is size+1；
    auto root = OptimalBST(p, q, size);
    printBST(root, 1, size, -1, size);
}
