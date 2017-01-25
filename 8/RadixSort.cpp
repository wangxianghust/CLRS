#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <utility>
#include <random>

using namespace std;

class RandInt{
    public:
        RandInt(int low, int high): ge(chrono::system_clock::now().time_since_epoch().count()), dist(low, high){}
        ~RandInt(){};
        int operator()(){ return dist(ge); }
    private:
        minstd_rand ge;
        uniform_int_distribution<int> dist;
};

class RadixSort{
    public:
        RadixSort(int n, int powValue);
        ~RadixSort(){};
        void printData();
        void sort();
    private:
        int inputSize;
        int digitNum;
        vector<int> sortData;
        vector<pair<int,int> > copyData;
        void CountSortDigit();
};

RadixSort::RadixSort(int n, int powValue):inputSize(n), digitNum(powValue), sortData(vector<int>(n)), copyData(vector<pair<int,int>>(n)){
    RandInt rnd(0, pow(n, powValue)-1);
    for(auto &ele : sortData){
        ele = rnd();
    }
}

void RadixSort::printData(){
    for(auto ele : sortData){
        cout << ele << " ";
    }
    cout << endl;
}

void RadixSort::sort(){
    for(int i=0; i<inputSize; ++i){
        copyData[i] = make_pair(i, sortData[i]);
    }

    for(int i=0; i<digitNum; ++i){
        CountSortDigit();
    }

    vector<int> backup(sortData.begin(), sortData.end());
    for(int i=0; i<inputSize; ++i){
        sortData[i] = backup[copyData[i].first];
    }
}

void RadixSort::CountSortDigit(){
    vector<pair<int,int>> digit(inputSize);
    for(int i=0; i<inputSize; ++i){     // for every digit, we process once;
        digit[i] = make_pair(i, copyData[i].second % inputSize);
        copyData[i].second /= inputSize;        
    }

    vector<int> C(inputSize);
    for(auto t : digit){
        ++C[t.second];
    }
    for(int i=1; i<inputSize; ++i){  // t.second max is inputSize;
        C[i] = C[i] + C[i-1];
    }

    vector<pair<int,int>> backup(copyData.begin(), copyData.end());
    for(int i=inputSize-1; i>=0; --i){
        int index = C[digit[i].second];
        copyData[index-1] = backup[digit[i].first];
        --C[digit[i].second];
    }
}

int main(){
    RadixSort rs(5,3);
    rs.printData();
    rs.sort();
    rs.printData();
}
