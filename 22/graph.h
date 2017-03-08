#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stack>

using namespace std;
class Node;
class Edge;
class Graph;

typedef shared_ptr<Node> NodePtr;
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
        //Node(){};
        Node(int id_):id(id_){}
        Node(int id_, NodeDataType d):id(id_), data(d){}
    public:
        bool operator==(Node &y);
        bool operator!=(Node &y);
        int GetID(){ return id; }
        void AddEdge(shared_ptr<Node> end) {edges.push_back(end);}
        vector<shared_ptr<Node> > GetEdges(){ return edges; }
    public:
        bool visited;
    private:
        int id;
        NodeDataType data;
        vector<shared_ptr<Node> > edges;
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
        Graph(int size);
        int GetNodeNum() {return Nodes.size(); };
        int GetEdgeNum(){return Edges.size(); };
        bool AddSingleEdge(int s, int e, EdgeDataType d = EdgeDataType());
        bool AddDoubleEdge(int s, int e, EdgeDataType d = EdgeDataType());
        bool DeleteSingleEdge(int s, int e);
        bool DeleteDoubleEdge(int s, int e);
        bool AddNode(int id, NodeDataType d = NodeDataType());
        vector<shared_ptr<Node> > BFS(int id);
        vector<vector<NodePtr> > SearchDFS();
        vector<NodePtr> DFS_iter(int id);
    private:
        shared_ptr<Node> FindNode(int id);
        void DFS(int id);
    private:
        vector<shared_ptr<Node> > Nodes;
        vector<shared_ptr<Edge> > Edges;
};

Graph::Graph(int size){
    for(int id=0; id<size; ++id){
        Node node(id);
        Nodes.push_back(make_shared<Node>(node));
    }
}

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
    auto start_p = FindNode(start);
    auto end_p = FindNode(end);
    start_p->AddEdge(end_p);

    return true;
}

bool Graph::AddDoubleEdge(int start, int end, EdgeDataType data){
    bool edgeStoE = AddSingleEdge(start, end, data);
    bool edgeEtoS = AddSingleEdge(end, start, data);
    return edgeEtoS && edgeStoE;
}

bool Graph::AddNode(int id, NodeDataType data){
    Node node(id, data);
    Nodes.push_back(make_shared<Node>(node));
    return true;
}

shared_ptr<Node> Graph::FindNode(int id){
    shared_ptr<Node> start;
    bool flag = false;
    for(auto i : Nodes){
        if(i->GetID() == id){
            start = i;
            flag = true;
            break;
        }
    }
    if(flag){
        return start;
    } else {
        cout << "ID NOT FOUND" << endl;
        return 0;
    }
}

vector<shared_ptr<Node> > Graph::BFS(int id){
    vector<shared_ptr<Node> > ret;
    auto start = FindNode(id);
    //if(! start) cout << "error" << endl;
    //initialization
    for(auto i : Nodes) i->visited = false;
    queue<shared_ptr<Node> > que;
    que.push(start);
    start->visited = true;
    while(! que.empty()){
        auto now = que.front();
        for(auto i : now->GetEdges()){
            if(! i->visited){ //first to test whether it is visited.
                que.push(i);
                i->visited = true;  //remember to update the visit state.
            }
        }
        ret.push_back(now);
        que.pop();
    }
    return ret;
}

void Graph::DFS(int id){
    auto start = FindNode(id);
    for(auto i : Nodes) i->visited = false;
    start->visited = true;
    for(auto i : start->GetEdges()){
        if(! i->visited) DFS(i->GetID());
    }
}

vector<NodePtr> Graph::DFS_iter(int id){
    vector<NodePtr> ret;
    auto start = FindNode(id);
    //for(auto i : Nodes) i->visited = false;
    start->visited = true;
    stack<shared_ptr<Node> > sta;
    sta.push(start);
    while(! sta.empty()){
        auto now = sta.top();
        for(int i=0; i<now->GetEdges().size(); ++i){
            auto edge = now->GetEdges()[i];
            if(! edge->visited){
                sta.push(edge);
                edge->visited = true;
                now = edge;
            }
        }
        ret.push_back(sta.top());
        sta.pop();
    }
    return ret;
}

vector<vector<NodePtr> > Graph::SearchDFS(){
    for(auto i : Nodes) i->visited = false;
    vector<vector<NodePtr> > ret;
    for(auto i : Nodes){
        if(! i->visited){
            auto dfs = DFS_iter(i->GetID());
            ret.push_back(dfs);
        }      
    }
    return ret;
}

#endif  
