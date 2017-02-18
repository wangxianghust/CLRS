#include <iostream>
#include <vector>

using namespace std;

void Print(vector<vector<int>> & c, vector<int> &w, int W){
    int N = w.size();
    vector<int> ret(N, 0);
    int j = W;
    for(int i=N; i>0; --i){
        if(c[i][j] == c[i-1][j]){ // the i-th item is not included.
            ret[i-1] = 0;
        } else {
            ret[i-1] = 1;
            j = j - w[i-1];
        }
    }
    for(auto i : ret) cout << i << "--->";
    cout << endl;
}

void Knapsack01(int N, int W, vector<int> &v, vector<int> &w){
    vector<vector<int> > c(N+1, vector<int>(W+1, 0));
    for(int i=0; i<W+1; ++i) c[0][i] = 0;
    
    for(int i=1; i<N+1; ++i){ //i:number of items, j:the weight,  c[i][j]:use i items and the weight is smaller than j
        c[i][0] = 0;
        for(int j=1; j<W+1; ++j){
            if(w[i-1] > j){ // w[i-1] denotes the i-th weight
                c[i][j] = c[i-1][j];
            } else {
                int temp = c[i-1][ j-w[i-1] ] + v[i-1];
                if(temp > c[i][j]){
                    c[i][j] = temp;
                }
            }    
        }
    }
   // for(auto i : c){
   //     for(auto j : i){
   //         cout << j << "  ";
   //     }
   //     cout << endl;
   // }
    Print(c, w, W);
}

struct node{
    int id;
    int v;
    int w;
    double r;
};

void initial(vector<int> &v, vector<int> &w, vector<node> &nodes){
    int n = v.size();
    for(int i=0; i<n; ++i){
        nodes[i].id = i;
        nodes[i].v = v[i];
        nodes[i].w = w[i];
        nodes[i].r = v[i]*1.0/w[i];
        
    }
}

bool cmp(node a, node b){
    return a.r > b.r;
}

void KnapsackGreedy(int W, vector<int> &v, vector<int> &w){
    int N = v.size();
    vector<double> ret(N, 0);   //save the ids of selected knapsack
    vector<node> nodes(N);
    initial(v,w,nodes);
    sort(nodes.begin(), nodes.end(), cmp);
    int total_w = 0;
    for(int i=0; i<N; ++i){
        total_w += nodes[i].w;
        if(total_w < W){
            ret[ nodes[i].id ] = 1;
        } else {
            ret[ nodes[i].id ] = (W - total_w + nodes[i].w)*1.0/nodes[i].w;
            break;
        }
    }
    for(auto i : ret) cout << i << "-->";
    cout << endl;
}

vector<double> Partition(vector<node> nodes, int W, int size){
    double pivot = nodes[0].r;
    vector<node> L, E, G;
    static vector<double> ret(size, 0);
    for(int i=0; i<size; ++i){
        if(nodes[i].r > pivot){
            G.push_back(nodes[i]);
        } else if(nodes[i].r < pivot){
            L.push_back(nodes[i]);
        } else {
            E.push_back(nodes[i]);
        }
    }
    
    int weightE = 0;
    for(auto node : E){
        weightE += node.w;
    }
    int weightG = 0;
    for(auto node : G){
        weightG += node.w;
    }
    if(weightG > W){
        return Partition(G, W, size);
    } else {
        int e_num = E.size();
        int i = 0;  //save the number that get from the E sets;
        if(weightG + e_num*nodes[0].w >= W){
            for(; i<=e_num; ++i){
                if(weightG + i*nodes[0].w < W) continue;
                else break;
            }
            for(auto node : G) {
                ret[node.id] = 1;
            }
            int ii=0;
            for(; ii<i-1; ++ii) ret[E[ii].id] = 1;
            ret[E[ii].id] = (W-weightG + (ii)*nodes[0].w)*1.0/nodes[0].w;
            return ret;
            } else {
                for(auto node : G) ret[node.id] = 1;
                for(auto node : E) ret[node.id] = 1;
                return Partition(L, W-weightE-weightG, size);
            }
    }
}

void KnapsackGreedyLinear(int W, vector<int> &v, vector<int> &w){
    int N = v.size();
    vector<double> ret(N,0);
    vector<node> nodes(N);
    initial(v,w,nodes);
    ret = Partition(nodes, W, N);
    for(auto i:ret) cout << i << "-->";
    cout << endl;
}

int main(){
    int N = 5;  
    int W = 17;  
    vector<int> w{3, 4, 7, 8, 9};  
    vector<int> v{4, 5, 10, 11, 13};
    Knapsack01(N, W, v, w);
    KnapsackGreedy(W, v, w);
    KnapsackGreedyLinear(W, v, w);
}
