#include <vector>
#include <random>
#include <iostream>

using namespace std;

int Partition(vector<int> &red, vector<int> &blue, int low, int high){
    // every time we select red jug as a pivot, campare it with blue jug elements.
    // firstly, sort the red jugs.
    default_random_engine e;
    uniform_int_distribution<int> dist(low, high);
    int select = dist(e);
    int pivot = red[select];

    int pivot_index;
    int small = low-1;
    for(int i=low; i<=high; ++i){
        if(blue[i]<pivot){
            swap(blue[++small], blue[i]);
        } else if(blue[i] == pivot){
            pivot_index = i;
        }
    }
    if(pivot_index<small){
        swap(blue[small], blue[pivot_index]);
    } else if(pivot_index>small){
        swap(blue[small+1], blue[pivot_index]);
    } 
        
    // then we sort the blue jugs
    small = low-1;
    for(int i=low; i<=high; ++i){
        if(red[i]<pivot){
            swap(red[++small], red[i]);
        } 
    }
    
    if(select<small){
        swap(red[small], red[select]);
    } else if(select>small){
        swap(red[small+1], red[select]);
    } 

    return small+1;  // notice this line;
}

void JugsQS(vector<int> &red, vector<int> &blue, int low, int high){
    if(low < high){
        int par = Partition(red, blue, low, high);
        JugsQS(red, blue, low, par-1);
        JugsQS(red, blue, par+1, high);
    }
}

void print(const vector<int> &A){
    for(auto i : A){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> red{1,2,5,6,7,4,3};
    vector<int> blue{6,7,5,3,2,1,4};
    print(red);
    print(blue);
    JugsQS(red, blue, 0, red.size()-1);

    print(red);
    print(blue);
}
