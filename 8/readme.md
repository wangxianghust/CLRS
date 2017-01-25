problem 8-2
The fastest in-place sort 
https://www.codeproject.com/articles/26048/fastest-in-place-stable-sort

problem 8-3 problem b
we need proprocess the data, then use the radix sort to get the results.
1.find the longest string, then make all strings have the same length as the longest one,
  use @ character use fill these strings.
2.use RadixSort to sort these new strings
3.reflect new string to raw strings.

problem 8-4
There is still some problems.
the return value of the Partition function.

problem 8-5
solution-c
sufficiency: A[i]<A[i+k],then just sum the k adjecent elements,we can get the provements
necessity:expend the sumption of the equation, then eliminate the same item, will get A[i]<[i+k]
