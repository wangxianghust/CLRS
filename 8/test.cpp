#include <iostream>

using namespace std;

int test(){
    static int t = 1;
    while(t != 10){
        ++t;
        cout << t << endl;
        test();
        return t;
    }
    return -1;
 }

int main(){
    int ret = test();
    cout << "ret is " << ret << endl;
}
