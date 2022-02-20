#include<iostream>
using namespace std;
template <class T>
class CQ{
    int front,rear,size;
    T *A;
    public:

    CQ(int size){
        this->size=size;
        front=rear=-1;
        A=new T[size];
    }

    int isFull(){
        return (rear+1) % size == front;
    }

    int isEmpty(){
        return front==rear;
    }

    T enqueue(T data){
         return  !isFull() ? A[ (rear+1) % size ] = data : -1;
    }

    T dequeue(){
        int data=-1;
        if(!isEmpty()){
            front=(front+1)%size;
            data=A[front];
        }
        return data;
    }
};             
int main(){
                 
    return 0;
}