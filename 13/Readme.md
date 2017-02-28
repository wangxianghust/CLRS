EXERCISES
13.1-5
case 1, node x is red, assume the shortest path is num, the longest have 2*num(red-black-red-black...)
case 2, node x is black, assume the shortest path is num, the longest have the 2*(num-1)+1 = 2*num -1
so, the longest path is no more than shortest path.

13.1-6
for a complete binary tree. 
smallest: all nodes all black, the height is k, then the number is 2^k-1;
largest: the red and black is placed alternately, then the height is 2k, the largest number is 2^2k-1.

13.1-7
ratio = red/height
ratio_max = 2;
rati0_min = 0;

13.3-4
line 7 and line 13 will change the node's color, but it can only influence the parent node.And root can not be red
so..

13.3-5
use contradiction, assume (n-1) nodes are all black, then insert a new node, the color is red , and it's parent must 
be black, which is satisfy all the red-black properties.
