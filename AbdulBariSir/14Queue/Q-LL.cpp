#include<iostream>

using namespace std;
template <class T=int>
class Queue {
    class Node {
        public:
        T data;
        Node *next;
        Node(T data=0,Node *next=NULL) {
            this->data=data;
            this->next=next;
        }
    };
    Node *front,*rear;
    public:
    Queue(Node *front=NULL,Node *rear=NULL) {
        this->rear=rear;
        this->front=front;
    }

    T enqueue(T data) {
        Node *t=new Node(data);
        if(!front) front=rear=t;
        else {
            rear->next=t;
            rear=t;
        }
        return data;
    }
    T dequeue() {
        
        if(!front) {
            return 0;
        }else {
            Node *temp=front;
            front=front->next;
            T tempData=temp->data;
            delete temp;
            return tempData;
        }
    }
    int isEmpty() {
        return front==NULL;
    }
    int isFull() {
        Node * t=new Node();
        if(t){
            delete t;
            return 0;
        }else return 1;
    }
};

// int main() {
//        Queue <int>*q=new Queue<int>();

//     for(int i=1;i<=20;i++) cout<<"insert "<<q->enqueue(i)<<endl;





//     for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
//     for(int i=1;i<=20;i++) cout<<"insert "<<q->enqueue(i)<<endl;

//     for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
//     cout<<endl<<endl;
//     for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
    
 
//      return 0;
// }