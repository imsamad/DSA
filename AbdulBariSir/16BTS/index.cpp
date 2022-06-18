#include<iostream>
#include "../15Tree/index.cpp"

using namespace std;
class BTS :public Tree {
    protected:
    int arr[100];
    Node * InPred(Node *);  
    Node * InSucc(Node *);  
    public:
    BTS() {
        for(int i=1;i<=100;i++) arr[i-1]=i*10;
    }
    Node * insert_it(int);
    Node * insert_rec(Node*,int);

    Node * search_it(int);
    Node * search_rec(Node*,int);
    
    Node * deleteNode_fun(Node *,int);
    
    void create(int,int);
    void search(int);
    void deleteNode(int);
};

void BTS::deleteNode(int data){deleteNode_fun(root,data);}
Node * BTS::InPred(Node *p) {
    p= p ? p->lChild : NULL;
    while(p && p->rChild) p=p->rChild;
    return p;
}

Node * BTS::InSucc(Node *p) {
    p= p ? p->rChild : NULL;
    while(p && p->lChild) p=p->lChild;
    return p;
}

Node * BTS::deleteNode_fun(Node *p,int data) {
    
    if(!p) return NULL;

    if(!p->lChild && !p->rChild){
        cout<<"Deleting both are vacant "<<p->data<<endl; 
        if(p==root)root=NULL;    
        delete p;
        return NULL;
    }

    if(data < p->data) p->lChild=deleteNode_fun(p->lChild,data);
    else if(data > p->data) p->rChild=deleteNode_fun(p->rChild,data);
    else {
        int lHeight=height_fun(p->lChild),rHeight=height_fun(p->rChild);

        if(lHeight > rHeight) {
            Node *replacer=InPred(p);
            p->data=replacer->data;
            p->lChild=deleteNode_fun(p->lChild,replacer->data);
       } else {
            Node *replacer=InSucc(p);
            p->data=replacer->data;
            p->rChild=deleteNode_fun(p->rChild,replacer->data);
       }
    }
    return p;
}

void BTS::create(int l=100,int s=0) {
    if(s==-1 && l>0 ){
    for(int i=0;i<l;i++)insert_rec(root,arr[i]);
       return; 
    }
    if(s>l) return;
    int mid=(l+s)/2;
    // insert_it(arr[mid]);
    insert_rec(root,arr[mid]);
    create(mid-1,s);
    create(l,mid+1);
}

void BTS::search(int data){
    Node *res=search_it(data);
    // Node *res=search_rec(root,data);
    if(res)
        cout<<data<<" found"<<endl;
    else  cout<<data<<" Not Found"<<endl;

}

Node * BTS::search_it(int data) {
        Node *t=root;

        while(t) 
            if(t->data==data) return t;
            else if(data < t->data) t=t->lChild;
            else t=t->rChild;
        

        return NULL;
    }

Node * BTS::search_rec(Node *t,int data) {
        if(!t)return NULL;
        if(t->data==data) return t;    
        else if(data < t->data) return search_rec(t->lChild,data);
        else  return search_rec(t->rChild,data);
    }

Node * BTS::insert_rec(Node *n,int data) {
    if(!root) root=n=new Node(data); 
    if(!n) return new Node(data);
     
    if(data < n->data) n->lChild=insert_rec(n->lChild,data);
    else if(data > n->data) n->rChild=insert_rec(n->rChild,data);    
    
    return n;
}

Node * BTS::insert_it(int data) {
    if(!root) {
        root=new Node(data);
        return root;
    }
    Node *p=root,*q=NULL;
    
    while(p) {
        q=p;
        if(data<p->data) p=p->lChild;
        else if(data>p->data) p=p->rChild;
        else return NULL;
    }
    if(data==q->data) return NULL;

    p=new Node(data);
    if(data < q->data)q->lChild=p;
    else if(data > q->data)q->rChild=p;
    
    return p;
}
// int main() {
//     BTS * t=new BTS();
//     t->create(10,-1);    
//     t->display();
//     t->deleteNode(20);
//     t->display();
//     // t->deleteNode(12);
//     // t->display();

//     return 0;
// }