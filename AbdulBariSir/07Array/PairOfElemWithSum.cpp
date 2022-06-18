#include<iostream>
using namespace std;

void findInUnsorted(int *arr,int len ,int sum) {
    for(int i=0; i<len; i++) {
        if( arr[i]==-1 ) continue;

        for(int j=i; j<len; j++) 
            if( arr[j]+arr[i] == sum ) {
                cout<<arr[i] << " + "<< arr[j]<<" found "<<endl;
                arr[j]=-1;
            }
    }
}

void findInSorted(int *arr,int len ,int sum) {
    int i=0,j=len-1;
    while(i<j) {
        int crtSum=arr[i]+arr[j];
       if(crtSum == sum) cout<<arr[i++] << " + "<< arr[j--]<<" found "<<endl;   
       else if(crtSum > sum) j--;
       else i++;
    }
}

void hashedTable (int *arr, int len, int maxElem,int sum) {
    int *bitSet= new int[maxElem+1];

    for(int i=0 ;i<len; i++) {
        if( bitSet[sum-arr[i]] ) {
            cout<<arr[i] << " + "<< sum-arr[i]<<" found "<<endl;
        }
        else bitSet[arr[i]]=1;
    }
}

int main() {
    int arr[]={6,3,8,10,16,7,5,2,9,14};
    // findInUnsorted(arr,10,10);
    int sortedArr[10]={1,3,4,5,6,8,9,10,12,14};
    // findInSorted(sortedArr,10,10);
    // hashedTable(arr,10,14,10);
    return 0;
}
