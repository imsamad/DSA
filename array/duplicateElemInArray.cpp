#include<iostream>
using namespace std;

void fun(int *A,int n){
    int lastDup=0;
    for(int i=0;i<n-1;i++)
        // if(A[i+1]!=lastDup && A[i+1]==A[i]){
        //     lastDup=A[i];
        //     cout<<A[i]<<" ,";
        // }
    if(A[i+1]==A[i]){
        int j=i+1;
        for(;A[j]==A[i];j++);
        cout<<A[i]<<" occured "<<j-i<<" times";
        i=j-1;
    } 
    cout<<endl;
}             
void duplicatesUnsorted(int *A,int n){
    int count=1;
    for(int i=0;i<n-1;i++){
        if(A[i]!=-1){
            count=1;
            for(int j=i+1;j<n;j++){
                if(A[j]==A[i]) {
                    count++;
                    A[j]=-1;
                } 
            }
            if(count>1)
                cout<<A[i]<<" => "<<count<<endl;
        }
    }
}
int main(){
        
    int A[]={6,7,8,8,10,10,10,14,16,25};             
    duplicatesUnsorted(A,10);       
    return 0;
}