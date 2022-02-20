#include<iostream>
using namespace std;
void fib(int n){
    int a=0,b=1;
    cout<<"Fibna"<<endl;
    for(int i=1; i<=n ; i++) {
        int next=a+b;
        cout<< next << " ,";
        a=b;
        b=next;
    }
    cout<<endl;
}             

int main(){
    fib(20);         
    return 0;
}