#include<iostream>

using namespace std;

void hammingBits(int num=31) {
    while(num) {
        cout<<(num & 1);
        num=num>>1;
    }
    cout<<endl;
}

void fib(int n=2) {
    if(n<2)return;
    int a=0,b=1;
    cout<<a<<", "<<b<<", ";
    while(n>2) {
        int res=a+b;
        cout<<res<<", ";
        a=b;
        b=res;
        n--;
    }
    cout<<endl;
}

void isPrime(int num) {
    if(num == 0) return;
    // if(num==2 || )
    int flag=1;
    if(num == 1) flag=0;
    for(int i=2; i<=num/2; i++) {
        if( num%i==0 ){
            flag=0;
            break;
        }
    }

    if(flag){
        cout<<num<<" is a prime number ";
    }
    else {
        cout<<num<<" Not a prime number ";
    }
    cout<<endl;
}
void prodSumDiff(int num=234) {
    int sum=0,prod=1;
    while(num) {
        int dig=num%10;
        sum+=dig;
        prod*=dig;
        num/=10;
    }

    cout<<"Res => "<<prod-sum<<endl;
}
int main() {
    for(int i=100;i<1000;i++) {
        // cout<<i<<"=> ";
        // hammingBits(i);
        // fib(i);
        // isPrime(i);
        // prodSumDiff(i);
    }
    prodSumDiff();
     return 0;
}