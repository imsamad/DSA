#include<iostream>
using namespace std;

void unsorted(int *A,int n,int sum){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(A[i]+A[j]==sum)
                cout<<A[i]<<" and "<<A[j]<<" => "<<sum<<endl;
}           
  
void unsortedWithHash(int *A,int n,int sum,int max){
    int H[max];
    for(int i=0;i<max;i++)H[i]=0;

    for(int i=0;i<n;i++){
        if(sum-A[i]>=0 && H[sum-A[i]])
            cout<<A[i]<<" and "<<sum-A[i]<<" "<<H[sum-A[i]]<<" => "<<sum<<endl;        
        H[A[i]]++;        
    }
    cout<<endl;
}
void sorted(int *A,int n,int sum){
    int i=0,j=n-1;
    while(i<j){
        if(A[i]+A[j]==sum){
            cout<<A[i]<<" + "<<A[j]<<" = "<<sum<<endl;
            i++;j--;
        }else if(A[i]+A[j]>sum)j--;
        else i++;
    }
}
int main(){
    int arr[]={6,3,8,10,16,7,5,3,4,0};
    int A[]={1,3,4,5,6,8,9,10,12,14};
    // fun(arr,10,10);   
    // unsortedWithHash(arr,10,10,16); 
    // sorted(A,10,10);
    // cout<<0x8<<endl;
    int x=14 | 0x8;
    if(12 & 0x8){
        cout<<"One "<<x<<endl;
    }else{
                cout<<"two"<<endl;

    }
    return 0;
}