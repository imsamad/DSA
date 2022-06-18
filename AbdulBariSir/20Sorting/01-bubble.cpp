#include<iostream>

#include "../14Queue/Q-LL.cpp"

using namespace std;

void swap(int &a,int &b){
    // if(a==b)return;
    int same=a==b;
    if(same)return;
    a=a+b;
    b=a-b;
    a=a-b;

}

void shell(int *arr,int len){
    for(int gap=len/2; gap > 0 ; gap/=2) {
        for(int i=0; i<len; i++) {
            if(!(i+gap < len)) continue;
            if(arr[i] > arr[i+gap]) { 
                swap(arr[i],arr[i+gap]);
                for(int j=i; j-gap > -1  && arr[j] < arr[j-gap]; j=-gap ) 
                    swap(arr[j],arr[j-gap]);
            }    
        }
    }
}
void shellSort(int *arr,int len) {
    for(int gap = len/2; gap >= 1; gap/=2) {
        for(int i=gap; i<len; i++) {
            int temp=arr[i];
            int j=i-gap;
            while(j>0 && arr[j] > temp ) {
                arr[j+gap]=arr[j];
                j=j-gap;
            }
            arr[j+gap]=temp;
        }
    } 
}
void binBkt(int *arr,int len,int max) {

    Queue <int>**bins=new Queue<int>*[max+1];
    for(int i=0;i<max+1;i++) bins[i]=new Queue<int>();

    for(int i=0;i<len;i++) bins[arr[i]]->enqueue(arr[i]);
    int k=0;
    
    for(int i=0;i<max+1;i++){ 
        // Node *bin=bins[i]->root;
        Queue <int>*bin=bins[i];
        while(!bin->isEmpty()) 
            arr[k++]=bin->dequeue();
        
    }
    delete bins;    
}

void dis(int *arr,int len){
    cout<<"Array is - ";
    for(int i=0;i<len;i++)
        cout<<arr[i]<<", ";
    cout<<endl;
}

void bubbleSort(int *arr,int len,int passes=0) {
    int pass=passes && passes < len ? passes : len-1;
    cout<<pass<<endl;
    for(int i=0; i < pass ; i++){
        int count=0;
        for(int j=0; j<len-1-i ; j++){
            if(arr[j] > arr[j+1]) {
                 count=1;
                 swap(arr[j],arr[j+1]);
            } 
        }
        if(!count) {
            // cout<<i<<" Break"<<endl;
            break;
        }
    }
}

void insertion(int *arr,int len,int item) {
    int i=len-1;

    while(i>=0 && arr[i] > item ) { 
         arr[(i--)+1]=arr[i];
        //  i--;
    }

    arr[i+1]=item;
}

void insertSort(int *arr,int len) {
    for(int i=1; i < len; i++) {
        int item=arr[i], j=i-1;
        for( ; j>-1 && arr[j] > item ; j-- ) 
            arr[j+1]=arr[j];
                
        arr[j+1]=item;

    }

}

void selection(int *arr,int len) {
    for(int i=0;i<len-1;i++) {
        int k=i;
        for(int j=i+1 ;j<len ; j++)
            if(arr[j] < arr[k]) k=j;

        swap(arr[k],arr[i]);
    }
}

void count(int *arr,int len,int max) {
    int *bin=new int[max+1];
    for(int i=0;i<len;i++) bin[arr[i]]++;
    int k=0;
    for(int i=0;i<max+1;i++)
        while(bin[i]) {
             arr[k++]=i;
             bin[i]--; 
        }

}

void radixSort(int *arr,int len) {
    int maxD=0;
    for(int i=0;i<len;i++) {
        int count=0;
        for(int num=arr[i]; num>0; num/=10) count++;
        if(maxD<count) maxD=count;
    }

    Queue <int>**bins=new Queue<int>*[10];
    for(int i=0; i<10; i++) bins[i]=new Queue<int>();

    for(int mod=1; maxD>=1 ; mod*=10 ,maxD-- ) {

        for(int i=0; i<len; i++){
            int index=(arr[i]/mod)%10;

            bins[index]->enqueue(arr[i]);
        }
        int k=0;
        for(int i=0; i<10; i++){
            while(!bins[i]->isEmpty()) arr[k++]=bins[i]->dequeue();
        }

    }   


}

int main() {
    int len=11;
    // int arr[len]={9,5,16,8,13,6,1200,100,4,2,3};
    int arr[len]={9,5,16,8,13,6,1200,100,4,2,3};

    // int len=6;
    //  int arr[len]={25,8,6,2,7,15};
     //  int arr[len]={2,5,6,7,8,52};
    //  bubbleSort(arr,5);
    dis(arr,len);
    radixSort(arr,len);
    // shell(arr,len);
     dis(arr,len);
    //  insertion(arr,5,10);
    //  dis(arr,6);
    //  insertion(arr,6,1);
    //  dis(arr,7);
     return 0;
}