#include<iostream>
using namespace std;
void ques1(){
    for(int i=0; i <= 15; i+=2){
        cout<<i<<" => "<<(i&1)<<endl;
        if( i&1 )continue;
        i++;
    }            

}
void infiniteLoop(){
    for(int i = 0; i<=15; i--){
        cout<< i << " ";
        i++;
    }
}      
void breakNeverExecute(){
    for(int i = 0; i<5; i++)
        for(int j = i; j<=5; j++){
            if(i+j == 10)break;
            cout<< i << " " << j <<endl;
        }
}
void compilerKnow(){
    int x=3*4/5+6-2;
    int y=((3*4)/5)+6-2;
    cout<<x<<endl;
    cout<<y<<endl;
}   
void proMinusSum(int num) {
    int product=1,sum=0;
    while(num) {
        product*= num % 10;
        sum+= num % 10;
        num/=10;
    }
    cout<< "Producct => "<<product<<endl;
    cout<< "Sum => "<<sum<<endl;
}    
int hammingWheight(int n) {
    int count=0;
    while(n){
        if(n&1) count++;
        n>>=1;
    }    
    return count;
}
int main(){
    // ques5(234);
    cout<<"1 in 11 "<<hammingWheight(11)<<endl;
    cout<<"1 in 12 "<<hammingWheight(12)<<endl;
    cout<<"1 in 13 "<<hammingWheight(13)<<endl;
    return 0;
}