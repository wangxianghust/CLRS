#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int Partition(vector<T> &A, int p, int r);

template<typename Container>
void print(Container &con){
    for(auto begin = con.cbegin(); begin != con.cend(); ++begin){
        cout << *begin << " ";
    }
    cout << endl;
}


template<typename T>
int Partition(vector<T> &A, int p, int r){
    T pviot = A[r];
    int small = p-1;
    for(int j=p; j<r; ++j){
        if(A[j] < pviot){
            ++small;
            swap(A[small], A[j]);
        }
    }
    swap(A[++small], A[r]);
    return small;
}

template<typename T>
int tail_QS(vector<T> &A, int p, int r){
    static int num=0;
    while(p<r){
        ++num;
        int q = Partition(A,p,r);
        tail_QS(A,p,q-1);
        p = q + 1;
        print(A);
    }
    return num;
}

template<typename T>
int update_tail_QS(vector<T> &A, int p, int r){
    static int numm = 0;
    while(p<r){
        ++numm;
        int q = Partition(A,p,r);
        if(r-q >= q-p){
            update_tail_QS(A, p, q-1);
            p = q+1;
        } else {
            update_tail_QS(A,q+1, r);
            r = q-1;
        }
        print(A);
    }
    return numm;
}

int main(){
    vector<int> A{50,1,2,3,89,6,3,234,53,89,67,43,3,23,3,54,100,0};
    int n = tail_QS(A, 0, A.size()-1);
    cout << "the recursion num is " << n << endl;
    A = {50,1,2,3,89,6,3,234,53,89,67,43,3,23,3,54,100,0};
    int num = update_tail_QS(A, 0, A.size()-1);
    //print(A);
    cout << "update the algorithm, the num is " << num << endl;
}
