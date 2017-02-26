chapter 10
10.4-5 
要求不用Stack来实现对树的遍历，关键在树stack的作用是记录parent节点的信息，故给每个node
添加parent的属性就可以解决这个问题。以root为当前node，prev记录上一个root, 比较prev和root的关系
决定是Left，Right 访问或者回溯到parent。

10.4-6
去掉parent指针，增加一个bool确定node有没有right sibling，有的话next指向兄弟，没有的话next指向parent。

12.2
Successor and Precessor, which is O(h) , h is the height of the tree
for a continuous (n-1) Successor call, it at most visit every edge 2 times, which time complexcity is O(n).
