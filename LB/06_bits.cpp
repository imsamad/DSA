#include<iostream>
#include<math.h>

using namespace std;

void decToBin(int num=31) {


    int dup=num;

    int res=0;
    
    for(int i=0; num; num>>=1, i++ ) 
    {
       int dig=num&1;     
        res+=( dig * pow(10,i) );        
    }
    cout<<dup<<" => "<<res<<endl;

}

void reverse(int num=4568) {
    int dup=num;
    int res=0;

    for(; num ; res = ( (res *10) + (num %10) ), num/=10 ) ;
    
    cout<<dup<<" => "<<res<<endl;
    
}
void compilerKnow(){
    int x=3*4/5+6-2;
    int y=((3*4)/5)+6-2;
    cout<<x<<endl;
    cout<<y<<endl;
} 
void binToDec() {
    int num;
    cout<<"Enter num \t";
    cin>>num;
    cout<<endl;
    int res=0,i=0;

    while(num) {
        int dig = num % 10;
        if(dig) res = res + pow(2,i);
        num/=10;
        i++;
    }

    cout<<"Res => "<<res<<endl;

} 
int main() {
    // decToBin(2);
    // reverse();
    for(int i=0; i<10; i++){ 
        binToDec();    
        // decToBin(i);
        // reverse(i);
        // decToBin(i);
    } 
    return 0;
}
