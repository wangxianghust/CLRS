#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Queue{
public:
    int peek(); // return the front element of queue;
    bool empty();
    void pop(); // remove the front element of queue;
    void push(int x); // push the element to the back of queue;
    void print(string info=" "); // for debug test

private:
    stack<int> sta1;
    stack<int> sta2;

    int value;
    void print(stack<int> sta);
};

void Queue::print(stack<int> sta){
    stack<int> staa(sta);
    while(!staa.empty()){
        cout << staa.top() << " ";
        staa.pop();
    }
    cout << endl;
}

void Queue::push(int val){
    if(sta1.empty()){
        value = val;
    }  
    sta1.push(val);  
    //print(sta1);
}

int Queue::peek(){
    if(empty()){
        value = -10086;
    }
    return value;
}

bool Queue::empty(){
    return sta1.empty();
}

void Queue::pop(){
    if(!sta1.empty()){
        while(!sta1.empty()){
            if(sta1.size() == 1){  // abort the last directly
                sta1.pop();
                break;
            }
            if(sta1.size() == 2){
                value = sta1.top(); // the last second as the peek element
            }
            int tmp;
            tmp = sta1.top();
            sta1.pop();
            sta2.push(tmp);
        }
    } else {
        cout << "the stack is empty" << endl;
    }

    while(!sta2.empty()){
        int tmp = sta2.top();
        sta2.pop();
        sta1.push(tmp);
    }
   // print(sta1);
}

void Queue::print(string info){
    cout << "---" << info << "---" << endl;
    stack<int> staa(sta1);
    vector<int> prt;
    while(!staa.empty()){
        int tmp = staa.top();
        prt.push_back(tmp);
        staa.pop();
    }
    for(int i=prt.size()-1; i>=0; --i){
        cout << prt[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    q.print("push");
    q.pop();
    q.pop();
    q.pop();
    q.print("after pop");
    q.pop();
    cout << "peek : " << q.peek() << endl;
    cout << "is empty : " << q.empty() << endl;
    
}
