Exercise12.1-2
The bound of sort is n*lg(n), for the min-heap, every time we extract the top, then the lg(n) time
will be used to adjust the heap, so the time comlexity is also n*lg(n).

12.1-3
see InOrderWalk.cpp

12.1-4
see chapter 10

12.1-5
使用反证法，如果build heap 复杂度优于n*lg(n), 则排序算法会优于n*lg(n),contradiction.
