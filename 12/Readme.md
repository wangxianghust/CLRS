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

