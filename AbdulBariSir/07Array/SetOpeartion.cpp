#include<iostream>
using namespace std;

void display(int *arr , int len) {
    for( int i=0; i < len; i++ ) 
        cout<<arr[i]<<", ";    
}

int * merge (int * arr1,int arr1Len,int *arr2,int arr2Len) {
    
    int *mergeArr=new int[arr1Len+arr2Len];
    
    int i=0, j=0, k=0;
    
    while( i < arr1Len && j < arr2Len )
        if(arr1[i]<arr2[j])
            mergeArr[k++]=arr1[i++];
            
        else if(arr1[i] > arr2[j])
            mergeArr[k++]=arr2[j++];

        else {
            mergeArr[k++]=arr1[i++];
            j++;
        }
    

    while(i < arr1Len) mergeArr[k++]=arr1[i++];    
    while(j < arr2Len) mergeArr[k++]=arr2[j++];    

    display(mergeArr,k);

    return mergeArr;
}

int * unionSet (int * arr1,int arr1Len,int *arr2,int arr2Len){
    int *unionArr=new int[arr1Len+arr2Len], i=0, j=0, k=0;

    while( i<arr1Len && j<arr2Len ){
        if(arr1[i] == arr2[j] ){
            unionArr[k++]=arr1[i++];
            j++;
        }

        else if( arr1[i] < arr2[j] ) unionArr[k++]=arr1[i++];

        else unionArr[k++]=arr2[j++];

    }

     display(unionArr,k);

    return unionArr;
}

int * intersectSet (int * arr1,int arr1Len,int *arr2,int arr2Len){
    int *unionArr=new int[arr1Len+arr2Len], i=0, j=0, k=0;

    while( i<arr1Len && j<arr2Len ){
        if(arr1[i] == arr2[j] ){
            unionArr[k++]=arr1[i++];
            j++;
        }
        else if( arr1[i] < arr2[j] ) i++;
        else if ( arr1[i]>arr2[j] ) j++;
    }

     display(unionArr,k);

    return unionArr;
}

 
int * diffSet (int * arr1,int arr1Len,int *arr2,int arr2Len){

    int * arr=new int[arr1Len+arr2Len], i=0, j=0, k=0;

    while( i<arr1Len && j<arr2Len ){

        if( arr1[i] == arr2[j] ) { i++; j++; }

        if( arr2[j] < arr1[i] ) j++;
        
        else arr[k++]=arr1[i++];   
    }

    while(i<arr1Len) arr[k++]=arr1[i++];

    display(arr,k);
    return arr;

}

int main(){
    int arr1Len=7, arr2Len=5;

    int arr1[arr1Len]={2,6,10,15,25,30,35}, arr2[arr2Len]={3,6,7,15,20};
    
    // int *mergeArr = new int[arr1Len+arr2Len];

    // merge(arr1, arr1Len, arr2, arr2Len);
    // unionSet(arr1, arr1Len, arr2, arr2Len);   
    // intersectSet(arr1,arr1Len,arr2,arr2Len);    
    diffSet(arr1,arr1Len,arr2,arr2Len);    
    return 0;
}
