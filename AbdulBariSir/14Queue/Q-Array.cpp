#include<iostream>

using namespace std;
template<class T>
class Queue {
    T *data;
    int rear,front,size;
    
    public:
    Queue(int size) {
        this->size=size;
        data=new T[size];
        rear=-1;
        front=-1;
    }
    T enqueue(T data) {
        if(isFull()) return 0;
        this->data[++rear]=data;

        return this->data[rear];
    }

    T dequeue() {
        if(isEmpty()) return 0;

        // Solution 1 - 
        // T key=data[0];
        // for(int i=0;i<rear;i++) data[i]=data[i+1];
        // rear--;
        // return key;
        
        // Solution 2 -resetting pointer
        T key=data[++front];
        if(rear == front) rear=front=-1;
        return key;
        
        // Solution 3 - Circular Queue
    }

    int isFull () { return rear==size-1; }
    int isEmpty () { return  front==rear; }
};
int main() {
    Queue <int>*q=new Queue<int>(10);

    for(int i=1;i<=20;i++) cout<<"insert "<<q->enqueue(i)<<endl;

    for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
    for(int i=1;i<=20;i++) cout<<"insert "<<q->enqueue(i)<<endl;    
    return 0;
}