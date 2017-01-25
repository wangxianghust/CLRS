// for problem 10.2-1 -2 -7
// head is nullptr to denote the null list
// node.next is null means the last element of the list
#include<iostream>

using namespace std;

class Node{
    public:
        Node():next(nullptr), key(-10086){} 
        Node(int k):next(nullptr), key(k){}
        Node* next;
        int key;
};

class List{
    public:
        List():head(nullptr){}  // head is nullptr means that the list is null
        Node* Search(int i);
        void Insert(int i);
        void Delete(int i);
        Node* Inverse();
        void print();
    private:
        Node* head;
};

// Change the direction of the link.
Node* List::Inverse(){ 
    Node* next_to_handle(nullptr);
    Node* prev(nullptr);
    while(head != nullptr){ // head is moving
        next_to_handle = head->next; // save the next to handle
        head->next = prev; // change the direction of the link
        prev = head;    // pre is now head
        head = next_to_handle;
    }
    head = prev;
    return prev;   
}

Node* List::Search(int i){
    Node* x = head;
    if(x != nullptr){
        while(x->next != nullptr && x->next->key != i){
            x = x->next;
        }
        return x->next;
    } else {
        cout << "List is null" << endl;
    }
}

void List::Insert(int i){
    Node* Ins = new Node;
    Ins->key = i;
    if(head != nullptr){
        //cout << "head is not null" << endl;
        Ins->next = head->next;
        head->next = Ins;
    } else {
        head = new Node;
        head->next = Ins;
        //cout << "head is null" << endl;
    }
} 

void List::Delete(int i){
    Node* iter = head;
    while(iter->next != nullptr && iter->next->key != i){
        iter = iter->next;
    }    
    if(iter->next == nullptr){
        cout << "can not find the element to delete" << endl;
    } else {
        Node* del = iter->next;
        iter->next = del->next;
    }
}

void List::print(){
    Node* iter = head;
    if(iter != nullptr){
        while(iter->next != nullptr){
            cout << iter->next->key << " ";
            iter = iter->next;
        }
        cout << endl;
    }
}

int main(){
    List L;
    L.Insert(1);
    L.Insert(2);
    L.Insert(3);
    L.print();
    L.Delete(1);
    L.print();
    auto ret = L.Search(2);
    cout << "Search " << ret->key << endl;
    L.Insert(5);
    L.Insert(6);
    L.print();
    L.Inverse();
    L.print();
}
