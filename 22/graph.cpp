#include "graph.h"

int main(){
    Graph graph(10);
    
    graph.AddDoubleEdge(0,1);
    graph.AddDoubleEdge(0,2);
    graph.AddDoubleEdge(0,3);
    graph.AddDoubleEdge(1,4);
    graph.AddDoubleEdge(0,1);
    cout << graph.GetEdgeNum() << endl;
    cout << graph.GetNodeNum() << endl;
}
