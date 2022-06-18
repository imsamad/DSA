#include<iostream>
using namespace std;

void duplicate(int *arr, int len,int countDup=0) {
    int lastDup=0;

    for(int i=0; i<len-1; i++){
        if( arr[i]!=arr[i+1] ) continue;
        
        if(!countDup) {
            if( arr[i] != lastDup ) cout<<arr[i]<<" is a duplicate element"<<endl;

            lastDup=arr[i];
            continue;
        }

        // Count duplicates    

        int j=i+2;

        while( arr[j]==arr[i] && j < len ) j++;

        cout<<arr[i]<< " occured "<<j-i<<" times"<<endl;

        i=j-1;
}
}



void bitSet( int *arr, int len, int maxElem) {
    int *bitSet=new int[maxElem+1];

    for( int i=0; i<len; i++ ) bitSet[arr[i]]++;

    for( int i=1; i<=maxElem; i++ ) {
        // cout<<i<<" => "<<bitSet[i]<<endl;
        if(bitSet[i] > 1) cout<<i<<" occured "<<bitSet[i]<<" times"<<endl;
    }
}

int main(){
    int arr[10]={6,8,8,10,12,15,15,15,15};

    // duplicate(arr,10,1);
    bitSet(arr,10,15);
    return 0;
}