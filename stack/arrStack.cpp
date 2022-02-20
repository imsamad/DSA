#include<iostream>
using namespace std;

template <class T>
class Stack{
    T *A;
    int top,size;
    public:
    Stack(int size){
        A=new T[size];
        this->size=size;
        top=-1;
    }
    int isFull(){ 
        return top==size-1 ? 1 : 0; 
    }

    int isEmpty(){
        return top==-1 ? 1 : 0;
    }

    T push(T data){
        return !isFull() ? A[++top] = data : -1;
    }

    T pop(){
        return !isEmpty() ? A[top--] : -1;
    }

    T peek(int pos){
        int x=top-pos+1;
        return x < 0 || x > top ? -1 : A[x];
    }    
    void display(){
        cout<<"Stack is "<<"- \t";
        for(int i=top;i>=0;i--)cout<<A[i]<<" ,";
        cout<<endl;
    }
};             
// int main(){
//     return 0;
// }