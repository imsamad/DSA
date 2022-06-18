#include<iostream>

using namespace std;


template <class T>
class Stack {
    class Node {
        public:
            T data;
            Node * next;
            Node (T data = 0, Node * next=NULL) {
                this->next=next;
                this->data=data;
            }
    };
   
    Node *top;
    public:
    Stack (Node *top=NULL) { 
        this->top=top;
    }

    T push(T data) {
        Node *temp=new Node(data);
        temp->next=top;
        top=temp;
        return top->data;
    }
    T stackTop() { return top?top->data:0; }
    T pop() {
        if(!top) return 0;

        Node *temp=top;
        top=top->next;

        T data=temp->data;
        delete temp;
        return data;
    }

    int isEmpty() { return top ? 0 : 1 ; }
    int isFull() {
        Node *t=new Node();
        if(t){
            delete t;
            return 0;
        } 
        return 1; 
    }

    T peek(int pos) {
        Node *t=top;
        for(int i=1 ; i<pos && t ; i++) t=t->next;
        return t ? t->data : 0;
    }
};

// int main() {
//     Stack  <int>*s =new Stack<int>();

//     for(int i=10;i<=100;i+=10) s->push(i);
    
//     for(int i=1;i<=10;i++) cout<<i<<" => "<<s->peek(i)<<" ,";




//     return 0;
// }