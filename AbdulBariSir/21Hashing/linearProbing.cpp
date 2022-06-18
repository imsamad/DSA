#include<iostream>

using namespace std;
class Hash {
    int *arr,size;
    public:
    Hash(int size){
        arr=new int[size];
        this->size=size;
    }
    int hash(int key){
        return key % size;
    }
    int probe(int key) {
        int i=0;
        int index=hash(key);

        while(arr[index+i]%size) i++;

        return (index+i) % size;
    }
    int insert(int key,int show=0) {
        int index=hash(key)%size;

        int i=0;
        // for(  ; i<size &&  arr[index] ; i++ ){ 
        //     if(show) {
        //         cout<<"index" <<index<<endl;
        //         cout<<"i" <<i<<endl;
        //     }
        //     index=(index+1)%size;

        // }
        
        for(  ; i<size &&  arr[(index+i)%size] ; i++ );

        // cout<<"key = "<<key<<" index "<<index<<",i = "<<i<<endl;
        if(i>=size) {
            cout<<"Oberflow "<<endl;
            return 0;
        }
        
        index=(index+i)%size;
        arr[index]=key;
        return arr[index];
    }

    void display() {
        for(int i=0;i<size;i++) cout<<arr[i]<<", ";
        cout<<endl;
    }

    int search(int key) {
        int index=hash(key)%size;

        int i=0;
        // while(arr[index+i]!=key && i<size ){    i++; }
        for(  ; i<size &&  arr[(index+i)%size]!=key ; i++ );
        // cout<<key<<" , index= "<<index<<", i= "<<i<<endl;
        index=(index+i)%size;    

        if( arr[index]==key )return index;
        return -1;
    }
};
int main() {

    // cout<<(0%10)<<endl;
    Hash h(10);
    h.insert(10);
    h.insert(11);    
    h.insert(12);    
    h.insert(13);    
    // h.insert(14);    
    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(45);
    h.insert(55);
    h.insert(65,1);
    // h.insert(75,1);
    
    // h.insert(65);
    // h.insert(75);
    // h.insert(85);
    // h.insert(90);
    h.display();

    for(int i=0;i<100;i++) {
        if(h.search(i)!=-1){
            cout<<i<<" = "<<h.search(i)<<endl;
        }
    }    
     return 0;
}