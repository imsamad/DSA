#include<iostream>
#include<math.h>
//Add it
#include <bits/stdc++.h>
using namespace std;
void reverseInt(int num=4968) {
    int res=0;
    for(; num ; num/=10) { 
        int dig=num % 10;
        if( (res > INT_MAX / 10) || (res < INT_MIN / 10) ) {
            cout<<"Out of range "<<endl;
            return;
        }
        res=(res * 10) + dig;

    }
    // for(;num; res=(res*10)+(num % 10), num/=10 ) ;
    cout<<res<<endl;
}
void complement(int num = 31 ) {
        int dup=num,mask=0;
        if(num==0) dup=1;
        while(dup) {
            mask=(mask << 1) | 1;
            dup>>=1;
        }
        int ans=(~num) & mask;
        cout<<num<<" = "<<ans<<endl; 
}

void isInPowerOf2(int num) {
    int ans=1;
    for(int i=0; i<=30 && num >= ans ; i++) {
        if( ans == num  ) {
            cout<<num<<" Yes"<<endl;
            return;                 
        }
        // no need to worry if num = 2^30 bcoz upper if block will got executed.
        // if(num== 2^ 31)

        if(ans < INT_MAX / 2) 
            ans*=2;
    }

    cout<<ans << " ="<<num<<" not"<<endl; 
}
int main() {
    isInPowerOf2(0);
    isInPowerOf2(1);
    isInPowerOf2(1073741824);
    isInPowerOf2(1073741840);
    isInPowerOf2(2147483648);
    // for(int i=0;i <50; i++) isInPowerOf2(i);    
    // complement();
    // complement(1);
    // complement(5);
    // complement(7);
    // complement(10);
    // complement(0);
    // reverseInt(1073741824);
    // cout<<pow(2,31)<<endl;
    // cout<<INT_MIN<<endl;
    // cout<<INT_MAX<<endl;
     return 0;
}