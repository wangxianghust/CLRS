#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Stack{
public:
    int top();
    bool empty();
    void push(int val);
    void pop();
    void print();
private:
    queue<int> q1;
    queue<int> q2;
    int value;
    void print(queue<int> &);
}; 

void Stack::print(queue<int> &q){
    queue<int> tmp(q);
    while(!tmp.empty()){
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;
}

void Stack::push(int val){
    if(!q1.empty()){
        q1.push(val);
    } else {
        q2.push(val);
    }
    value = val;
}

bool Stack::empty(){
    return ( q1.empty() && q2.empty() );
}

int Stack::top(){
    return value;
}

void Stack::pop(){
    
    if(!q1.empty()){
        if(q1.size() == 1){
            q1.pop();
            value = -10086;
          //break;
        } 
        while(q1.size() >= 2){
            if(q1.size() == 2){
                value = q1.front();
            }
            int tmp = q1.front();
            q2.push(tmp);
            q1.pop();
        }
    } else {
        if(q2.size() == 1){
             q2.pop();
             value = -10086;
             //break;
        } 
        while(q2.size() >= 2){
            if(q2.size() == 2){
                value = q2.front();
            }
            int tmp = q2.front();
            q1.push(tmp);
            q2.pop();
        }
    }
    cout << "print q1 and q2" << endl;
    print(q1);
    print(q2);
}

void Stack::print(){
    queue<int> q_tmp(q1);
    vector<int> prt;
    while(!q_tmp.empty()){
        int tmp = q_tmp.front();
        //cout << "tmp1 " << tmp << endl;
        prt.push_back(tmp);
        q_tmp.pop();
    }
    q_tmp = q2;
    while(!q_tmp.empty()){
        int tmp = q_tmp.front();
        prt.push_back(tmp);
        q_tmp.pop();
    }

    for(int i=prt.size()-1; i>=0; --i){
        cout << prt[i] << " ";
    }
    cout << endl;
}

int main(){
    Stack sta;
    sta.push(1);
    sta.print();
    sta.push(2);
    sta.push(3);
    sta.push(4);
    sta.push(5);
    sta.print();
    sta.pop();
    sta.pop();
    sta.print();
    cout << " top : " << sta.top() << endl;
    cout << " empty : " << sta.empty() << endl;
}
