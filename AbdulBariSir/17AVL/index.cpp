#include<iostream>
#include "../15Tree/index.cpp"
// #include "../16AVL/index.cpp"

using namespace std;

class AVL  :public Tree {
    protected:
    int arr[100];
    public:

    AVL() {
        for(int i=1;i<=100;i++) arr[i-1]=i*10;
    }
    Node * LLRotation(Node *);
    Node * LRRotation(Node *);
    Node * RRRotation(Node *);
    Node * RLRotation(Node *);
    int NodeHeight(Node *);
    Node * insert_rec(Node*,int);
    void create(int,int);
    int BalanceFactor(Node *);
};

int AVL::NodeHeight(Node * p) {
    int hl=p && p->lChild ? p->lChild->height : 0,
    hr=p && p->rChild ? p->rChild->height : 0;
    return  hl > hr ? hl+1 : hr+1;
}

int AVL::BalanceFactor(Node * p) {
    int hl=p && p->lChild ? p->lChild->height : 0,
    hr=p && p->rChild ? p->rChild->height : 0;
    return  hl - hr;
}
Node * AVL::insert_rec(Node *n,int data) {
    if(!root) root=n=new Node(data,0); 
    if(!n) return new Node(data,0);
     
    if(data < n->data) n->lChild=insert_rec(n->lChild,data);
    else if(data > n->data) n->rChild=insert_rec(n->rChild,data);    
    n->height=NodeHeight(n);    
    if(BalanceFactor(n) ==2 && BalanceFactor(n->lChild)==1 )
       return LLRotation(n); 
    else if(BalanceFactor(n) ==2 && BalanceFactor(n->lChild)==-1 )
       return LRRotation(n); 
    if(BalanceFactor(n) ==-2 && BalanceFactor(n->rChild)==-1 )
       return RRRotation(n); 
    if(BalanceFactor(n) ==-2 && BalanceFactor(n->rChild)==1 )
       return LRRotation(n); 
    return n;
}

void AVL::create(int l=100,int s=0) {
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

Node * AVL::LLRotation(Node * node) {
    Node *nodeL=node->lChild,*nodeLR=node->lChild->rChild;

    node->lChild=nodeLR;
    nodeL->rChild=node;

    node->height=NodeHeight(node);
    nodeL->height=NodeHeight(nodeL);
    
    if(root==node){
        root=nodeL;
    }
    return nodeL;
}

int main() {
    AVL *a=new AVL();
    a->create(5);
    a->display();
    return 0;
} 