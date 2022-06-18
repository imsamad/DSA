#include<iostream>
#include "./../13Stack/Stack.cpp"
using namespace std;

template <class T>
class Queue {
    Stack <T>*s1;
    Stack <T>*s2;
    public:
    Queue(){
        s1=new Stack<T>();
        s2=new Stack<T>();
    }
    T enqueue(T data) {
        s1->push(data);
        return data;
    }
    T dequeue() {
        while(!s1->isEmpty()) s2->push(s1->pop());
        return s2->isEmpty() ? 0 : s2->pop();
    }
    int isEmpty() {
        return s1->isEmpty() && s2->isEmpty();
    }
    int isFull() {
        return s1->isFull() && s2->isFull();
    }
};
// int main() {
//     Queue <int>*q=new Queue<int>();
//     cout<<endl<<" Enqueue "<<endl;
//     for(int i=1;i<=20;i++) cout<<q->enqueue(i)<<" ,";
//     cout<<endl<<" Dequeue "<<endl;
//     for(int i=1;i<=20;i++) cout<<q->dequeue()<<" ,";
//     cout<<endl<<"Again Enqueue "<<endl;
//     for(int i=1;i<=20;i++) cout<<q->enqueue(i)<<" ,";

//     cout<<endl<<"Again Dequeue "<<endl;
//     for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
//     cout<<endl<<"Again Again Dequeue "<<endl;
//     for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
//     cout<<endl;    
//     cout<<endl;    
 
//      return 0;
// }