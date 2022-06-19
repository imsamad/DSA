#include<iostream>

using namespace std;
void pat1(int n=4){
    cout<<"----------------------"<<endl;
    for(char i='A'; i<'A'+n; i++){
        for(int j=0; j<n; j++)
            cout<<i<<" ";
        cout<<endl;
    }
}
void pat2(int n=4){
    cout<<"----------------------"<<endl;
    for(char i='A'; i<'A'+n; i++){
        for(char j='A'; j<=i; j++)
            cout<<i<<" ";
        cout<<endl;
    }
}

void pat3(int n=4){
    cout<<"----------------------"<<endl;
    // for(char i='A'; i<'A'+n; i++){
    //     for(char curr=i, j=0; j<=(int)(i-'A'); j++,curr++)
    //         cout<<curr<<" ";
    //     cout<<endl;
    // }
    for(int i=0; i<n; i++){
        for(char curr='A'+i, j=0; j<=i; j++,curr++)
            cout<<curr<<" ";
        cout<<endl;
    }
}
void pat4(int n=4){
    cout<<"----------------------"<<endl;
    char fin='A';
    for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
            cout<<fin++<<" ";
        cout<<endl;
    }
}
void pat5(int n=4){
    cout<<"----------------------"<<endl;
    // char fin='A';
    for(int i=0; i<n; i++){
    char fin='A'+i;
    for(int j=0; j<n; j++)
            cout<<fin++<<" ";
        cout<<endl;
    }
}
void pat6(int n=4) {
    for( int i=0; i<n; i++) {
        char curr='A'+n-1-i;
        for(int j=0; j<=i; j++, curr++)
            cout<<curr;
        cout<<endl;
    }
}


/************************ Start ***************************/

void pat7(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++)
            cout<<( j>=i ? "*" : " " );
        cout<<endl;
    }
}
void pat8(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++)
            // cout<<( j>=i ? "*" : " " );
            cout<<"*";
        cout<<endl;
    }
}
/******************** Numbers ***************************/
void pat9(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            if(j>=i)cout<<i;
            else cout<<" ";
        cout<<endl;
    }
}

void pat10(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=n; i>=1; i--) {
        for(int j=1,curr= n-i+1 ; j<=n; j++)
            if(j>=i) cout<<curr;
            else cout<<" ";
        cout<<endl;
    }
}
void pat11(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1, curr=i; j<=n; j++) 
            if(j >= i) cout<<curr++;
            else cout<<" ";    
        cout<<endl;
    }
} 
void pat12(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=1, fin=1; i<=n; i++) {
        for(int j=1; j<=n; j++) 
            if(j >= i) cout<<fin++;
            else cout<<" ";    
        cout<<endl;
    }
} 
void pat13(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=n, fin=1; i>=1; i--) {
        for(int j=1; j<=n; j++) 
            if(j >= i) cout<<fin++;
            else cout<<" ";    
        cout<<endl;
    }
} 
void pat14(int n=4) {
    cout<<"----------------------"<<endl;
    for(int i=n; i>=1; i--) {
        int curr=0;
        for(int j=1 ; j<=n; j++)
            if(j >= i) cout<<++curr;
            else cout<<" ";
        
        while(curr>1) cout<<--curr;
        cout<<endl;
    }
}
void pat15(int n=5) {
    cout<<"----------------------"<<endl;
    for(int i=n; i>=1; i--) {
        int stars=(2*n)-(2*i);

        for(int j=1; j<=i; j++) cout<<j;
        for(;stars>0;stars--) cout<<"*";
        for(int j=i; j>=1; j--) cout<<j;
        // int curr=0; 
        // for(int j=1 ; j<=n; j++)
        //     if(j <= i) cout<<++curr;
        //     else cout<<"*";
        
        // for(int j=n ; j>=1; j--)
        //     if(j <= i) cout<<curr--;
        //     else cout<<"*";

        cout<<endl;
    }
}
int main() {
    pat1(4);
    pat2(4);
    pat3(4);
    pat4(4);
    pat5(4);
    pat6(4);
    pat7(4);
    pat8(4);
    pat9(4);
    pat10(4);
    pat11(4);
    pat12(4);
    pat13(4);
    pat14(4);
    pat15(5);
     return 0;
}