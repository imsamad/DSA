#include<iostream>
using namespace std;

template <class T>
class Stack{
    class Node{
        public:
        T data;
        Node *next;
        Node(T data){
            this->data=data;
            next=NULL;
        }
        Node(){ data=0;next=NULL; }
    };
    
    Node *top;
    public:
    Stack(){ top=NULL; }

    int isEmpty(){ return !top ? 1 : 0 ; }
    
    T push(T data){
        Node *temp=new Node(data);
        if(temp){
            temp->next=top;
            top=temp;
            return top->data;
        }
        return 0;
    }

    T pop(){
        T data=0;
        if(top){
            Node *temp=top;
            top=top->next;
            data=temp->data;
            delete temp;
        }
        return data;
    }

    T stackTop(){ 
        return top ? top->data : 0 ;
    }

    T peek(int pos){
        Node *temp=top;
        for(int i=0;i<pos-1 && temp ;i++) temp=temp->next;
        return temp?temp->data:0;
    }
    void display(){
        Node *temp=top;
        cout<<"Stack is \t";
        while(temp){
            cout<<temp->data<<" ,";
            temp=temp->next;
        }
        cout<<endl;
    }
};

// int main(){
             
//     return 0;
// }