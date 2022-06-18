#include<iostream>
#include "./Q-Stack.cpp"
using namespace std;
class PriorityQueues {
    Queue <int>**q;
    int noOfPriorities;
    public:
    PriorityQueues(int noOfPriorities) {
        this->noOfPriorities=noOfPriorities;
        q=new Queue<int>*[noOfPriorities];
        
        for(int i=0;i<noOfPriorities;i++) q[i]=new Queue<int>();
    }
    int enqueue(int pNo) {
        if(pNo > noOfPriorities-1) return 0;  
        return q[pNo]->isFull() ? 0 :q[pNo]->enqueue(pNo+1);
    }
    int getSpecificPriority(int pNo) {

        if(pNo>noOfPriorities-1) return 0;  
       return q[pNo]->isEmpty() ? 0: q[pNo]->dequeue();
    }    
    int dequeue() {
        for(int i=0;i<noOfPriorities;i++){
            int item=q[i]->dequeue();
            if(item) return item;
        }
        return -1;
    }
};
int main() {
    PriorityQueues *q=new PriorityQueues(10);
    cout<<endl<<" Enqueue "<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++)
            cout<<q->enqueue(i)<<" ,";
        cout<<endl;
    }
    cout<<endl<<" Dequeue "<<endl;

    for(int i=0;i<=1000;i++){
            cout<<q->dequeue()<<" ,";
       
    }    
    // cout<<endl<<" Dequeue "<<endl;
    // for(int i=1;i<=20;i++) cout<<q->dequeue()<<" ,";
    // cout<<endl<<"Again Enqueue "<<endl;
    // for(int i=1;i<=20;i++) cout<<q->enqueue(i)<<" ,";

    // cout<<endl<<"Again Dequeue "<<endl;
    // for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
    // cout<<endl<<"Again Again Dequeue "<<endl;
    // for(int i=1;i<=20;i++) cout<<q->dequeue()<<", ";
    cout<<endl;    
    cout<<endl;    
 
     return 0;
}