#include "graph.h"

int main(){
    Graph graph(10);
    
    graph.AddDoubleEdge(0,1);
    graph.AddDoubleEdge(0,2);
    graph.AddDoubleEdge(0,3);
    graph.AddDoubleEdge(1,4);
    graph.AddDoubleEdge(6,7);
    //graph.AddDoubleEdge(7,8);
    graph.AddDoubleEdge(8,9);
    cout << graph.GetEdgeNum() << endl;
    cout << graph.GetNodeNum() << endl;
    vector<shared_ptr<Node> > bfs = graph.BFS(1);
    for(auto i : bfs) cout << i->GetID() << "--";
    cout << endl;
    
    //vector<shared_ptr<Node> > dfs = graph.DFS_iter(0);
    //r(auto i : dfs) cout << i->GetID() << "--";
    //cout << endl;

    vector<vector<NodePtr> > dfss = graph.SearchDFS();
    for(auto dfs : dfss){
        for(auto i : dfs){
            cout << i->GetID() << "-->";
        }
        cout << endl;
    }
}
