#include<iostream>
using namespace std;
int binSearch(int *A,int size,int key) {
    int start=0,end=size-1,mid;

    while(start<=end) {
        // mid=(start+end)/2; // edge case
        mid=start+((end-start)/2);
        
        if(A[mid]==key || A[start]==key || A[end]==key) return key;

        if(key<A[mid]) end=mid-1;
        
        else start=mid+1;
    }
    return -1;
}             
int main(){
    int E[6]={2,4,6,8,12,18};
    int O[5]={3,8,11,14,16};
    for(int i=0;i<20;i++) cout<<i<<"\t"<<binSearch(E,6,i)<<endl;
    cout<<"==========================="<<endl;
    for(int i=0;i<20;i++) cout<<i<<"\t"<<binSearch(O,5,i)<<endl;
    return 0;
}