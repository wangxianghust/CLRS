/* 实现KMP算法 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getNext(string &pattern, vector<int> &next){
    int size(pattern.size()), j(0), k(-1);
    next[0] = -1;
    while(j < size-1){
        //k == -1 denotes the start index, p[k] == p[j] means match.
        //k代表前缀，j代表后缀
        if(k == -1 || pattern[k] == pattern[j]){
            ++k;
            ++j;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int match(string &str, string &pattern){
    int s_len(str.size()), p_len(pattern.size());
    if(str.empty() && pattern.empty()) return 0;
    int i(0), j(0);
    vector<int> next(p_len, 0);
    getNext(pattern, next);
    while(i < s_len && j < p_len){
        if(j == -1 || str[i] == pattern[j]){
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    return (j == p_len) ? (i-j) : -1;
}

int main(){
    string s("abcabcdabcdabcd");
    string p("abcdabd");
    cout << match(s,p) << endl;
}
