#include <iostream>

using namespace std;

const int Stack_Size =  10;

struct Stack{ 
public:
    int pop();
    void push(int);
    bool empty();
    void print();
private:
    int top;
    int array[Stack_Size];
};

bool Stack::empty(){
    return (top == 0);
}

int Stack::pop(){
    if(empty()){
        cout << " Empty,underflow " << endl;
        return -1;
    }
    --top;
    return array[top+1];
}

void Stack::push(int ele){
    if(top == Stack_Size-1){
        cout << " overflow_error " << endl;
    } else {
        array[top++] = ele;
    }
}

void Stack::print(){
    for(int i=0; i<top; ++i){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.print();
    S.pop();
    S.print();
    S.pop();
    S.print();
}
