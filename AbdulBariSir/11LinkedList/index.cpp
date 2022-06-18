#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node(int data=0,Node *next=NULL) {
        this->data=data;
        this->next=next;
    }
};

class LL {
    Node * root;
    Node * last;
    public:
    LL(Node *root=NULL,Node * last=NULL) { this->root=root; this->last=last; }
    void display(){
        Node *temp=root;
        while(temp){ 
            cout<<temp->data<<" ,";
            temp=temp->next;
        }
        cout<<endl;
    }
    void display_r(Node * n=NULL,int call=1){
        if( !n && call==1 ) n=root;

        if(n){
            cout<<n->data<<", ";
            display_r(n->next,0);
        }

    }

    int countNode() {
        Node *temp=root;
        int count=0;
        while(temp) { count++; temp=temp->next; }
        cout<<"Total count is "<<count<<endl;
        return count;
    }

    int countNode_r(Node *n =NULL, int call=1) {
        if(!n && call==1) n=root;

        if(!n) return 0;
        else return 1+countNode_r(n->next,0);
    }

    int sum() {
        Node *temp=root;
        int sum=0;
        while(temp) { sum+=temp->data; temp=temp->next; }
        cout<<"Total sum is "<<sum<<endl;
        return sum;
    }
    
    int sum_r(Node *n =NULL, int call=1) {
        if(!n && call==1) n=root;

        if(!n) return 0;
        else return sum_r(n->next,0)+n->data;
    }

    int max_r(Node *n=NULL,int call=1) {
        if(!n && call==1) n=root;

        if(!n) return -11;

        int x=max_r(n->next,0);

        return n->data > x ? n->data : x;
    }
                
    void insertSorted(int data) {
        
        if(!root || data < root->data ){ insert(data,0); return; }

        Node *n=new Node(data),*p=root;

        while(p->next && p->next->data < data ) p=p->next;

        n->next=p->next;
        p->next=n;
    }

    void insert(int data,int pos=-1){ 
        Node *temp=new Node(data);

        if(pos==0 || !root ){ 
            temp->next=root;
            if(!root) last=temp;
            root=temp;

        } else { 

            Node *p=root;
            if(pos==-1) p=last;
            else for(int i=1; i<pos && p ;  i++) p=p->next;

            if(p) { 
                temp->next=p->next;
                p->next=temp;
                if(pos==-1) last=temp;
            }    
        
        }
    }
    void deleteNode(int pos) {
            Node *temp=root;
        if(pos==1) {
            root=temp->next;
            delete temp;
        } else {

            for(int i=1; i<pos-1 && temp ; i++) temp=temp->next;
            
            if(!temp) return;

            Node *temp2=temp->next;
            temp->next=temp2->next;
            delete temp2;    
        }
    }

    void merge(LL * ll) {
        Node *first=root,*second=ll->root,*final=NULL;

        if(first->data < second -> data) {
            last=final=first;            
            first=first->next;
            last->next=NULL;
        }
        else {
            last=final=second;
            second=second->next;
            last->next=NULL;
        }

        while(first && second) {
            if(first->data < second -> data) {
                last->next=first;
                last=first;
                first=first->next;
                last->next=NULL;
            }
            else {
                last->next=second;
                last=second;
                second=second->next;
                last->next=NULL;    
            }
        }
        while(first){ last->next=first; last=first;first=first->next;last->next=NULL; }
        while(second){ last->next=second; last=second;second=second->next;last->next=NULL; }

        root=final;
    }
    void createLoop(int removeLoop=0 ) {
        if(removeLoop) last->next=NULL;
        else last->next=root;
    }

    int loop() {
        Node *p=root,*q=root;
        
        while(p && q) {
            if (p==q) {
                cout<<"From inside Yes loop exist"<<endl;
                break;
            }
            p=p->next;
            q=q->next;
            q=q ? q->next : NULL;
        } 

        return q==p ? 1 :0 ;
    }

    void removeDuplicates() {
        Node *t=root;

        while( t && t->next ) {
            if( t->data == t->next->data ) {
                Node *temp=t->next;
                t->next=temp->next;
                delete temp;
            } else t=t->next;
        }
    }

    int isSorted() {
        Node *t=root; 
        while( t && t->next ) { 
            if(t->data > t->next->data ) return 0;
            t=t->next;
        }
        return 1;
    }
};

/*
search, r
reverse, r
*/

// int main() {
//     LL *l =new LL(),*l2=new LL();

//     for(int i=10;i<=50;i+=10)
//         l->insert(i);

    // for(int i=110;i<=1000;i+=100)
    //     l2->insert(i);
    
    // l2->insertSorted(3);
    
    // l->insert(10);

    // l->display_r();
    // cout<<endl;
    // l->createLoop();
    // cout<<l->loop();
    // l->merge(l2); 
    // l->removeDuplicates(); 
    // l->display_r();
    // cout<<endl;

    // cout<<l->isSorted()<<" is sorted "<<endl;
    


//     return 0;
// }