#include <iostream>
#include <vector>

using namespace std;

int Fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int Fibonacci_DP(int n){
    vector<int> F(n+1, 0);
    F[1] = 1;
    for(int i=2; i<=n; ++i){
        F[i] = F[i-1] + F[i-2];
    }  
    return F[n];
}

int main(){
    int n;
    cout << "input the number : " << endl;
    cin >> n;
    cout << "Dynamic Programing " << endl;
    cout << Fibonacci_DP(n) << endl;
    cout << "Recursive Method " << endl;
    cout << Fibonacci(n) << endl;
}
