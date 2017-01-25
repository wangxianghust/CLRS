// the complexe logical expression for vector border, need improvement.
// improvement: use array replace vector and omit the copy processes.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

void print(vector<int> A, string info=" "){
    cout << info << endl;
    for(auto i:A){
        cout << i << " ";
    }
    cout << endl;
}

void print(const int a[], size_t size, string info=""){
    cout << info << endl;
    for(size_t i=0; i<size; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}


int Median(int size){
    int med;
    if(size & 0x1){
        med = size/2;
    } else {
        med = size/2 - 1;
    }
    return med;
}

pair<int, int> FindMedian(vector<int> &X, vector<int> &Y){
    if(X.size() == 1) {
        return make_pair(X[0], Y[0]);
    }

    if(X.size() ==2){
        return make_pair(max(X[0], Y[0]), min(X[1], Y[1]));
    }
    int x_mid_index = Median(X.size());
    int y_mid_index = Median(Y.size());

    int x_med = X[x_mid_index]; 
    int y_med = Y[y_mid_index];

    if(x_med == y_med){
        return make_pair(x_med, x_med);
    }

    
    int size = X.size();
    if(x_med < y_med){   // there are complexe expression
        if(size & 0x1){
            vector<int> xtmp(X.size()/2+1);
            vector<int> ytmp(Y.size()/2+1);
            copy(X.begin()+x_mid_index, end(X), xtmp.begin());
            copy(begin(Y), Y.begin()+y_mid_index+1, ytmp.begin());
            print(xtmp, "X");
            print(ytmp, "Y");
            return FindMedian(xtmp, ytmp);

        } else {
            vector<int> xtmp(X.size()/2);
            vector<int> ytmp(Y.size()/2);
            copy(X.begin()+size/2, end(X), xtmp.begin());
            copy(begin(Y), Y.begin()+size/2+1, ytmp.begin());
            print(xtmp, "X");
            print(ytmp, "Y");
            return FindMedian(xtmp, ytmp);

        }
    } else {
        if(size & 0x1){
            vector<int> xtmp(X.size()/2+1);
            vector<int> ytmp(Y.size()/2+1);
            copy(Y.begin()+y_mid_index, end(Y), ytmp.begin());
            copy(begin(X), X.begin()+x_mid_index+1, xtmp.begin());
            print(xtmp, "X");
            print(ytmp, "Y");
            return FindMedian(xtmp, ytmp);

        } else {
            vector<int> xtmp(X.size()/2);
            vector<int> ytmp(Y.size()/2);
            copy(Y.begin()+size/2, end(Y), ytmp.begin());
            copy(begin(X), X.begin()+size/2+1, xtmp.begin());
            print(xtmp, "X");
            print(ytmp, "Y");
            return FindMedian(xtmp, ytmp);

        }
    } 
}

pair<int,int> FindMedian(int X[], int Y[], int size){   // the important thing is how to handle the base cases.
    if(size == 1) return make_pair(X[0], Y[0]);
    if(size ==2) return make_pair( max(X[0], Y[0]), min(X[1], Y[1]) );
    
    int mid_index = Median(size);
    int x_mid = X[mid_index];
    int y_mid = Y[mid_index];

    if(x_mid == y_mid) return make_pair(x_mid, x_mid);

    pair<int, int> ret;
    if(x_mid < y_mid){                                  // then we process the remain cases, every time we stay the middle element.
        if(size & 0x1){
            ret = FindMedian(X + size/2, Y, size/2 + 1 );
        } else {
            ret = FindMedian(X + size/2 - 1, Y, size/2 + 1);
        }
    } else {
        if(size & 0x1){
            ret = FindMedian(Y + size/2, X, size/2 + 1);
        } else {
            ret = FindMedian(Y + size/2 - 1, X, size/2 + 1);
        }
    }
    return ret;
}

int main(){
    vector<int> X{1,2,3,4,5,12,15,20};
    vector<int> Y{6,7,8,9,10,11,13,14};

    //auto ret = FindMedian(X,Y);
    int a[] = {1,2,3,4,5,12,15,19,20};
    int b[] = {6,7,8,9,10,11,13,14,16};
    auto ret = FindMedian(a, b, sizeof(a)/sizeof(a[0]));
    cout << ret.first << " --- " << ret.second << endl;
}
