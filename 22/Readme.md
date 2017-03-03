##Exercise

#22.2-3
the line 5 and 14 only assign the color gray to some nodes, but the color informations are not used yet,
so these codes can be ignored. In another word, we don't need the gray state to denote the nodes to be
visited, we only need to konw the node is visited or not.

#22.2-4
if the graph is reprented by the adjacent matrix, the time of iterating all edges will cost O(V^2) replace 
O(E), so the time cost is O(V + V^2).

#22.2-5
the shortest path is fixed, obviously independent on the order of nodes. But the bread-first-tree is visited
by node.parent, different nodes order make different tree orders.

#22.2-7
test whether it is a bipartite graph.

#22.2-8
there is an O(n) algorithm.

#22.3-4
white, gray and black colors, the gray can be omited, and use one bit to denote the white and black.

#22.3-8
they may be the brothers rather than parents and children.

#22.3-13
for every node x in V, use DFS, and detect whether there are forward edges or cross edges(in the same component)
if yes, then it is not single, else it is single.

#22.5-1
keep or decrease one component number

#22.5-3
no, without transpose graph, two nodes which can visit each other may not be satisfied.

#22.5-4
the strongly connected relationship is an equivalence relation. so G and GT have the same SCC.
