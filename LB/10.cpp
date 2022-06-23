#include<iostream>

using namespace std;
int binSearch(int * arr ,int len, int key ) {
    int low=0,last=len-1;
    int mid;

    while( low <= last ) {
        // mid = (low + last) / 2;
        mid = low + (last - low) / 2;
        
        if( arr[mid] == key) {
        
            cout<<key <<" Found "<<endl;
            return key;
        
        } else if( key < arr[mid] ) 
            last=mid-1;
        else
            low=mid+1;
        
    }
    cout<<key <<" Not Found"<<endl;
    return 0;    
}
int main() {
    int len=10;
    // int arr[len]={10,20,30,40,50,60,70,80,90,100};
    int arr[len]={0};
    
    for(int i=10; i>0; i--) arr[10-i] = i*10;
    // for(int i=1; i<=10; i++) arr[i-1] = i*10;
    for(int i=0; i<len; i++) cout<<arr[i]<<"\t";
    cout<<endl;
    binSearch(arr,len,40);
    binSearch(arr,len,400);
    binSearch(arr,len,30);
    binSearch(arr,len,20);

     return 0;  
}
