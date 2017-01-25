#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;

template<typename Container>
void insertSort(Container& A){
    auto n = A.size();
    for(typename Container::size_type j = 2; j < n; ++j){
        auto key = A[j];
        int i = j - 1;
        while(i > 0 && A[i] > key){
            A[i+1] = A[i];
            --i;
        }
        A[i+1] = key;
    }
}

template<typename Container>
ostream& print(const Container& A, ostream& os, string info = " "){
    os << "---" << info << "---" << endl;
    for(auto i : A){
        os << i << endl;
    }
    return os;
}

int main(){
   vector<int>A = {1,4,2,3,9,5,2,1,35,25};
   print(A,cout,"old");
   insertSort(A); 
   print(A,cout,"sorted");
   vector<string> S{"a", "abc", "de", "xyz", "wang"};
   insertSort(S);
   print(S,cout, "string sorted");
}
