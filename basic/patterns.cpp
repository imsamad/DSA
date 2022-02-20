#include<iostream>
using namespace std;

void square(int n=4){
/*
    1 2 3 
    4 5 6 
    7 8 9
*/
    int count=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
           cout<<count++<<" ";
        cout<<endl; 
    }
}

void tri(int n=4){
/*
    1 
    2 3 
    4 5 6 
    7 8 9 10 
*/
    int count=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
           cout<<count++<<" ";
        cout<<endl; 
    }
}

void tri2(int n=4){    
/*
    1 2 3 4 
    5 6 7 
    8 9 
    10
*/
    int count=1;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++)
           cout<<count++<<" ";
        cout<<endl; 
    }
}
void tri3(int n=4){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++)
           if(j-i)cout<<"* ";
        cout<<endl; 
    }
}
void charSq(int n=4){
/*
    A A A A 
    B B B B 
    C C C C 
    D D D D
*/
    for(int i='A';i<'A'+n;i++){
        for(int j=1;j<=n;j++)
            // cout<<i<<" ";
            cout<<(char)(i)<<" ";
        cout<<endl;    
    }
}

void charSqInc(int n=4){
/*
    A B C D 
    B C D E 
    C D E F 
    D E F G
*/
    // A to D = 65,66,67,68 == 65+3=5+(4-1)=68
    for(int i='A';i<'A'+n;i++){
        for(int j=i;j<i+n;j++)
            // cout<<i<<" ";
            cout<<(char)(j)<<" ";
        cout<<endl;    
    }

}

void charTri(int n=4){
/*
    A
    BB
    CCC
    DDDD
*/
    for(int i=0;i<4;i++){
        for(int j=0;j<=i;j++)
            cout<<(char)(i+'A')<<"";
        cout<<endl;        
    }
}

int main(){
    //  square(3);
    // tri();        
    // tri2();
    // charSq();
    // charSqInc();
    charTri();
    return 0;
}