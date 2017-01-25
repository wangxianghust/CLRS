#include <iostream>

using namespace std;

const int SIZE = 5;

class Queue{
    public:
        Queue():head(0),tail(1){}
        void Enqueue(int);
        void Enqueue_front(int);
        int Dequeue();
        int Dequeue_back();
        void print();
    private:
        int head;
        int tail;
        int array[SIZE];
        bool empty();
        bool full();
};

bool Queue::empty(){
    return ( (tail-head == 1) | (head-tail == SIZE-1) );
}

bool Queue::full(){
    return ( (tail-head == SIZE-1)|( head-tail == 1 ) );
}

void Queue::Enqueue(int ele){
    if(full()){
        cout << "overflow" << endl;
    } else {
        array[tail] = ele;

        if(tail == SIZE-1) tail = 0;
        else ++tail;
    }
}

void Queue::Enqueue_front(int ele){
    if(full()){
        cout << "overflow_error" << endl;
    } else {
        array[head] = ele;

        if(head == 0) head = SIZE-1;
        else --head;
    }
}

int Queue::Dequeue(){
    if(empty()){
        cout << "downflow" << endl;
    } else {
        int ele;
        if(head == SIZE-1) {
            ele = array[0];
            head = 0;
        } else {
            ele = array[++head];
        }
        return ele;
    }
}

int Queue::Dequeue_back(){
    if(empty()){
        cout << "underflow_error" << endl;
    } else {
        int ele;
        if(tail == 0){
            ele = array[SIZE-1];
            tail = SIZE-1;
        } else {
            ele = array[--tail];
        }
        return ele;
    }
}

void Queue::print(){   // use print to control which element we can see.
    int index = head+1;
    while(index != tail){
        if(index == SIZE){
            index = 0;
        }
        cout << array[index++] << endl;
    }
}

int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue_front(3);
    q.print();
    cout << "-----" << endl;
    q.Enqueue_front(4);
    q.Dequeue_back();
    q.Dequeue();
    q.print();
}

