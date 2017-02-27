Exercise12.1-2
The bound of sort is n*lg(n), for the min-heap, every time we extract the top, then the lg(n) time
will be used to adjust the heap, so the time comlexity is also n*lg(n).

12.1-3
see InOrderWalk.cpp

12.1-4
see chapter 10

12.1-5
使用反证法，如果build heap 复杂度优于n*lg(n), 则排序算法会优于n*lg(n),contradiction.

12.2-5
obviously, 使用反证法，在right subtree 中，假设successor node s 还有left child sl，则sl是更加合适的successor。

12.2-7
题目说，使用一次Minimum和(n-1)次Succssor来完成InOrder visit. 
This algorithm traverse each edge only twice, so running time is O(n).

12.2-8
对于k次连续成功的successive的调用，假设start node is s, end node is e.
case 1, s and e has an common ancestor, then cost O(2h) = O(h)
case 2, assume s and e has an common ancestor a, then s to a is O(h), a to e is O(h), and there are 
2k to consume when every successor is called.

12.3-3
best case: full binary tree, the tree height is lg(n), so the time complexith is n*lg(n).
worst case: the single linked list, so is O(n^2).

12.3-4
No

12.3-5 参考 http://blog.csdn.net/hrzr79011/article/details/41889431
问题的关键是从successor得到parent，同时复杂度在O(h)内。所以分以下的情况讨论。
case 1. x == x.parent.left; 令m是以x为根的子树中的最大值，则显然 m.successor = x.parent.
        a. x 没有right child，则m = x, x.parent = x.successor;
        b. x 有right child, 则m = Max(x.right), x.parent = m.successor;
case 2. x == x.parent.right; 令m是以x为根的子树中的最大值, 令 n = m.successor, 则m.predecessor = n. 现在考虑m在寻找
        predecessor的过程，则m会先访问其左子树，然后一直向右子树迭代。故这条path中，必然会经过x 和 x.parent.

12.3-6
1. Random
2. add an attribute height of every node, then choose the higher one to replace the x.


PROBLEM
12.1
b. h = O(lg n), other oprations are O(h)
c. h = O(lg m), m is the distinct item number of the these input. oprations are O(lg m) + O(equal_num)
d. worst case is h = n , everage case is h = lg(n)

12.2 
InOrder visit is ok, which time complexity is O(E), E is the edges number, then E = O(n), so the O(n) algorithm 
can be got.
