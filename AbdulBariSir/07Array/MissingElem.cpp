#include<iostream>

using namespace std;

int findByDiff(int *arr, int arrLen, int findMultiple=1) {
    int diff=arr[0]-0;

   for(int i=1; i<arrLen; i++) {

        if( arr[i]-i == diff ) continue;
        
        
        if(!findMultiple)
            return 0;

        else 
            while (diff < arr[i]-i)
                cout<<i+diff++<<", ";        
   }
     
   return  diff != arr[0]? 0 : 1;

}

void findMissingBySum(int *arr, int arrLen, int num) {
    // Elements are first n natural no.
    int sum=0,totalSumMustBe=(num*(num+1))/2;

    while(arrLen) sum+=arr[--arrLen];

    if(totalSumMustBe != sum) 
        cout<<totalSumMustBe - sum << " is Missing " <<endl;
    else cout<< "Complete , no missing " <<endl;
}

void findByHashBitSet ( int *arr,int len,int maxElem){
    int *bitSet=new int[maxElem];

    for(int i=0; i<len; i++ ) bitSet[arr[i]]++;

    for(int i=1; i<maxElem; i++ ) {
        // cout<<bitSet[i]<<", ";
        if (bitSet[i]) continue;

        cout<<i<<", ";
    }


}

int main(){
    int arr[14]={1,2,3,4,5,6,7,9,10,11,12,13,14,25};
    // findMissingBySum(arr,14,15);
    findByDiff(arr,14,1);
    cout<<endl;
    findByHashBitSet(arr,14,25);
    return 0;
}