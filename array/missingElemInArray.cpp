#include<iostream>
using namespace std;
/* 
 * O(n)
 * Inner loop is just filling gap
 * 
 */
void diffMethod(int *A,int n){
    int diff=A[0]-0,i=1;
    cout<<"Missing are :- \t";
    for(int i=1;i<n;i++)
        if(A[i]-i!=diff)
            while(diff<A[i]-i)
                cout<<i+diff++<<" ";
    
    cout<<endl;
}        
int main(){
    int A[]={6,7,8,9,10,11,13,14,16,25};             
    diffMethod(A,10);        
    return 0;
}