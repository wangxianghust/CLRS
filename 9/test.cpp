#include <iostream>

using namespace std;

void print(const int *begin, const int *end){
    while(begin != end){
        cout << *begin++ << " " ;
    }
    cout << endl;
}

void print(const int a[], size_t size){
    for(size_t i=0; i<size; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[] = {1,2,3,4,5,6};
    print(begin(a), end(a));
   
    print(a+2, 3);
}
