#include<iostream>

using namespace std;
void swap(int &a,int &b) {
    // cout<<a<<" "<<b<<endl;
    a=a+b;
    b=a-b;
    a=a-b;
}

class Heap {
    int *arr,size,last;
    public:

    Heap(int size=20) {
        this->arr=new int[size];
        this->size=size;
        last=0;
    }

    void insert(int item) {
        int i=++last;

        while(i>1 && item > arr[i/2] ) {arr[i]=arr[i/2]; i/=2;}
        
        arr[i]=item;
    }

    void sort() {
        for(int i=0;i<80;i++) 
            deleteElem();
    }

    int deleteElem(){
        // cout<<"PreDelete "<<last<<endl;
        // display();
        // cout<<endl;
        if(last <=2) {
            if(arr[1] > arr[2])
                swap(arr[1],arr[2]);
            
            return arr[1];  
        }
        
        int elem=arr[1];
        
        arr[1]=arr[last--];
        
        int i=1,j=2;

        while(j < last) {

            if(arr[j+1] > arr[j]) j++;

            if (arr[i] < arr[j]) {
                swap(arr[i],arr[j]);
                i=j;
                j*=2;
            }
            else break;
        }
        arr[last+1]=elem;
        // cout<<"PostDelete "<<last<<endl;
        // display();
        // cout<<endl;

        return elem;
    }

    void display(int dispSorted=0) {
        for(int i=1;i<=8;i++) {
            cout<<arr[i]<<", ";
        }
    }
    void clear() {
        delete arr;
        arr= new int[size];
        last=0;
    }
};

int main() {

    Heap *h=new Heap();

    // for(int i=10;i<=120;i+=10) {
    //     h->insert(i);
    // }
    h->insert(40);
    h->insert(35);
    h->insert(30);
    h->insert(15);
    h->insert(10);
    h->insert(25);
    h->insert(90);
    // h->insert(656);
    // h->insert(5465);
    // h->insert(9878);
    // h->insert(6664);
    // h->insert(8796);
    // h->insert(5466);
    // h->insert(5);
    h->display();
    cout<<endl;
    h->sort();
    h->display();
    
    cout<<endl;


    // h->clear();
    // // for(int i=10;i<=120;i+=10) {
    // //     h->insert_post(i);
    // // }
    // h->insert_post(10);
    // h->insert_post(20);
    // h->insert_post(30);
    // h->insert_post(25);
    // h->insert_post(5);
    // h->insert_post(40);
    // h->insert_post(35);

    // h->display();
    
    cout<<endl;
    return 0;
}