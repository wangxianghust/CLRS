#include <iostream>

using namespace std;

const int SIZE = 4;

class Queue{
    public:
        void Enqueue(int);
        int Dequeue();
        void print();
    private:
        int head;
        int tail;
        int array[SIZE];
        bool empty();
        bool full();
};

bool Queue::empty(){
    return ( head == tail );
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

int Queue::Dequeue(){
    if(empty()){
        cout << "downflow" << endl;
    } else {
        int ele;
        ele = array[head];
        if(head == SIZE-1) head = 0;
        else ++head;
        return ele;
    }
}

void Queue::print(){
    int index = head;
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
    q.Enqueue(3);
    q.print();
    cout << "-----" << endl;
    q.Enqueue(4);
    q.Dequeue();
    q.Dequeue();
    q.print();
}
