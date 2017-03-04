#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef int NodeDataType;
typedef int EdgeDataType;

class Edge{
    public:
        Edge(){};
        Edge(int s, int e, EdgeDataType d): start(s), end(e), data(d) {}
        int start;
        int end;
        EdgeDataType data;
    public:
        bool operator==(Edge &y);
        bool operator!=(Edge &y);
};

bool Edge::operator==(Edge &y){
    if(start == y.start && end == y.data && data == y.data){
        return true;
    } else {
        return false;
    }
}

bool Edge::operator!=(Edge &y){
    return !(*this == y);
}

class Node{
    public:
        Node(){};
        Node(NodeDataType d):data(d){}
        NodeDataType data;
        vector<int> edges;
    public:
        bool operator==(Node &y);
        bool operator!=(Node &y);
};

bool Node::operator==(Node &y){
    if(data == y.data && edges == y.edges){
        return true;
    } else {
        return false;
    }
}

bool Node::operator!=(Node &y){
    return !(*this == y);
}

class Graph{
    public:
        Graph(){}
        Graph(int size): Nodes(vector<shared_ptr<Node> >(size)) {}
        int GetNodeNum() {return Nodes.size(); };
        int GetEdgeNum(){return Edges.size(); };
        bool AddSingleEdge(int s, int e, EdgeDataType d = EdgeDataType());
        bool AddDoubleEdge(int s, int e, EdgeDataType d = EdgeDataType());
        bool DeleteSingleEdge(int s, int e);
        bool DeleteDoubleEdge(int s, int e);
        bool AddNode(NodeDataType d = NodeDataType());
    private:
        vector<shared_ptr<Node> > Nodes;
        vector<shared_ptr<Edge> > Edges;
};

bool Graph::AddSingleEdge(int start, int end, EdgeDataType data){
    //test whether the input is legal. assume the node id is 0,1,2...nodeNum-1
    int nodeNum = GetNodeNum();
    if(start >= nodeNum || start < 0 || end >= nodeNum || end < 0){
        cout << "The input edges is not legal" << endl;
        return false;
    }
    for(auto edge : Edges){
        if(edge->start == start && edge->end == end){
            cout << "The edge(" << start << "," << end << ") is already exist" << endl;
            return false;
        }
    }
    Edge edge(start, end, data);
    Edges.push_back(make_shared<Edge>(edge));
    return true;
}

bool Graph::AddDoubleEdge(int start, int end, EdgeDataType data){
    bool edgeStoE = AddSingleEdge(start, end, data);
    bool edgeEtoS = AddSingleEdge(end, start, data);
    return edgeEtoS && edgeStoE;
}

bool Graph::AddNode(NodeDataType data){
    Node node(data);
    Nodes.push_back(make_shared<Node>(node));
    return true;
}

#endif  
