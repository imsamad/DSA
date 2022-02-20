#include<iostream>
using namespace std;
void swap(int *x,int *y){
    if(*x==*y) return;
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}
void reverse(int *A,int n){
    for(int i=0, j=n - 1; i < j; i++ , j--) swap(A+i,A+j);
}
void display(int *A,int n){
    for(int i=0;i<n;i++)cout<<A[i]<<", ";
    cout<<endl;
}

void maxMin(int *A,int n){
    int max=A[0],min=A[0];
    for(int i=0;i<n;i++)
        if(A[i]<min)min=A[i];
        else if(A[i]>max)max=A[i];
    cout<<"Max is "<<max<<endl;
    cout<<"Min is "<<min<<endl;
}
long long int factorial(int n){
    long long sum=n;
    for(int i=n-1;i>1;i--)sum*=i;
    return sum;
}
void negToLeft(int *A,int n){
    int i=0,j=n-1;
    while(i<j){

    }
    // for(int i=0,j=n-1;i<j;i++)
}


int * unionSet(int *A,int m,int *B,int n){

}
int * intersectionSet(int *A,int m,int *B,int n){

}

void pairOfElem(){
    
}




int main(){ 
    int A[]={1,2,3,4,5,6,7,8,9,10};
    // reverse(A,10);
    // display(A,10);   
    // maxMin(A,10);
    for(int i=1;i<100;i++) cout<<i<<" => "<<factorial(i)<<endl;          
    return 0;
}