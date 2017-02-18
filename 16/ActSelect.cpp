#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    node(int a=0): start(a), finish(0), id(0){}
    int start;
    int finish;
    int id;
};

bool cmp(node a, node b){
    return a.finish < b.finish;
}

void initial(vector<int> &start, vector<int> &finish, vector<node> &nodes){
    int size = start.size();
    for(int i=0; i<size; ++i){
        nodes[i].start = start[i];
        nodes[i].finish = finish[i];
        nodes[i].id = i;
    }
    sort(nodes.begin(), nodes.end(), cmp);
}

void Select_Greedy(int size, vector<node> &nodes){
    vector<int> S;
    S.push_back(0);
    int now = 0;
    for(int i=1; i<size; ++i){
        if(nodes[i].start >= nodes[now].finish){
            S.push_back(i);
            now = i;
        }
    } 
    for(auto i : S) cout << i << endl;
}

vector<int> Select_Greedy_Recur(vector<node> &nodes, int m, int n){
    static vector<int> S;
    if(m == 0) S.push_back(0);  // add first element, it must be in the set S.
    int next = m+1; //m is the last earliest activity, intial 0
    while(next <= n &&  nodes[next].start < nodes[m].finish){
        ++next;
    }
    if(next <= n){ // that is to say, start[next] >= finish[m];
        S.push_back(next);
        return Select_Greedy_Recur(nodes, next, n);
    } 
    return S;
}

// use dynamic programming to relize it.
void Select_DP(vector<node> &nodes){
    int size = nodes.size();
    vector<vector<int>> count(size, vector<int>(size,0));
    
    for(int l=2; l<=size; ++l){
        for(int i=0; i<size-l+1; ++i){
            int j = i+l-1;
            int fi = nodes[i].finish;
            int sj = nodes[j].start;
            if(fi >= sj){
                count[i][j] = 0;
            } else {
                for(int k=0; k<size; ++k){
                    int sk = nodes[k].start;
                    int fk = nodes[k].finish;
                    if(sk < fi || fk > sj){
                        continue;
                    } 
                    int q = count[i][k] + 1 + count[k][j];
                    if(q > count[i][j]){
                        count[i][j] = q;
                    }
                }
            }
        }
    }
    int max = 0;
    for(auto i : count){
        for(auto j : i){
            cout << j << "  ";
            if(j>max) max = j;
        }
        cout << endl;
    }
    cout << "the max activity number is : " << max + 2 << endl;
}

int main(){
    vector<int> start{1,3,0,5,3,5,6,8,8,2,12,17};
    vector<int> finish{4,5,6,7,9,9,10,11,12,14,16,18};
    int size = start.size();
    vector<node> nodes(size, node());
    initial(start, finish , nodes);
    Select_Greedy(size, nodes);
    auto ret = Select_Greedy_Recur(nodes, 0, size-1);
    for(auto i : ret) cout << i << "-->";
    cout << endl << "DP " << endl;
    Select_DP(nodes);
}

