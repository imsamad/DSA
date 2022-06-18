#include<iostream>
#include "./../14Queue/Q-LL.cpp"
#include "./../13Stack/Stack.cpp"

class Node{
    public:
    int data,height;
    Node *lChild,*rChild;
    Node () {lChild=rChild=NULL;data=0;}
    Node (int d=0,int h=0) { lChild=rChild=NULL; data=d; height=h; }
};

using namespace std;
class Tree {

    protected:

    Node *root;
    int leafNodes_fun(Node*); 
    int deg2_fun(Node*);     
    int internal_fun(Node*);      
    int deg1_fun(Node*);

    int count_fun(Node*);     
    int height_fun(Node*);     
    int sum_fun(Node*);     
    public:
    Tree() { root=NULL;}
    void preorder_rec(Node*,int);    
    void postorder_rec(Node*,int);    
    void inorder_rec(Node*,int);    
    void preorder();
    void inorder();
    void postorder(); 

    void levelorder();

    void create(int *,int);
    void count(){ cout<<"Total Nodes - "<<count_fun(root)<<endl; }  
    void leafNodes(){ cout<<"Leaf Nodes - "<<leafNodes_fun(root)<<endl; }
    void internal(){ cout<<"Internal/Deg 1or2 - "<<internal_fun(root)<<endl; }  
    void deg12(){ internal_fun(root); }

    void deg2(){ cout<<"Degree 2 Nodes - "<<deg2_fun(root)<<endl; }  
    void deg1(){ cout<<"deg1 - "<<deg1_fun(root)<<endl; }  

    void height(){ cout<<"Height - "<<height_fun(root)<<endl; }  
    void sum(){ cout<<"Sum - "<<sum_fun(root)<<endl; }  
    
    void stats() {
        count();
        internal();
        leafNodes();
        deg1();
        deg2();
        height();
        sum();
    }

    void display() {
        preorder();
        inorder();
        postorder();
        levelorder();
        cout<<"------------------------"<<endl;
    }
};

int Tree::deg1_fun(Node *p) {
    if(!p)return 0;
    int left=deg1_fun(p->lChild),right=deg1_fun(p->rChild);
    // if((p->lChild && !p->rChild) || (!p->lChild && p->rChild) ) return left+right+1;
    if(p->lChild!=NULL ^ p->rChild!=NULL) return left+right+1;
    else return left+right; 

}
int Tree::internal_fun(Node *p) {
    if(!p)return 0;
    int left=internal_fun(p->lChild),right=internal_fun(p->rChild);
    if(p->lChild || p->rChild) return left+right+1;
    else return left+right; 
}

int Tree::height_fun(Node *p) {
    if(!p)return 0;
    int left=height_fun(p->lChild),right=height_fun(p->rChild);
    // if(!left && !right)
     if(!p->lChild && !p->rChild) return left+right;
    else if(left > right) return left+1;
    else return right+1; 
}


int Tree::sum_fun(Node *p) {
    if(!p)return 0;

    return sum_fun(p->lChild)+sum_fun(p->rChild)+p->data;
}
int Tree::count_fun(Node *p) {
    if(!p)return 0;

    return count_fun(p->lChild)+count_fun(p->rChild)+1;
}
int Tree::deg2_fun(Node *p) {
    if(!p)return 0;
    int left=deg2_fun(p->lChild),right=deg2_fun(p->rChild);
    if(p->lChild && p->rChild) return left+right+1;
    else return left+right; 

}
int Tree::leafNodes_fun(Node *p) {
    if(!p)return 0;
    int left=leafNodes_fun(p->lChild),right=leafNodes_fun(p->rChild);
    if(!p->lChild && !p->rChild) return left+right+1;
    else return left+right; 
}

void Tree::levelorder() {
    Queue <Node *>*q=new Queue<Node *>();
    q->enqueue(root);
    Node *temp;
    cout<<"LevelOrder - ";
    while(!q->isEmpty()) {
        temp=q->dequeue();
        cout<<temp->data<<", ";
        if(temp->lChild)q->enqueue(temp->lChild);
        if(temp->rChild)q->enqueue(temp->rChild);
    }
    cout<<endl;
}
void Tree::create(int *data, int len) {
    Queue <Node *>*q=new Queue<Node *>();
    int k=0;
    if(!root) root=new Node(data[k++]);
    q->enqueue(root);

    Node *temp;
    while(!q->isEmpty()) {
        temp=q->dequeue();

        int lChildData=k<len ? data[k++] : 0 ;
        if(lChildData) {
            Node *n=new Node(lChildData);
            temp->lChild=n;   
            q->enqueue(n);
        }
        int rChildData=k<len ? data[k++] : 0 ;
        if(rChildData) {
            Node *n=new Node(rChildData);
            temp->rChild=n;   
            q->enqueue(n);
        }
    }
}

void Tree::postorder(){
    if(!root) {
        cout<<"No tree"<<endl;
        return;
    }
    Stack <Node *>*st=new Stack<Node *>();
    Node *temp=root;
    long   int tempInt;
    cout<<"PostOrder - ";
    while(temp || !st->isEmpty()) {
        if(temp) {
            st->push(temp);
            temp=temp->lChild;
        } else {   
            tempInt=(long  int)st->pop();     
            if(tempInt > 0){
                st->push((Node *)-tempInt);
                temp=(Node *)(tempInt);
                temp=temp->rChild;
            } else {
                temp=(Node *)(-1*tempInt);
                cout<<temp->data<<" ,";
                temp=NULL;                    
            }
        }
    }
    cout<<endl;
}
void Tree::inorder(){
    if(!root) {
        cout<<"No tree"<<endl;
        return;
    }
    Stack <Node *>*st=new Stack<Node *>();
    Node *temp=root;
    cout<<"InOrder - ";
    while(temp || !st->isEmpty()) {
        if(temp) {
            st->push(temp);
            temp=temp->lChild;
        } else {
            temp=st->pop();            
            cout<<temp->data<<" ,";
            temp=temp->rChild;
        }
    }
    cout<<endl;
}

void Tree::preorder(){
    if(!root) {
        cout<<"No tree"<<endl;
        return;
    }
    Stack <Node *>*st=new Stack<Node *>();
    Node *temp=root;
    cout<<"PreOrder - ";

    while(temp || !st->isEmpty()) {
        if(temp) {
            cout<<temp->data<<" ,";
            st->push(temp);
            temp=temp->lChild;
        } else {
            temp=st->pop();
            temp=temp->rChild;
        }
    }
    cout<<endl;
}

void Tree::inorder_rec(Node *p=NULL,int call=1) {
        if(!p && call==1){ 
            p=root;
            cout<<"InOrder Rec - ";
        }
        if(!p)return;
        inorder_rec(p->lChild,0);
        cout<<p->data<<" ,";
        inorder_rec(p->rChild,0);
}    

void Tree::postorder_rec(Node *p=NULL,int call=1) {
        if(!p && call==1){ 
            p=root;
            cout<<"PostOrder Rec - ";
        }
        if(!p)return;
        postorder_rec(p->lChild,0);
        postorder_rec(p->rChild,0);
        cout<<p->data<<" ,";
}    

void Tree::preorder_rec(Node *p=NULL,int call=1){
        if(!p && call==1){ 
            p=root;
            cout<<"PreOrder Rec - ";
        }
        if(!p)return;
        cout<<p->data<<" ,";
        preorder_rec(p->lChild,0);
        preorder_rec(p->rChild,0);
}
// int main() {
//     Tree *t=new Tree();
//     int arr[100];
//     for(int i=1;i<=100;i++) arr[i-1]=i+10;
//     t->create(arr,4);
//     // t->preorder();
//     // t->inorder();
//     // t->postorder();
//     t->levelorder();
//     t->leafNodes();

//     t->stats();
//      return 0;
// }