#include<iostream>
#include<math.h>
using namespace std;

/**
 * 1.) DecToBin with exception
 * 2.) complement by mask 
 * 3.) is power of two(by brute force or optimised)
 */

// long long
 int decToBinary(int num) {
    // long long
     int ans=0;
    for(int i=0; num; i++, num>>=1 )
        ans+=(num&1) * pow(10,i);
    
    return ans;
}

long long int decToBinary2(int num) {
    long long int ans=0;
    for(int i=0; num; i++, num/=2 )
        ans+=(num%2) * pow(10,i);
    
    return ans;
}

int binToDec(int num) {
    int ans=0;
    for(int i=0; num; num/=10, i++)
        ans+=(num%2)*pow(2,i);
    return ans;
}

int reverseDecimal(int num) {
    int ans=0;
    for(int i=0; num; i++, num/=10)
        if(ans > INT32_MAX/10 || ans < INT32_MIN/10) return 0;
        else {
            cout<<(num%10)<<endl;
            cout<<ans<<endl;
            ans=(num%10)+(ans*10);
        }

    return ans;
}

void makeAllOne(){
    unsigned long long int x=0,j=1,i=0;
    for(i=0;i<sizeof(x)*8-1;i++){
        // cout<<(j<<i)<<endl;
        x=x|1<<i;
    }
    cout<<x<<endl;
}
void sqr(){
    for(int i=1; i<sizeof(i)*8; i++)
        cout<<i<<" => "<<(1<<i)<<endl;
}

int complementOfDecimal(int num){
    int binComp=0,temp=1;
    for(int i=0; num; num/=2, i++) 
        binComp+=( num % 2 ? 0 : 1) * pow(10,i);
    int decComp=0;
    for(int i=0; binComp; binComp/=10, i++) {
        decComp+=(binComp % 10)*pow(2,i);
    }
    // for(int i=0; num; num/=2, i++) {
    //     decComp+=(num%2) * pow(10,i);
    // }
    return decComp;
}
int complementOfDecimalMask(int num2){
    // edge case
    if(!num2) return 0;
    int mask=0,num=num2;
    
    for(int i=0; num; i++,num>>=1) {
        mask=(mask<<1)|1;
        // mask|=1;
    }
    cout<<"mask "<<mask<<endl;
    // return INT32_MIN & num2;
    // return mask & ~num2;
    return ~num2;
}
int main(){
    // cout<<"decToBinary 12 " << decToBinary(12)<<endl;   
    // cout<<"binToDec 12 "<< binToDec(10)<<endl;       
    // cout<<"decToBinary2 10 " << decToBinary2(10000)<<endl;          
    // cout<<"reverseDecimal 2147 " << reverseDecimal(-2147)<<endl;          
    // cout<<sizeof(int)<<endl;
    // makeAllOne();
        // // sqr();
        // cout<<(4%2)<<endl;
        // cout<<(2%2)<<endl;
        // cout<<(0%2)<<endl;
        // cout<<(1%2)<<endl;
    cout<<complementOfDecimalMask(5)<<endl;
        // cout<<INT8_MAX<<" , "<<INT8_MIN<<endl;
    // cout<<INT16_MAX<<" , "<<INT16_MIN<<endl;
    // cout<<INT32_MAX<<" , "<<INT32_MIN<<endl;
    return 0;
}