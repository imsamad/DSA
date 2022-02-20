#include<iostream>
using namespace std;
template <class T>
class LL{
    class Node{
        public:
        Node* next;
        T data;
        Node(T c){
            data=c;
            next=NULL;
        }
    };

    Node *front,*rear;
    public:
    LL(){ front=rear=NULL; }
    T enqueue(T data){
        Node *n=new Node(data);
        if(!front) front=rear=n;
        else {
            rear->next=n;
            rear=n;
        }
        return n->data;
    }

    T dequeue(){
        T data=0;
        if(!isEmpty()){
            Node *temp=front;
            front=front->next;
            data=temp->data;
            delete temp;
        }
        return data;
    }

    int isEmpty(){ return !front; }

};             
int main(){
             
    return 0;
}