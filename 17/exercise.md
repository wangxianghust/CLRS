Amortized analysis: everage performance of each operation in the worst case.

17.1-1 
no, assume MULTIPUSH cost O(k) every operation, then for n operations will cost O(nk).
MULTIPOP may cost O(nk) correspondly, it will be O(nk)/n = O(k)

17.1-2
think in the worst case, 01111 +1--> 10000 -1--> 01111 +1--> 10000... it will cost O(k) obviously.

17.1-3
assume k = lg2(n), total = 1*(2^k-1)/(2-1) + 2^(k+1) = 2^k + n-2^k = O(n), then average = O(n)/n = O(1)
