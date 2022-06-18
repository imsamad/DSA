#include<iostream>

using namespace std;
template<class T>
class Queue {
    T *data;
    int size,front,rear;
    public:
    Queue(int size) {
        this->size=size+1;
        rear=front=0;
        this->data=new T[this->size];
    }

    T enqueue(T data) {
        if(isFull())return 0;
        rear=(rear+1) % size;
        this->data[rear]=data;
        return data;
    }
    T dequeue() {
        if(isEmpty())return 0;
        front=(front+1) % size;
        return this->data[front];
    }

    int isFull() { return (rear+1) % size==front; }
    int isEmpty() { return rear==front; }
};

int main() {
    Queue <int>*q=new Queue<int>(10);

    for(int i=1;i<=20;i++) cout<<"insert "<<q->enqueue(i)<<endl;
    for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
    return 0;
}
