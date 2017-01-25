#include <iostream>
#include <utility>
#include <vector>
#include <random>

using namespace std;

using Array = vector<pair<int,int>>;
using EleType = pair<int, int>;

EleType Find_Intersection(Array &A, int p, int r){
    EleType pivot = A[r];
    int one, two;
    one = pivot.first;
    two = pivot.second;
    for(int j = p; j < r; ++j){
        if(A[j].first <=  two && A[j].second >= one){
            if(A[j].first > one) one = A[j].first;
            if(A[j].second < two) two = A[j].second; 
        }      
    }
    return make_pair(one, two);
}

int Partition_Right(Array &A, int p, int r, int one){
    int small = p - 1;
    for(int j=p; j<=r; ++j){
        if(A[j].first <= one){
            swap(A[++small], A[j]);
        }
    }
    //swap(A[++small], A[r]);
    return small+1;
}

int Partition_Left_Middle(Array &A, int p, int r, int two){
    int small = p - 1;
    for(int j=p; j<=r; ++j){
        if(A[j].second < two){
            swap(A[++small], A[j]);
        }
    }
    //swap(A[++small], A[r]);
    return small+1;
}

void fuzzy_sort(Array &A, int p, int r){
    if(p<r){
        EleType inter = Find_Intersection(A, p, r);
        int q1 = Partition_Right(A, p, r, inter.first);
        int q2 = Partition_Left_Middle(A, p, q1, inter.second);
        fuzzy_sort(A, p, q2-1);
        fuzzy_sort(A, q1, r);
    }
}

void print(const Array &A){
    cout << endl;
    for(auto ele : A){
        cout << ele.first << ", " << ele.second << endl;
    }
}

int main(){
    Array A{ {6,8}, {3,4}, {2,3}, {7,9},{9,10}, {15,16}, {1,2} };
    print(A);
    fuzzy_sort(A, 0, A.size()-1);
    cout << "The result is " << endl;
    print(A);
}
