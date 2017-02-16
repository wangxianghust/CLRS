#include <iostream>
#include <vector>

using namespace std;

int main(){
    int total = 7089;
    int per = 590;
    double intrest = 0.07;
    double ret = 0;
    for(int i=1; i<=12; ++i){
        ret += i*1.0/12;      
    }
    cout << ret << endl;
    double ret2 = per*intrest*ret;
    cout <<  ret2 << endl;
}
